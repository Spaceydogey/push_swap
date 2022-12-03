#include "push_swap.h"

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list	**stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
	
void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
