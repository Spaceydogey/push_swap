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

static void find_next_min(t_list **stack_a, t_ext **min, int iter)
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
	k = iter * LEN;
	i = 1;
	while(k < size - (iter * LEN))
	{
		(min[k]) = malloc(sizeof(t_ext)); 
		if (!min[k])
			return ;
		(min[k])->pos = i;
		(min[k])->val = tmp->content;
		dst(&min[k], size);
		j = iter * LEN;
		while(tmp && j < size - (iter * LEN))
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
			j++;
		}
		// ft_putnbr_fd(min[k]->val, 1);
		// write(1, "\n", 1);
		// ft_putnbr_fd(min[k]->dst, 1);
		// write(1, "\n", 1);
		tmp = *stack_a;
		k++;
		i = 1;
	}
}

static void goto_closest(t_list **stack_a, t_ext **min , int iter)
{
	int	k;
	int	closest_min;
	int	closest_pos;
	int	size;

	k = iter * LEN;
	find_next_min(stack_a, min, iter);
	size = ps_lstsize(*stack_a);
	closest_min = (min[k])->dst;
	closest_pos = (min[k])->pos;
	while (k < (LEN * iter) + LEN)
	{
		if ((min[k])->dst < closest_min)
		{
			closest_min = (min[k])->dst;
			closest_pos = (min[k])->pos;
		}
		k++;
	}
	while (closest_min > 0)
	{
		if (closest_pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		closest_min--;
	}
	k = -1;
}

static void push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, int iter)
{
	int		len;

    len = LEN;
	while (len > 0)
	{
		goto_closest(stack_a, min, iter);
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
	if (is_rev_sorted(stack_b) == 1)
		return ;
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
	int		len;
	int		size;

	if (is_sorted(stack_a))
			return ;
	size = ps_lstsize(*stack_a);
	if (size <= LEN || iter == iter_max)
		sort_a(stack_a, stack_b);
		// return ;
	else
	{
		push_all_min(stack_a, stack_b, min, iter);
		sort_b(stack_a, stack_b);
		push_all_of_b(stack_a, stack_b);
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
	print_lst(&stack_a);
}
