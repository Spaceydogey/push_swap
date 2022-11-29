#include "push_swap.h"

int	argument_check(char *str)
{	
	int	i;
	
	i = -1;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (0);
	return (1);
}

int	check_dup(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return (0);
	tmp = *lst;
	while (tmp)
	{
		if (new->content == tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	parsing(int ac, char **av, t_list *stack_a)
{
	int		i;
	t_list	*new;

	i = 1;
	while (++i < ac)
	{
		if (argument_check(av[i]) == 0)
			return (0);
		new = ps_lstnew(ft_atoi(av[i]));
		if (!new)
			return (0);
		if (check_dup(&stack_a, new) == 0)
			return (0);
		ps_addback(&stack_a, new);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list *stack_a;
	if (ac < 2)
		return (1);
	if (argument_check(av[1]) == 0)
	{
		ft_putendl_fd("Error\n", 2);
		return (1);
	}
	stack_a = ps_lstnew(ft_atoi(av[1]));
	if (parsing(ac, av , stack_a) == 0)
	{
		//ps_lstclear(stack_a);
		ft_putendl_fd("Error\n", 2);
		return (1);
	}
	while (stack_a)
	{
		printf("%d\n",stack_a->content);
		stack_a = stack_a->next;
	}
}
