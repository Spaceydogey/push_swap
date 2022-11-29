#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list
{
		int				content;
		struct s_list	*next;
} t_list;

void	ps_addback(t_list **list, t_list *new);
t_list	*ps_lstnew(int content);
t_list	*ps_lstlast(t_list *list);
#endif
