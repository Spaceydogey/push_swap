#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

# define LEN 6
typedef struct s_list
{
	int				content;
	struct s_list	*next;
} t_list;

typedef struct	s_ext
{
	int				val;
	int				pos;
	int 			dst;
	struct s_ext	*next;
} t_ext;

/////////////////MOVE////////////////
void    push(t_list **a, t_list **b);
void 	swap(t_list **list);
void    rotate(t_list **list);
void    rev_rotate(t_list **list);
///////////////OPERATION/////////////
void    sa(t_list **stack_a);
void    sb(t_list   **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

//void    sort(t_list **stack_a, t_list **stack_b);
///////////////PARASING/////////////
t_list	*parsing(int ac, char **av);
/////////////////LIST////////////////
void    ps_addfront(t_list **list, t_list *new);
t_list  *ps_lstclear(t_list **list);
long	ps_atoi(const char *nptr);
int		ps_lstsize(t_list *lst);
void	ps_addback(t_list **list, t_list *new);
t_list	*ps_lstnew(int content);
t_list	*ps_lstlast(t_list *list);
////////////////////////////////////
void    print_lst(t_list **lst);
/////////////////MOVE////////////////
void    push(t_list **a, t_list **b);
void 	swap(t_list **list);
void    rotate(t_list **list);
void    rev_rotate(t_list **list);
///////////////OPERATION/////////////
void    sa(t_list **stack_a);
void    sb(t_list   **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
/////////////////ALGO///////////////
void	push_swap(t_list **lst);
////////////UTILS_ALGO//////////////
t_ext	find_max(t_list **stack_a);
t_ext	find_min(t_list **stack_a);
int		is_sorted(t_list **stack_a);
int		is_rev_sorted(t_list **stack);
void	push_all_of_b(t_list **stack_a, t_list **stack_b);
//void    sort(t_list **stack_a, t_list **stack_b);
///////////////PARASING/////////////
t_list	*parsing(int ac, char **av);
/////////////////LIST////////////////
void    ps_addfront(t_list **list, t_list *new);
t_list  *ps_lstclear(t_list **list);
long	ps_atoi(const char *nptr);
int		ps_lstsize(t_list *lst);
void	ps_addback(t_list **list, t_list *new);
t_list	*ps_lstnew(int content);
t_list	*ps_lstlast(t_list *list);
////////////////////////////////////
void    print_lst(t_list **lst);

#endif
