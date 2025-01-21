/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/21 13:22:49 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack_node **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	set_i_ac(&ac, &i, av);
	while (av[i])
	{
		if (!is_digit(av[i]))
		{
			free_stack(a);
			exit_error();
		}
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
		{
			free_stack(a);
			exit_error();
		}
		if (is_repeated(*a, ft_atoi(av[i])))
			exit_error();
		add_node(a, ft_atoi(av[i++]));
	}
	if (ac == 2)
		free_split(av);
}

void	set_i_ac(int *ac, int *i, char **av)
{
	if (*ac == 2)
	{
		*ac = ft_count_words(av);
		*i = 0;
	}
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
