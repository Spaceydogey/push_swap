/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:13:24 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/21 17:02:45 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **lst, int chunk_size)
{
	t_list	*stack_b;
	t_ext	**min;
	int		size;
	t_iter	iter;

	size = ps_lstsize(*lst);
	min = malloc(sizeof(t_ext) * size);
	if (!min)
		return ;
	stack_b = NULL;
	iter.chunk_size = chunk_size;
	iter.iter = 0;
	iter.iter_max = size / iter.chunk_size;
	if (size % iter.chunk_size > 0)
		iter.iter_max += 1;
	if (size < LEN)
		sort_a(lst, &stack_b, size);
	else
		sort(lst, &stack_b, min, iter);
	push_all_of_b(lst, &stack_b);
	ps_lstclear(lst);
	if (size > LEN)
		free_min(min, iter.chunk_size * iter.iter_max);
	free(min);
}

static int	ps_run(int save_ac, char **save_av)
{
	int		chunk_size;
	t_list	*stack_a;

	stack_a = parsing(save_ac, save_av);
	if (!stack_a)
		return (1);
	chunk_size = 1;
	if (ps_lstsize(stack_a) > LEN)
	{
		chunk_size = find_best_chunk_size(save_ac, save_av);
		if (chunk_size == -1)
			return (1);
	}
	push_swap(&stack_a, chunk_size);
	return (0);
}

int	main(int ac, char **av)
{
	char	**arg;
	t_arg	save;
	int		i;

	if (ac <= 1)
		return (1);
	save.av = av;
	save.ac = ac;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		i = 0;
		while (arg[i])
			i++;
		save.av = malloc(sizeof(char *) * (i + 1));
		if (!save.av)
			return (free_err(arg, NULL, i, ac));
		save.av[0] = av[0];
		save.ac = 0;
		while (arg[++save.ac - 1])
			save.av[save.ac] = arg[save.ac - 1];
	}
	if (ps_run(save.ac, save.av) == 1)
		return (free_err(arg, save.av, i, ac));
	free_all(arg, save.av, i, ac);
}
