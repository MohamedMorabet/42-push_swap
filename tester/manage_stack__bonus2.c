/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack__bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:22:05 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/05 15:41:02 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

//check if the stack is empty
int	is_empty(t_stack_node *stack)
{
	if (!stack)
		return (1);
	return (0);
}

void	free_and_exit(char **split, t_stack_node **a)
{
	if (split)
		free_split(split);
	if (a)
		free_stack(a);
	exit_error();
}
