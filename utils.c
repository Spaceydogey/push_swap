/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:43:33 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/21 16:45:09 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **tab, char **save_av, int size, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (tab[i] && i < size)
			free(tab[i++]);
		free(tab);
		free(save_av);
	}
}

int	free_err(char **tab, char **save_av, int size, int ac)
{
	ft_putendl_fd("Error\n", 2);
	free_all(tab, save_av, size, ac);
	return (1);
}

void	free_min(t_ext **min, int size)
{
	int	k;

	k = -1;
	while (++k < size)
		free(min[k]);
}
