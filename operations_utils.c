/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:28:00 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 13:25:35 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lastnode(t_stack_node *lst)
{
	t_stack_node	*lastel;

	lastel = lst;
	while (lastel && lastel->next != NULL)
	{
		lastel = lastel->next;
	}
	return (lastel);
}
