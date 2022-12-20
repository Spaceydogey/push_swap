/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_chunk.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:31:00 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 14:19:07 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BEST_CHUNK_H
# define FIND_BEST_CHUNK_H
# include "push_swap.h"
typedef struct s_stacks
{
	t_list **stack_a;
	t_list **stack_b;
}	t_stacks;

void	sa_chunk(t_list **stack_a, int *count);
void	sb_chunk(t_list	**stack_b, int *count);
void	ss_chunk(t_list **stack_a, t_list **stack_b, int *count);
void	pa_chunk(t_list **stack_a, t_list **stack_b, int *count);
void	pb_chunk(t_list **stack_a, t_list **stack_b, int *count);
void	ra_chunk(t_list **stack_a, int *count);
void	rb_chunk(t_list **stack_b, int *count);
void	rr_chunk(t_list **stack_a, t_list **stack_b, int *count);
void	rra_chunk(t_list **stack_a, int *count);
void	rrb_chunk(t_list **stack_b, int *count);
void	rrr_chunk(t_list **stack_a, t_list **stack_b, int *count);
void	test_sort_b(t_list **stack_a, t_list **stack_b, int size, int *count);
void	test_push_all_of_b(t_list **stack_a, t_list **stack_b, int *count);
void	test_move_a(t_list **stack_a, t_ext **min, t_iter iter, int *count);
void	test_push_all_min(t_stacks stack, t_ext **min, t_iter iter, int *count);

#endif