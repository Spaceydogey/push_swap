/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_chunk1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:15:59 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 10:43:21 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_chunk(t_list **stack_a, int *count)
{
	swap(stack_a);
	*count += 1;
}

void	sb_chunk(t_list	**stack_b, int *count)
{
	swap(stack_b);
	*count += 1;
}

void	ss_chunk(t_list **stack_a, t_list **stack_b, int *count)
{
	swap(stack_a);
	swap(stack_b);
	*count += 1;
}

void	pa_chunk(t_list **stack_a, t_list **stack_b, int *count)
{
	push(stack_a, stack_b);
	*count += 1;
}

void	pb_chunk(t_list **stack_a, t_list **stack_b, int *count)
{
	push(stack_b, stack_a);
	*count += 1;
}
