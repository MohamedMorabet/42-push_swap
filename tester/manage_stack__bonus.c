/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack__bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/11 08:40:49 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	int				result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(result, str[i] - '0', sign))
			exit_error();
		result = result * 10 + (str[i] - '0');
		i++;
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
