/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:30:14 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/05 15:43:06 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*opearation;

	a = NULL;
	b = NULL;
	if (ac == 1 || ((ac == 2) && !av[1][0]))
		return (1);
	create_stack(&a, av);
	opearation = get_next_line(STDIN_FILENO);
	while (opearation)
	{
		do_operation(&a, &b, opearation);
		free(opearation);
		opearation = get_next_line(STDIN_FILENO);
	}
	check_sort(a, b);
	free_stack(&a);
	free_stack(&b);
}

//helper function for the norminette
void	check_sort(t_stack_node *a, t_stack_node *b)
{
	if (is_sorted(a) && is_empty(b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void	do_operation(t_stack_node **a, t_stack_node **b, char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		swap_a__bonus(a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		swap_b__bonus(b);
	else if (ft_strcmp(operation, "ss\n") == 0)
		swap_ab__bonus(a, b);
	else if (ft_strcmp(operation, "pa\n") == 0)
		push_a__bonus(a, b);
	else if (ft_strcmp(operation, "pb\n") == 0)
		push_b__bonus(a, b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		rotate_a__bonus(a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rotate_b__bonus(b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rotate_ab__bonus(a, b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		reverse_rotate_a__bonus(a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		reverse_rotate_b__bonus(b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		reverse_rotate_ab__bonus(a, b);
	else
		exit_error();
}
