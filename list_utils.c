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
	t_list	*res;

	if (!list)
		return (NULL);
	res = list;
	while (res->next)
		res = res->next;
	return (res);	
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
