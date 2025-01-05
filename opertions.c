/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opertions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:06:36 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/04 21:57:09 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_node	**a)
{
	t_stack_node	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		(*a)->next = tmp; 
		tmp->next = (*a)->next;
		(*a)->next->prev = tmp;
	}
}