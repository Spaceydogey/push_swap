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

static void	sort(t_list **stack_a, t_list **stack_b)
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
	if (is_sorted(stack_a) == 1)
		return ;
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

static void push_all_of_b(t_list **stack_a, t_list **stack_b)
{
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
/*	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);*/
}
