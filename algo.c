#include "push_swap.h"

static void	dst(t_ext **ext, int size)
{
	t_ext *res;

	res = *ext;
	res->dst = res->pos - 1;
	if (res->dst > size - res->pos + 1)
		res->dst = size - res->pos + 1;
}
static int	is_in_tab(t_ext **tab, int size, int content)
{
	int	i;

	i = -1;

	while (++i < size)
	{
		if ((tab[i])->val == content)
			return (1);
	}
	return (0);
}

static t_ext	**find_min_20(t_list **stack_a, int len)
{
	int		i;
	int		k;
	int		size;
	t_list	*tmp;
	t_ext	**res;

	tmp = *stack_a;
	size = ps_lstsize(*stack_a);
//	printf(">>>min\n");
	res = malloc(sizeof(t_ext *) * len); 
	if (!tmp || !res)
		return (NULL);
	k = 0;
	while(k < len)
	{
		i = 0;

		(res[k]) = malloc(sizeof(t_ext)); 
		if (!res[k])
			return (NULL);
		(res[k])->pos = 1;
		(res[k])->val = tmp->content;
		dst(&res[k], size);
		while(tmp)
		{
			i++;
				while (tmp && is_in_tab(res, k, (res[k])->val) == 1)
				{	
					tmp = tmp->next;
					if (tmp)
					{
						(res[k])->val = tmp->content;
						(res[k])->pos = i;
						dst(&(res[k]), size);
					}
				}
		//	printf("is in tab %d\n", is_in_tab(res, k, tmp->content));
			if (tmp && (res[k])->val >= tmp->content && is_in_tab(res, k + 1, tmp->content) == 0)
			{
//				printf("wtf");
				(res[k])->val = tmp->content;
				(res[k])->pos = i;
				dst(&(res[k]), size);
				while (tmp && is_in_tab(res, k + 1, tmp->content) == 1)
					tmp = tmp->next;
			}
			else
				if (tmp)
					tmp = tmp->next;
		}
//		printf(">>>k %d min %d\n",k, (res[k])->val);
		tmp = *stack_a;
		k++;
	}
	return (res);
}

static int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;

	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void goto_closest(t_list **stack_a, int len)
{
	int	k;
	int	closest_min;
	int	closest_pos;
	int	size;
	t_ext	**min;

	k = 0;
	min = find_min_20(stack_a, len);
	if (!min)
		return ;
	size = ps_lstsize(*stack_a);
	closest_min = (min[k])->dst;
//	printf(">closest min %d\n", closest_min);
	closest_pos = (min[k])->pos;
	while (k < len)
	{
//		printf(">>dst %d\n", (min[k])->dst);
		if (min[k]->dst < closest_min)
		{
			closest_min = (min[k])->dst;
			closest_pos = (min[k])->pos;
		}
		k++;
	}
//	printf("> %d\n", closest_min);
	while (closest_min > 0)
	{
		if (closest_pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		closest_min--;
	}
	k = -1;
	while (++k < len)
		free(min[k]);
	free(min);
}

static void push_all_min(t_list **stack_a, t_list **stack_b)
{
	t_ext	**min;
	int		len;
	int		size;

	len = 20;
	size = ps_lstsize(*stack_a);
	if (len > size)
		len = size;
	while (len > 0)
	{
		goto_closest(stack_a,len);
		pb(stack_a, stack_b);
		len--;
	}
}

static t_ext	find_max(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_ext	res;

	i = 0;
	res.val = 0;
	res.pos = 0;
	tmp = *stack_a;
//	printf(">>>min\n");
	if (!tmp)
		return (res);
	res.val = tmp->content;
	while(tmp)
	{
		i++;
//		printf(">>>min\n");
		if (res.val <= tmp->content)
		{
			res.val = tmp->content;
			res.pos = i;
		}
		tmp = tmp->next;
	}
	return (res);
}

static t_ext	find_min(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_ext	res;

	i = 0;
	res.val = 0;
	res.pos = 0;
	tmp = *stack_a;
//	printf(">>>min\n");
	if (!tmp)
		return (res);
	res.val = tmp->content;
	while(tmp)
	{
		i++;
//		printf(">>>min\n");
		if (res.val >= tmp->content)
		{
			res.val = tmp->content;
			res.pos = i;
		}
		tmp = tmp->next;
	}
	return (res);
}
static void push_sorted(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		pb(stack_a, stack_b);
}
int	is_rev_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;

	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
static void	sort_b(t_list **stack_a, t_list **stack_b, int len)
{
	t_ext	min;
	t_ext	max;
	int		size;

//	printf(">>sort\n");
	min = find_min(stack_b);
	max = find_max(stack_b);
//	printf(">>%d %d\n", min.val, min.pos);
//	size = ps_lstsize(*stack_b);
	size = ps_lstsize(*stack_b);
//	printf("max = %d ; size = %d\n", max.pos, size);
//	printf("min = %d\n", min.pos);
	//printf(">>size : %d\n", size);
	
	if (size == 0)
		return ;
	if (is_rev_sorted(stack_b) == 1)
		return ;
//	if (size == 3 && max.pos == 1 && min.pos == 2)
//		rrb(stack_b);
	else if (max.pos == 1)
	{
		//ft_putnbr_fd(len, 1);
		len--;
		pa(stack_a, stack_b);
	}
	//else if (min.pos == 1)
	//	rb(stack_b);
//	else if (max.pos == 2 && min.pos == size)
//		sb(stack_b);
	else if (max.pos > size / 2)
		rrb(stack_b);
	else if (max.pos <= size / 2)
		rb(stack_b);
//	if (len == 0)
//		return ;
	sort_b(stack_a, stack_b, len);
}

static void	sort(t_list **stack_a, t_list **stack_b)
{
	t_ext	*min;
	int i = -1;
	while(++i < 26)
	{
		push_all_min(stack_a, stack_b);
		sort_b(stack_a, stack_b, 20);
		if (i != (5 - 1))
			push_sorted(stack_a, stack_b, 20);
	}
}

static void push_all_of_b(t_list **stack_a, t_list **stack_b)
{
//	sort_b(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}


void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
//	printf(">push_swap\n");
	stack_a = *lst;
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	push_all_of_b(&stack_a, &stack_b);
//	push_all_of_b(&stack_a, &stack_b);
/*	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);*/
}

