/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:30:47 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/09 00:47:30 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move the first chunk elements to be based on rank must be in 
// the range of the chunk
void	move_by_chunks(t_stack_node **a, t_stack_node **b, int chunk_size)
{
	int				chunk_min;
	int				chunk_max;
	t_stack_node	*tmp;

	chunk_min = 0;
	chunk_max = chunk_size;
	while (len_stack(*a) > 3)
	{
		tmp = *a;
		if (tmp->rank >= chunk_min && tmp->rank < chunk_max)
			push_b(b, a);
		else
			rotate_a(a);
		if (no_elements_in_chunk(*a, chunk_min, chunk_max))
		{
			chunk_min = chunk_max;
			chunk_max += chunk_size;
		}
	}
}

// Helper function to check if there are elements in the current chunk
int	no_elements_in_chunk(t_stack_node *a, int chunk_min, int chunk_max)
{
	while (a)
	{
		if (a->rank >= chunk_min && a->rank < chunk_max)
			return (0);
		a = a->next;
	}
	return (1);
}
