/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:46:08 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/11 08:38:58 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
