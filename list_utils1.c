/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:55:25 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/14 19:01:21 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

t_list	*ps_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ps_addback(t_list **list, t_list *new)
{
	t_list	*old_last;

	if (!new || !list)
		return ;
	if (!*list)
		*list = new;
	else
	{
		old_last = ps_lstlast(*list);
		old_last->next = new;
	}
	return ;
}

void	ps_addfront(t_list **list, t_list *new)
{
	if (!new || !list)
		return ;
	new->next = *list;
	*list = new;
	return ;
}

t_list	*ps_lstclear(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	while (*list)
	{
		tmp = *list;
		*list = tmp->next;
		free(tmp);
	}
	return (NULL);
}
