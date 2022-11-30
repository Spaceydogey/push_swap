#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list
{
		int				content;
		struct s_list	*next;
} t_list;

t_list  *ps_lstclear(t_list **list);
void 	swap(t_list **list);
void    push(t_list **a, t_list **b);
long	ps_atoi(const char *nptr);
int		ps_lstsize(t_list *lst);
void	ps_addback(t_list **list, t_list *new);
t_list	*ps_lstnew(int content);
t_list	*ps_lstlast(t_list *list);
#endif
