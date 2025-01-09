/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:33:49 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/09 00:46:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// prototypes of all functions

void	set_rank(t_stack_node *stack)
{
	int				*tab;
	int				len;
	t_stack_node	*temp;
	int				rank;

	len = len_stack(stack);
	if (len == 0)
		return ;
	tab = create_table(stack);
	if (!tab)
		exit_error();
	sort_table(tab, len);
	temp = stack;
	while (temp)
	{
		rank = get_rank(tab, len, temp->value);
		if (rank == -1)
			exit_error();
		temp->rank = rank;
		temp = temp->next;
	}
	free(tab);
}

int	*create_table(t_stack_node *stack)
{
	int	*table;
	int	i;

	table = malloc(sizeof(int) * len_stack(stack));
	if (!table)
		exit_error();
	i = 0;
	while (stack)
	{
		table[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (table);
}

void	sort_table(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_rank(int *tab, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
