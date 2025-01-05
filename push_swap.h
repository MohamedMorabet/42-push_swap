/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:54:57 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/04 19:28:05 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

void	create_stack(t_stack_node **a, int ac, char **av);
void	exit_error(void);
void	add_node(t_stack_node **stack, int value);
int		is_repeated(t_stack_node *stack, int value);
int		is_sorted(t_stack_node *stack); 
int	    is_digit(char *str);
void	free_sack(t_stack_node **stack);
long long	ft_atoll(const char *str);
void	free_split(char **split);
// void	initialize_node(t_stack_node *node, int value);

#endif