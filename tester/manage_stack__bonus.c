/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack__bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/05 15:43:17 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	check_overflow(unsigned long result, int nb, int sign)
{
	if (sign == 1)
	{
		if ((result >= 214748364 && nb > 7) 
			|| result >= 214748365)
			return (1);
	}
	if (sign == -1)
	{
		if ((result >= 214748364 && nb > 8) 
			|| result > 214748365)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *error_flag)
{
	int				i;
	int				sign;
	int				result;

	i = 0;
	result = 0;
	sign = 1;
	*error_flag = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(result, str[i] - '0', sign))
		{
			*error_flag = 1;
			return (0);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
