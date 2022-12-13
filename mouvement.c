/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:15:26 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/13 13:15:36 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	int	tmp;

	if (ps_lstsize(*list) < 2)
		return ;
	tmp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = tmp;
}

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp_new;
	int		tmp_content;
	t_list	*tmp_next;

	if (ps_lstsize(*src) < 1)
		return ;
	tmp_content = (*src)->content;
	tmp_next = (*src)->next;
	tmp_new = ps_lstnew((tmp_content));
	free(*src);
	*src = tmp_next;
	ps_addfront(dst, tmp_new);
}

void	rotate(t_list **list)
{
	int		save_first;
	t_list	*tmp;

	tmp = *list;
	save_first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = save_first;
}

void	rev_rotate(t_list **list)
{
	t_list	*tmp;
	int		save_content;
	int		old_content;

	tmp = *list;
	save_content = tmp->content;
	tmp->content = ps_lstlast(tmp)->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		old_content = tmp->content;
		tmp->content = save_content;
		save_content = old_content;
	}
}
