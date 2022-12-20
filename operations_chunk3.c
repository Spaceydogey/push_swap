/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_chunk3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:52:09 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 10:48:08 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_chunk(t_list **stack_a, int *count)
{
	rev_rotate(stack_a);
	*count += 1;
}

void	rrb_chunk(t_list **stack_b, int *count)
{
	rev_rotate(stack_b);
	*count += 1;
}

void	rrr_chunk(t_list **stack_a, t_list **stack_b, int *count)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	*count += 1;
}
