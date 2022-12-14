/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:13:42 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/21 16:43:12 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# define LEN 25

typedef struct s_arg
{
	int		ac;
	char	**av;
}	t_arg;

typedef struct s_incr
{
	int	i;
	int	max;
}	t_incr;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_ext
{
	int	val;
	int	pos;
	int	dst;
}	t_ext;

typedef struct s_iter
{
	int	iter;
	int	iter_max;
	int	last_iter;
	int	len;
	int	chunk_size;
}	t_iter;

///////////////OPERATION/////////////
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
///////////////PARASING/////////////
t_list	*parsing(int ac, char **av);
/////////////////LIST////////////////
void	ps_addfront(t_list **list, t_list *new);
t_list	*ps_lstclear(t_list **list);
long	ps_atoi(const char *nptr);
int		ps_lstsize(t_list *lst);
void	ps_addback(t_list **list, t_list *new);
t_list	*ps_lstnew(int content);
t_list	*ps_lstlast(t_list *list);
/////////////////MOVE////////////////
void	push(t_list **a, t_list **b);
void	swap(t_list **list);
void	rotate(t_list **list);
void	rev_rotate(t_list **list);
///////////////OPERATION/////////////
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
/////////////////ALGO///////////////
t_ext	*get_closest_min(t_ext **min, int k, int len);
int		find_best_chunk_size(int save_ac, char **save_av);
///////SORT///////
void	sort(t_list **stack_a, t_list **stack_b, t_ext **min, t_iter iter);
void	sort_a(t_list **stack_a, t_list **stack_b, int size);
void	sort_b(t_list **stack_a, t_list **stack_b, int size);
////UTILS_ALGO////
int		push_all_min(t_list **stack_a, t_list **stack_b,
			t_ext **min, t_iter iter);
int		is_in_tab(t_ext **tab, int size, int content);
t_ext	find_max(t_list **stack_a);
t_ext	find_min(t_list **stack_a);
int		is_sorted(t_list **stack_a);
int		is_rev_sorted(t_list **stack);
void	push_all_of_b(t_list **stack_a, t_list **stack_b);
int		dst(int pos, int size);
int		find_next_min(t_list **stack_a, t_ext **min, t_iter iter);
void	set_min(t_ext **min, t_list *stack, int pos, int size);
void	update_min(t_ext **min, int content, t_incr incr, t_iter iter);
void	free_min(t_ext **min, int size);
///////////////PARASING/////////////
t_list	*parsing(int ac, char **av);
/////////////////UTILS////////////////
void	free_all(char **tab, char **save_av, int size, int ac);
int		free_err(char **tab, char **save_av, int size, int ac);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ps_addfront(t_list **list, t_list *new);
t_list	*ps_lstclear(t_list **list);
long	ps_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ps_lstsize(t_list *lst);
void	ps_addback(t_list **list, t_list *new);
t_list	*ps_lstnew(int content);
t_list	*ps_lstlast(t_list *list);

#endif
