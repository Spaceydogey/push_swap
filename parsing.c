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
	while (tmp->next)
	{
		if (new->content == tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*parsing(int ac, char **av)
{
	int			i;
	t_list		*stack_a;
	long int	content;
	t_list		*new;

	i = 0;
	stack_a = NULL;
	while (++i < ac)
	{
		if (argument_check(av[i]) == 0)
			return (ps_lstclear(&stack_a));
		content = ps_atoi(av[i]);
		if (content > INT_MAX || content < INT_MIN)
			return (ps_lstclear(&stack_a));
		if (i == 1)
		{
			stack_a = ps_lstnew((int)content);
			if (!stack_a)
				return (ps_lstclear(&stack_a));
		}
		else
		{
			new = ps_lstnew((int)content);
			if (!new)
				return (ps_lstclear(&stack_a));
			ps_addback(&stack_a, new);
		}
		//printf(">%d\n",new->content);
		if (i > 1 && check_dup(&stack_a, new) == 0)
			return (ps_lstclear(&stack_a));
	}
	return (stack_a);
}

void	print_lst(t_list **lst)
{	
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
