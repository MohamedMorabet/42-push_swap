/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:54:45 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 21:37:41 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void check_leaks(void)
// {
// 	system("leaks push_swap");
// }
// atexit(check_leaks); add it in the beggening of the main
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
	create_stack(&a, ac, av);
	if (!is_sorted(a))
	{
		if (ac == 4)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
		// printf("Not sorted\n");
	}
	// printf("\na :\n");
	// print_stack(a);
	// printf("\nb :\n");
	// print_stack(b);
	free_sack(&a);
	free_sack(&b);
}
