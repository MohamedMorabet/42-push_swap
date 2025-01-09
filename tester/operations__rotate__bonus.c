/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__rotate__bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:25:07 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/08 20:57:31 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a__bonus(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		tmp = (*a);
		last = ft_lastnode__bonus(*a);
		(*a) = (*a)->next;
		(*a)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
}

void	rotate_b__bonus(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		tmp = (*b);
		last = ft_lastnode__bonus(*b);
		(*b) = (*b)->next;
		(*b)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
}

void	rotate__bonus(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		tmp = (*b);
		last = ft_lastnode__bonus(*b);
		(*b) = (*b)->next;
		(*b)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
}

void	rotate_ab__bonus(t_stack_node **a, t_stack_node **b)
{
	rotate__bonus(a);
	rotate__bonus(b);
}
