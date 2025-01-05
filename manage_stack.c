/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 10:11:04 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack_node **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		if (!is_digit(av[i]))
		{
			free_sack(a);
			exit_error();
		}
		if (ft_atoll(av[i]) > 2147483647 || ft_atoll(av[i]) < -2147483648)
		{
			free_sack(a);
			exit_error();
		}
		if (is_repeated(*a, ft_atoll(av[i])))
			exit_error();
		add_node(a, ft_atoll(av[i++]));
	}
	if (ac ==2)
		free_split(av);
}

void	free_sack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	print_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}