/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:11:15 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/05 16:44:23 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = ft_highest(*a);
	if ((*a) == highest)
		rotate_a(a);
	else if ((*a)->next == highest)
		reverse_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}

t_stack_node	*get_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	bring_to_top(t_stack_node **stack, t_stack_node *target,
			void (*rotate)(t_stack_node **),
			void (*reverse_rotate)(t_stack_node **))
{
	int				distance;
	int				len;
	t_stack_node	*temp;

	distance = 0;
	temp = *stack;
	len = len_stack(*stack);
	while (temp != target)
	{
		distance++;
		temp = temp->next;
	}
	if (distance <= len / 2)
	{
		while (*stack != target)
			rotate(stack);
	}
	else
	{
		while (*stack != target)
			reverse_rotate(stack);
	}
}

void	find_and_push_smallest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	smallest = get_smallest(*a);
	bring_to_top(a, smallest, rotate_a, reverse_rotate_a);
	push_b(b, a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	find_and_push_smallest(a, b);
	find_and_push_smallest(a, b);
	tiny_sort(a);
	push_a(a, b);
	push_a(a, b);
}
