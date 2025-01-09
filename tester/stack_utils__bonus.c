/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils__bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:14:58 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/08 21:02:56 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_node(t_stack_node *node, int value)
{
	node->value = value;
	node->current_position = 0;
	node->push_price = 0;
	node->above_moy = false;
	node->cheapest = false;
	node->target_node = NULL;
	node->next = NULL;
	node->rank = 0;
}

void	add_node(t_stack_node **stack, int value)
{
	t_stack_node	*new;
	t_stack_node	*last;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		exit_error();
	initialize_node(new, value);
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

int	is_repeated(t_stack_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	len_stack(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
