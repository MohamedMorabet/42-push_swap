/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__reverse_rotate__bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:49:20 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/09 00:41:23 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a__bonus(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		last = ft_lastnode__bonus(*a);
		tmp = last->prev;
		last->prev = NULL;
		last->next = *a;
		(*a)->prev = last;
		(*a) = last;
		tmp->next = NULL;
	}
}

void	reverse_rotate_b__bonus(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		last = ft_lastnode__bonus(*b);
		tmp = last->prev;
		last->prev = NULL;
		last->next = *b;
		(*b)->prev = last;
		(*b) = last;
		tmp->next = NULL;
	}
}

void	reverse_rotate__bonus(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		last = ft_lastnode__bonus(*b);
		tmp = last->prev;
		last->prev = NULL;
		last->next = *b;
		(*b)->prev = last;
		(*b) = last;
		tmp->next = NULL;
	}
}

void	reverse_rotate_ab__bonus(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate__bonus(a);
	reverse_rotate__bonus(b);
}
