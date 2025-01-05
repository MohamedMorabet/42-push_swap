/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:14:16 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 21:13:33 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len;
	t_stack_node	*lowest;

	len = len_stack(*a);
	while (len-- > 3)
		push_b(b, a);
	tiny_sort(a);
	while (*b)
	{
		intialize_stack(*a, *b);
		move_to_a(a, b);
	}
	set_position(*a);
	lowest = ft_lowest(*a);
	while (*a != lowest)
	{
		if (lowest->above_moy)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*b);
	if (cheapest->above_moy && cheapest->target_node->above_moy)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_moy && !cheapest->target_node->above_moy)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation_a(a, cheapest->target_node);
	finish_rotation_b(b, cheapest);
	push_a(a, b);
}

t_stack_node	*get_cheapest(t_stack_node *b)
{
	t_stack_node	*tmp_b;
	t_stack_node	*cheapest;

	tmp_b = b;
	while (tmp_b)
	{
		if (tmp_b->cheapest)
		{
			cheapest = tmp_b;
			break ;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rotate_ab(a, b);
	set_position(*a);
	set_position(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		reverse_rotate_ab(a, b);
	set_position(*a);
	set_position(*b);
}
