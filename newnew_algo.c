#include "push_swap.h"

static int	is_in_tab(t_ext **tab, int size, int content)
{
	int	i;
	int	k;

	i = -1;
// 0 1 2 3 ... size
	while (++i <= size)
	{
		if ((tab[i])->val == content)
			return (1);
	}
	return (0);
}

static void	dst(t_ext **ext, int size)
{
	t_ext *res;

	res = *ext;
	res->dst = res->pos - 1;
	if (res->dst > size - res->pos + 1)
		res->dst = size - res->pos + 1;
}

static void find_next_min(t_list **stack_a, t_ext **min, int len, int iter)
{
	int		i;
	int		j;
	int		k;
	int		size;
	t_list	*tmp;

	tmp = *stack_a;
	size = ps_lstsize(*stack_a);
	if (!tmp)
		return ;
	k = 0;
	i = 1;
	while(k < size)
	{
		(min[k]) = malloc(sizeof(t_ext)); 
		if (!min[k])
			return ;
		(min[k])->pos = i;
		(min[k])->val = tmp->content;
		dst(&min[k], size);
	//	j = iter * LEN;
		while(tmp /*&& j < size - (iter * LEN)*/)
		{
			while (tmp && is_in_tab(min, k - 1, (min[k])->val) == 1)
			{	
				tmp = tmp->next;
				i++;
				if (tmp)
				{
					(min[k])->val = tmp->content;
					(min[k])->pos = i;
					dst(&(min[k]), size);
				}
			}//skip doubles
			if (tmp && (min[k])->val >= tmp->content && is_in_tab(min, k - 1, tmp->content) == 0)
			{
				(min[k])->val = tmp->content;
				(min[k])->pos = i;
				dst(&(min[k]), size);
				
				while (tmp && is_in_tab(min, k, tmp->content) == 1)
				{	
					tmp = tmp->next;
					i++;
				}
			}//change min to the new min value
			else
			{
				if (tmp)
				{
					tmp = tmp->next;
					i++;
				}
			}
		//	j++;
		}
	// 	ft_putnbr_fd(min[k]->val, 1);
	// write(1, "\n", 1);
	// //ft_putnbr_fd(min[k]->dst, 1);
	// write(1, "\n", 1);
		tmp = *stack_a;
		k++;
		i = 1;
	}
}

static void goto_closest(t_list **stack_a, t_ext **min, int len, int iter)
{
	int	k;
	int	closest_min;
	int	closest_dst;
	int	closest_pos;
	int	size;
	int	last_iter;

	last_iter = iter - 1;
	if (last_iter <= 0)
		last_iter = 0;
	k = iter * LEN;
	
	find_next_min(stack_a, min, len, iter);
	size = ps_lstsize(*stack_a);
	closest_min = (min[k])->val;
	closest_dst = (min[k])->dst;
	closest_pos = (min[k])->pos;
	while (k < iter * LEN + len)
	{
		if ((min[k])->dst < closest_dst /*&& is_in_tab(&min[(last_iter) * LEN], iter * LEN, min[k]->val) == 0*/)
		{
			closest_min = (min[k])->val;
			closest_dst = (min[k])->dst;
			closest_pos = (min[k])->pos;
		}

		// ft_putnbr_fd(k , 1);
		// write(1, "\n", 1);
		k++;
	}
	// ft_putstr_fd("closest min and pos :", 1);
	// ft_putnbr_fd(closest_min, 1);
	// write(1, "\t", 1);
	// ft_putnbr_fd(closest_pos, 1);
	// write(1, "\n", 1);
	while (closest_dst > 0)
	{
		if (closest_pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		closest_dst--;
	}
	k = -1;
}

static void push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, int iter)
{
	int		len;
	int 	last_iter;

    len = LEN;

	//find_next_min(stack_a, min, len, iter);
	while (len > 0)
	{
		goto_closest(stack_a, min, len, iter);
	
		pb(stack_a, stack_b);
		len--;
	}
}

static void	sort_b(t_list **stack_a, t_list **stack_b)
{
	t_ext	max;
	int		size;

	max = find_max(stack_b);
	size = ps_lstsize(*stack_b);
	
	if (size == 0)
		return ;	
	//if (is_rev_sorted(stack_b) == 1)
	//	return ;
	else if (max.pos == 1)
		pa(stack_a, stack_b);
	else if (max.pos > size / 2)
		rrb(stack_b);
	else if (max.pos <= size / 2)
		rb(stack_b);
	sort_b(stack_a, stack_b);
}

static void	sort_a(t_list **stack_a, t_list **stack_b)
{
	t_ext	min;
	t_ext	max;
	int		size;

	min = find_min(stack_a);
	max = find_max(stack_a);
	size = ps_lstsize(*stack_a);
	if (size == 0)
		return ;
	if (is_sorted(stack_a) == 1)
		return ;
	if (size == 3 && min.pos == 1 && max.pos == 2)
		rra(stack_a);
	else if (min.pos == 1)
		pb(stack_a, stack_b);
	else if (min.pos == 2 && max.pos == size)
		sa(stack_a);
	else if (min.pos > size / 2)
		rra(stack_a);
	else if (min.pos <= size / 2)
		ra(stack_a);
	sort_a(stack_a, stack_b);
}

static void	sort(t_list **stack_a, t_list **stack_b, t_ext **min, int iter, int iter_max)
{
	int		i;
	int		size;
	int		last_iter;

	last_iter = iter - 1;
	if (last_iter <= 0)
		last_iter = 0;
	if (is_sorted(stack_a))
			return ;
	size = ps_lstsize(*stack_a);
	if (size <= LEN || iter == iter_max)
	{

		// while (min[last_iter + LEN - 1]->pos != ps_lstsize(*stack_a))
		// {
		// 	ra(stack_a);
		// 	min[last_iter + LEN - 1]->pos += 1;
		// }
		sort_a(stack_a, stack_b);
	}
	else
	{
		push_all_min(stack_a, stack_b, min, iter);
		sort_b(stack_a, stack_b);
		while (min[last_iter + LEN - 1]->pos != ps_lstsize(*stack_a))
		{
			ra(stack_a);
			min[last_iter + LEN - 1]->pos += 1;
		}	
		i = 0;
		// while (i < LEN)
		// {
		// 	write(1, "oi\n", 3);
		// 	ra(stack_a);
		// 	i++;
		// }
		// //push_all_of_b(stack_a, stack_b);
		iter++;
	}
	sort(stack_a, stack_b, min, iter, iter_max);
}

void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ext	**min;
	int iter_max;
	int	iter;
 
	stack_a = *lst;
	min = malloc(sizeof(t_ext) * ps_lstsize(stack_a));
	stack_b = NULL;
	iter = 0;
	iter_max = ps_lstsize(stack_a) / LEN;
	sort(&stack_a, &stack_b, min, iter, iter_max);
	push_all_of_b(&stack_a, &stack_b);
	// print_lst(&stack_a);
	// while (++k < len)
	// 	free(min[k]);
	// free(min);
}
