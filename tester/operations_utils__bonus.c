/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils__bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:28:00 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/21 13:32:33 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*ft_lastnode__bonus(t_stack_node *lst)
{
	t_stack_node	*lastel;

	lastel = lst;
	while (lastel && lastel->next != NULL)
	{
		lastel = lastel->next;
	}
	return (lastel);
}

//no place in manage stack bonus file
void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	set_i_ac(int *ac, int *i, char **av)
{
	if (*ac == 2)
	{
		*ac = ft_count_words(av);
		*i = 0;
	}
}
