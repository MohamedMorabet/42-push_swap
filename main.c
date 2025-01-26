/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:54:45 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/26 10:05:46 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || ((ac == 2) && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av[0])
		return (1);
	create_stack(&a, ac, av);
	ac = len_stack(a);
	set_rank(a);
	if (!is_sorted(a))
	{
		if (ac <= 4)
			tiny_sort(&a);
		else if (ac <= 6)
			sort_five(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
