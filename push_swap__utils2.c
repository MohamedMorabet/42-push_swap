/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:22:29 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 21:12:47 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lowest(t_stack_node *lst)
{
	t_stack_node	*tmp;
	t_stack_node	*lowest;

	tmp = lst;
	lowest = lst;
	while (tmp)
	{
		if (tmp->value < lowest->value)
			lowest = tmp;
		tmp = tmp->next;
	}
	return (lowest);
}

void	finish_rotation_a(t_stack_node **a, t_stack_node *target)
{
	while (*a != target)
	{
		if (target->above_moy)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	finish_rotation_b(t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->above_moy)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
}

t_stack_node	*ft_highest(t_stack_node *lst)
{
	t_stack_node	*tmp;
	t_stack_node	*highest;

	tmp = lst;
	highest = lst;
	while (tmp)
	{
		if (tmp->value > highest->value)
			highest = tmp;
		tmp = tmp->next;
	}
	return (highest);
}
