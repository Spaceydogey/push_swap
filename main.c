#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	
	//TODO add support to input string containing multiple element of the stack 
	if (ac < 2)
		return (1);
	stack_a = parsing(ac, av);
	if (!stack_a)
	{
		ft_putendl_fd("Error\n", 2);
		return (1);
	}
	push_swap(&stack_a);
//	print_lst(&stack_a);
//	ft_putendl_fd("_\na", 1);
	ps_lstclear(&stack_a);
	return (0);

/*	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);

	ft_putendl_fd("------\nrotate\n------", 1);
	ra(&stack_a);
//	rb(&stack_b);

	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);

	rra(&stack_a);
//	rrb(&stack_b);

	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);

	sa(&stack_a);

	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);

	pb(&stack_a, &stack_b);

	print_lst(&stack_a);
	ft_putendl_fd("_\na", 1);
	print_lst(&stack_b);
	ft_putendl_fd("_\nb", 1);

	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);*/
}
