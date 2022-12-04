#include "push_swap.h"

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

static void	sort_b(t_list **stack_b)
{
	t_ext	max;
	int		size;

	max = find_max(stack_b);
	size = ps_lstsize(*stack_b);
	if (max.pos > size / 2)
	{
		while (max.pos != 1)
		{
			rrb(stack_b);
			max = find_max(stack_b);
		}
	}
	else
	{
		while (max.pos != 1)
		{
			rb(stack_b);
			max = find_max(stack_b);
		}
	}
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

static void	sort_min(t_list **stack_a, t_list **stack_b)
{
	t_ext	min;
	t_ext	max;
	int		size;

//	printf(">>sort\n");
	min = find_min(stack_a);
	max = find_max(stack_a);
//	printf(">>%d %d\n", min.val, min.pos);
	size = ps_lstsize(*stack_a);
//	printf("max = %d ; size = %d\n", max.pos, size);
//	printf("min = %d\n", min.pos);
	//printf(">>size : %d\n", size);
	if (size == 0)
		return ;
//	if (is_sorted(stack_a) == 1)
//		return ;
	if (size == 3 && min.pos == 1 && max.pos == 2)
		rra(stack_a);
	else if (min.pos == 1)
		pb(stack_a, stack_b);
//	else if (max.pos == 1)
//		ra(stack_a);
	else if (min.pos == 2 && max.pos == size)
		sa(stack_a);
	else if (min.pos > size / 2)
		rra(stack_a);
	else if (min.pos <= size / 2)
		ra(stack_a);
	sort(stack_a, stack_b);
}

static void	sort_max(t_list **stack_a, t_list **stack_b)
{
	t_ext	min;
	t_ext	max;
	int		size;

//	printf(">>sort\n");
	min = find_min(stack_a);
	max = find_max(stack_a);
//	printf(">>%d %d\n", min.val, min.pos);
	size = ps_lstsize(*stack_a);
//	printf("max = %d ; size = %d\n", max.pos, size);
//	printf("min = %d\n", min.pos);
	//printf(">>size : %d\n", size);

	if (size == 0)
		return ;
//	if (is_sorted(stack_a) == 1)
//		return ;
	if (size == 3 && min.pos == 1 && max.pos == 2)
		rra(stack_a);
	else if (max.pos == 1)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if (max.pos == 2 && min.pos == size)
		sa(stack_a);
	else if (max.pos > size / 2)
		rra(stack_a);
	else if (max.pos <= size / 2)
		ra(stack_a);
	sort(stack_a, stack_b);
}

static t_ext	dst(t_ext ext, int size)
{
	t_ext res;

	res = ext;
	res.dst = ext.pos - 1;
	res.mvt = "up";
	if (res.dst > size - ext.pos + 1)
	{
		res.dst = size - ext.pos + 1;
		res.mvt = "down";
	}
	return (res);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_ext	min;
	t_ext	max;
	int		size;
	int		dst_min;

	min = find_min(stack_a);
	max = find_max(stack_a);
	size = ps_lstsize(*stack_a);
	min = dst(min, size);
	max = dst(max, size);
	if (size == 0)
		return ;
//	if (is_sorted(stack_a) == 1)
//		return ;
	if (max.dst >= min.dst)
		sort_min(stack_a, stack_b);
	else
		sort_max(stack_a, stack_b);
}

static void push_all_of_b(t_list **stack_a, t_list **stack_b)
{
	sort_b(stack_b);
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
	sort_min(&stack_a, &stack_b);
	push_all_of_b(&stack_a, &stack_b);
/*	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);*/
}
