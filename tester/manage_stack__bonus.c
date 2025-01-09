/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack__bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/09 00:39:39 by mel-mora         ###   ########.fr       */
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
	if (ac == 2)
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

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			res = res * 10 + *str - '0';
			str++;
		}
		else
			exit_error();
	}
	return (res * sign);
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
