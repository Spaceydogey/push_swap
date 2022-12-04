#include "push_swap.h"

static void	dst(t_ext **ext, int size)
{
	t_ext *res;

	res = *ext;
	res->dst = res->pos - 1;
	//printf(">> %d\n", res.dst);
	res->mvt = "up";
	if (res->dst > size - res->pos + 1)
	{
		res->dst = size - res->pos + 1;
	//	printf(">>> %d\n", res.dst);
		res->mvt = "down";
	}
}

static t_ext	**find_min_20(t_list **stack_a, int len)
{
	int		i;
	int		k;
	int		size;
	t_list	*tmp;
	t_ext	**res;
	//TODO MIN EN LIST CHAINER

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

		res[k] = malloc(sizeof(t_ext) * len); 
		if (!res[k])
			return (NULL);
		(res[k])->pos = 1;
		(res[k])->val = tmp->content;
		dst(&res[k], size);
		while(tmp)
		{
			i++;
//		printf(">>>min\n");
			if ((res[k])->val >= tmp->content)
			{
				(res[k])->val = tmp->content;
				(res[k])->pos = i;
				dst(&res[k], size);
			}
			tmp = tmp->next;
		}
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

static void goto_closest(t_list **stack_a, t_ext **min, int len)
{
	int	k;
	int	closest_min;
	int	closest_pos;
	int	size;

	k = 0;
	size = ps_lstsize(*stack_a);
	closest_min = (min[k])->dst;
	printf(">closest min %d\n", closest_min);
	closest_pos = (min[k])->pos;
	while (k < len)
	{
		printf(">>dst %d\n", (min[k])->dst);
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
}

static void push_all_min(t_list **stack_a, t_list **stack_b)
{
	t_ext	**min;
	int		len;

	len = 8;
	while (len > 0)
	{
		min = find_min_20(stack_a, len);
		if (!min)
	   		return ;
		goto_closest(stack_a, min, len);
		free(min);
		pb(stack_a, stack_b);
		len--;
	}
}

static void	sort(t_list **stack_a, t_list **stack_b)
{
	t_ext	*min;
	while(*stack_a)
		push_all_min(stack_a, stack_b);
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
//	push_all_of_b(&stack_a, &stack_b);
/*	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);*/
}

