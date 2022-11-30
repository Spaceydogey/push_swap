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

	if (ps_lstsize(*src) < 2)
		return ;
	tmp_src = *src;
	tmp_new = ps_lstnew(tmp_src->content);
	*src = (*src)->next;
	free(tmp_src);
	ps_addback(dst, tmp_new);
}
