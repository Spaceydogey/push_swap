/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_chunk2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:51:17 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 10:46:30 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_chunk(t_list **stack_a, int *count)
{
	rotate(stack_a);
	*count += 1;
}

void	rb_chunk(t_list **stack_b, int *count)
{
	rotate(stack_b);
	*count += 1;
}

void	rr_chunk(t_list **stack_a, t_list **stack_b, int *count)
{
	rotate(stack_a);
	rotate(stack_b);
	*count += 1;
}
