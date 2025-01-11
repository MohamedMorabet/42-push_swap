/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__swap_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:06:36 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/10 15:55:48 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_node	**a)
{
	t_stack_node	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		if ((*a)->next)
			(*a)->next->prev = tmp;
		(*a)->prev = NULL;
		(*a)->next = tmp;
		tmp->prev = *a;
		ft_putstr("sa\n");
	}
}

void	swap_b(t_stack_node	**b)
{
	t_stack_node	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		if ((*b)->next)
			(*b)->next->prev = tmp;
		(*b)->prev = NULL;
		(*b)->next = tmp;
		tmp->prev = *b;
		ft_putstr("sb\n");
	}
}

void	swap_ab(t_stack_node **a, t_stack_node **b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr("ss\n");
}

void	push_b(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*tmp;

	if (!a || !(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	(*b)->prev = NULL;
	ft_putstr("pb\n");
}

void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	(*a)->prev = NULL;
	ft_putstr("pa\n");
}
