/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:54:45 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/04 21:35:02 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_leaks(void)
{
	system("leaks a.out");
}
int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	atexit(check_leaks);
	a = NULL;
	b = NULL;
	if (ac == 1 || ((ac == 2) && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	create_stack(&a, ac, av);
	if (!is_sorted(a))
	{
		
		printf("Not sorted\n");
	}
	free_sack(&a);
	free_sack(&b);
}
