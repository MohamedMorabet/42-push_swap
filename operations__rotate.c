/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:25:07 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 13:11:47 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		tmp = (*a);
		last = ft_lastnode(*a);
		(*a) = (*a)->next;
		(*a)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
	printf("ra\n");
}

void	rotate_b(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		tmp = (*b);
		last = ft_lastnode(*b);
		(*b) = (*b)->next;
		(*b)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
	printf("rb\n");
}

void	rotate_ab(t_stack_node **a, t_stack_node **b)
{
	rotate_a(a);
	rotate_b(b);
	printf("rr\n");
}
