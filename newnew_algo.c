#include "push_swap.h"

static int	is_in_tab(t_ext **tab, int size, int content)
{
	int	i;
	int	k;

	i = -1;
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

static int find_next_min(t_list **stack_a, t_ext **min, int iter)
{
	int		i;
	int		j;
	int		k;
	int		size;
	t_list	*tmp;

	tmp = *stack_a;
	size = ps_lstsize(*stack_a);
	// if ((iter * LEN) + len >= size)
	// 	len = size - (iter * LEN);
	if (!tmp)
		return (-1);
	k = 0;
	i = 1;
	while(k < size)
	{
		(min[k]) = malloc(sizeof(t_ext)); 
		if (!min[k])
			return (-1);
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
	return (size);
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
	size = find_next_min(stack_a, min, iter);
	if (size == -1)
		return ;
	if ((iter * LEN) + len >= size)
		len = size - (iter * LEN);
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
	while (++k < size)
		free(min[k]);
}

static int push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, int iter)
{
	int		len;
	int 	last_iter;
	int		size;
	int		res;

    len = LEN;
	size = ps_lstsize(*stack_a);
	if ((iter * LEN) + len >= size)
		len = size - (iter * LEN);
	res = len;
	while (len > 0)
	{
		goto_closest(stack_a, min, len, iter);
		pb(stack_a, stack_b);
		len--;
	}
	return (size - res);
}

static void	sort_b(t_list **stack_a, t_list **stack_b, int size)
{
	t_ext	max;
	t_ext	min;
	int		check_ra;


	// min.dst = min.pos + 1;
	// max.dst = max.pos;
	while (size > 0)
	{
		check_ra = 0;
		max = find_max(stack_b);
		min = find_min(stack_b);
		min.dst = min.pos;
		if (min.dst > (size / 2))
			min.dst = size - min.pos;	
		max.dst = max.pos;
		if (max.dst > (size / 2))
			max.dst = size - max.pos;
		if (is_rev_sorted(stack_b) == 1)
		{
			push_all_of_b(stack_a, stack_b);
			return ;
		}
		else if (min.pos == 1)
		{
			pa(stack_a, stack_b);
			check_ra = 1;
			size -= 1;
		}
		else if (max.pos == 1)
		{
			pa(stack_a, stack_b);
			size -= 1;
		}
		// else if (max.pos > (size / 2) + (size % 2))
		// 	rrb(stack_b);
		// else if (max.pos <= (size / 2) + (size % 2))
		// {
		// 	if (check_ra == 1)
		// 	{
		// 		rr(stack_a, stack_b);
		// 		check_ra = 0;
		// 	}
		// 	else
		// 		rb(stack_b);
		// }
		else if (max.dst < min.dst + 1)
		{
			if (max.pos > (size / 2) + (size % 2))
				rrb(stack_b);
			else if (max.pos <= (size / 2) + (size % 2))
			{
				if (check_ra == 1)
				{
					rr(stack_a, stack_b);
					check_ra = 0;
				}
				else
					rb(stack_b);
			}
		}
		else if (max.dst >= min.dst + 1)
		{
			if (min.pos > (size / 2) + (size % 2))
				rrb(stack_b);
			else if (min.pos <= (size / 2) + (size % 2))
			{
				if (check_ra == 1)
				{
					rr(stack_a, stack_b);
					check_ra = 0;
				}
				else
					rb(stack_b);
			}
		}
		if (check_ra == 1)
			ra(stack_a);
	}
	// sort_b(stack_a, stack_b, size);
}

static void	sort_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_ext	min;
	t_ext	max;
	// int		size;

	min = find_min(stack_a);
	max = find_max(stack_a);
	// size = ps_lstsize(*stack_a);
	if (size == 0)
		return ;
	if (is_sorted(stack_a) == 1)
		return ;
	if (size == 3 && min.pos == 1 && max.pos == 2)
		rra(stack_a);
	else if (min.pos == 1)
	{
		size--;
		pb(stack_a, stack_b);
	}
	else if (min.pos == 2 && max.pos == size)
		sa(stack_a);
	else if (min.pos > (size / 2) + (size % 2))
		rra(stack_a);
	else if (min.pos <= (size / 2) + (size % 2))
		ra(stack_a);
	sort_a(stack_a, stack_b, size);
}

static void	sort(t_list **stack_a, t_list **stack_b, t_ext **min, int iter, int iter_max)
{
	int		k;
	int		size;
	int		last_iter;


	last_iter = iter - 1;
	if (last_iter < 0)
		last_iter = 0;
	if (is_sorted(stack_a))
		return ;
	if (iter > iter_max)
	{
		sort_a(stack_a, stack_b, ps_lstsize(*stack_a));
		return ;
	}
	else
	{
			
		push_all_min(stack_a, stack_b, min, iter);
		size = find_next_min(stack_a, min, iter);
		while (iter > 0 && iter < iter_max && min[(last_iter * LEN) + LEN - 1]->pos != size)
		{
			if (min[(last_iter * LEN) + LEN - 1]->pos > size / 2)
			{
				rra(stack_a);
				min[(last_iter * LEN) + LEN - 1]->pos += 1;
			}
			else
			{
				ra(stack_a);
				min[(last_iter * LEN) + LEN - 1]->pos -= 1;
				if (min[(last_iter * LEN) + LEN - 1]->pos == -1)
					min[(last_iter * LEN) + LEN - 1]->pos = size;
			}
			// ft_putnbr_fd(ps_lstsize(*stack_a), 1);
			// write(1,"\t",1);
			// ft_putnbr_fd(min[(last_iter * LEN) + LEN - 1]->val, 1);
			// write(1,"\t",1);
			// ft_putnbr_fd(min[(last_iter * LEN) + LEN - 1]->pos, 1);
			// write(1,"\n",1);
		}
		k = -1;
		while (++k < size)
			free(min[k]);
		sort_b(stack_a, stack_b, ps_lstsize(*stack_b));
		iter++;
	}
	sort(stack_a, stack_b, min, iter, iter_max);
}

void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ext	**min;
	int		size;

	stack_a = *lst;
	size = ps_lstsize(stack_a);
	min = malloc(sizeof(t_ext) * size);
	stack_b = NULL;
	if (size < LEN)
		sort_a(&stack_a, &stack_b, size);
	else
		sort(&stack_a, &stack_b, min, 0, size / LEN);
	push_all_of_b(&stack_a, &stack_b);
	ps_lstclear(&stack_a);
	free(min);
}
