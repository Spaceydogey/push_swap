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
	return (0);
}
