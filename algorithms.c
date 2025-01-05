/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:11:15 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 21:11:06 by mel-mora         ###   ########.fr       */
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
