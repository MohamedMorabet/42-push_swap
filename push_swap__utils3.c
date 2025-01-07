/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:08:27 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/07 20:12:25 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_price_above_moy(t_stack_node *b, int len_a)
{
	if (b->target_node->above_moy)
		b->push_price = max_between(b->current_position - 1,
				b->target_node->current_position - 1);
	else
		b->push_price = b->current_position + len_a
			- b->target_node->current_position;
}

void	calculate_price_below_moy(t_stack_node *b, int len_a, int len_b)
{
	if (!b->target_node->above_moy)
		b->push_price = max_between(len_b - b->current_position + 1,
				len_a - b->target_node->current_position + 1);
	else
		b->push_price = len_b - b->current_position
			+ b->target_node->current_position;
}
