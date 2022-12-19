/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:13:24 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/19 11:44:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_min(t_ext **min, int size)
{
	int	k;

	k = -1;
	while (++k < size)
		free(min[k]);
	free(min);
}

void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ext	**min;
	int		size;
	t_iter	iter;

	stack_a = *lst;
	size = ps_lstsize(stack_a);
	min = malloc(sizeof(t_ext) * size);
	if (!min)
		return ;
	stack_b = NULL;
	iter.iter = 0;
	iter.iter_max = size / LEN;
	if (size % LEN > 0)
		iter.iter_max += 1;
	if (size < LEN)
		sort_a(&stack_a, &stack_b, size);
	else
		sort(&stack_a, &stack_b, min, iter);
	push_all_of_b(&stack_a, &stack_b);
	ps_lstclear(&stack_a);
	free_min(min, LEN * iter.iter_max);
}
static void	free_all(char **tab, char **save_av, int size, int ac)
{
	int	i;
	
	i = 0;
	if (ac == 2)
	{
		while (tab[i] && i < size)
		{
			free(tab[i++]);
		}
		free(tab);
		free(save_av);
	}
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	char 	**arg;
	char	**save_av;
	int		save_ac;
	int		i;
	
	if (ac < 1)
		return (1);
	save_av = av;
	save_ac = ac;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		i = 0;
		while (arg[i])
			i++;
		save_av = malloc(sizeof(char *) * (i + 1));
		if (!save_av)
		{
			ft_putendl_fd("Error\n", 2);
			free_all(arg, NULL, i, ac);
			return (1);
		}
		save_av[0] = av[0];
		save_ac = 1; 
		while (arg[save_ac - 1])
		{
			save_av[save_ac] = arg[save_ac - 1];
			save_ac++;
		}
	}
	stack_a = parsing(save_ac, save_av);
	if (!stack_a)
	{
		ft_putendl_fd("Error\n", 2);
		free_all(arg, save_av, i, ac);
		return (1);
	}
	free_all(arg, save_av, i, ac);
	push_swap(&stack_a);
	return (0);
}
