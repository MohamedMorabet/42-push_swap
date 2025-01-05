/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:55:56 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 21:11:49 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	intialize_stack(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(a, b);
}

void	set_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = len_stack(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i >= center)
			stack->above_moy = true;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*target_node;
	long long		perfect_match;

	while (b)
	{
		perfect_match = LONG_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->value > b->value && tmp_a->value < perfect_match)
			{
				perfect_match = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (perfect_match == LONG_MAX)
			b->target_node = ft_lowest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_moy))
			b->push_price = len_b - b->current_position;
		if (b->target_node->above_moy)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->push_price < cheapest->push_price)
			cheapest = b;
		b = b->next;
	}
	cheapest->cheapest = true;
}
