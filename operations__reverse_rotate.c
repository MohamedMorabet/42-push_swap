/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:49:20 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 13:11:36 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		last = ft_lastnode(*a);
		tmp = last->prev;
		last->prev = NULL;
		last->next = *a;
		(*a)->prev = last;
		(*a) = last;
		tmp->next = NULL;
	}
	printf("rra\n");
}

void	reverse_rotate_b(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		last = ft_lastnode(*b);
		tmp = last->prev;
		last->prev = NULL;
		last->next = *b;
		(*b)->prev = last;
		(*b) = last;
		tmp->next = NULL;
	}
	printf("rrb\n");
}

void	reverse_rotate_ab(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	printf("rrr\n");
}