#include "push_swap.h"

t_ext	find_max(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_ext	res;

	i = 0;
	tmp = *stack_a;
	if (!tmp)
		return (res);
	res.val = tmp->content;
	res.pos = 1;
	while(tmp)
	{
		i++;
		if (res.val <= tmp->content)
		{
			res.val = tmp->content;
			res.pos = i;
		}
		tmp = tmp->next;
	}
	return (res);
}

t_ext	find_min(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_ext	res;

	i = 0;
	tmp = *stack_a;
	if (!tmp)
		return (res);
	res.val = tmp->content;
	res.pos = 1;
	while(tmp)
	{
		i++;
		if (res.val >= tmp->content)
		{
			res.val = tmp->content;
			res.pos = i;
		}
		tmp = tmp->next;
	}
	return (res);
}

int	is_sorted(t_list **stack_a)
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

void push_all_of_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
}
