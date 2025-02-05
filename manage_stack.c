/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/05 15:42:05 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_with_space(char *joined, char *arg)
{
	char	*temp;

	temp = joined;
	joined = ft_strjoin(temp, arg);
	free(temp);
	if (!joined)
		exit_error();
	return (joined);
}

char	**join_and_split_args(char **av)
{
	char	*joined;
	char	**split;
	int		i;

	i = 1;
	joined = ft_strdup("");
	if (!joined)
		exit_error();
	while (av[i])
	{
		joined = join_with_space(joined, av[i]);
		if (av[i + 1])
			joined = join_with_space(joined, " ");
		i++;
	}
	split = ft_split(joined, ' ');
	free(joined);
	if (!split)
		exit_error();
	return (split);
}

void	create_stack(t_stack_node **a, char **av)
{
	char	**split;
	int		i;
	int		error_flag;
	int		value;

	split = join_and_split_args(av);
	if (!split)
		exit_error();
	i = 0;
	while (split[i])
	{
		if (!is_digit(split[i]))
			free_and_exit(split, a);
		value = ft_atoi(split[i], &error_flag);
		if (error_flag || is_repeated(*a, value))
			free_and_exit(split, a);
		add_node(a, value);
		i++;
	}
	free_split(split);
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
