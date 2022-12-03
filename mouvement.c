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
	t_list	*tmp_src;

	if (ps_lstsize(*src) < 1)
		return ;
	tmp_src = *src;
	tmp_new = ps_lstnew(tmp_src->content);
	*src = (*src)->next;
//	free(tmp_src);
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
