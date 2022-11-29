#include "push_swap.h"

int	argument_check(char *str)
{	int	i;
	
	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (ft_isnum(str[i]) == 0)
			return (0);
	return (1);
}
int	parsing(int ac, char **av)
{
	int	i;
	t_stack *stack_a;

	i = 0;
	stack_a = stack_init(ac);
	while (++i < ac)
	{
		if (argument_check(av[i]) == 0)
				return (0);
		stack_a->content = ft_atoi(av[i]);
		stack_a = stack_a->next;
	}
}
