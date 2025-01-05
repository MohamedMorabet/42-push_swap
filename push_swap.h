/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:54:57 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/05 21:14:59 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_moy;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// -------------manage_stack---------------
void			create_stack(t_stack_node **a, int ac, char **av);
void			exit_error(void);
void			add_node(t_stack_node **stack, int value);
int				is_repeated(t_stack_node *stack, int value);
int				is_sorted(t_stack_node *stack); 
int				is_digit(char *str);
void			free_sack(t_stack_node **stack);
long long		ft_atoll(const char *str);
void			free_split(char **split);
void			print_stack(t_stack_node *stack);
int				len_stack(t_stack_node *stack);

// -------------operations---------------
void			swap_a(t_stack_node **a); //swap
void			swap_b(t_stack_node **b);
void			swap_ab(t_stack_node **a, t_stack_node **b);
void			push_a(t_stack_node **a, t_stack_node **b); // push
void			push_b(t_stack_node **b, t_stack_node **a);
void			rotate_a(t_stack_node **a); // rotate
void			rotate_b(t_stack_node **b);
void			rotate_ab(t_stack_node **a, t_stack_node **b);
void			reverse_rotate_a(t_stack_node **a); // reverse rotate
void			reverse_rotate_b(t_stack_node **b);
void			reverse_rotate_ab(t_stack_node **a, t_stack_node **b);

// -------------operations_utils--------------
t_stack_node	*ft_lastnode(t_stack_node *lst);

// -------------algorithms---------------
void			tiny_sort(t_stack_node **a);
t_stack_node	*ft_highest(t_stack_node *lst);
t_stack_node	*ft_lowest(t_stack_node *lst);
t_stack_node	*get_cheapest(t_stack_node *b);

// -------------push_swap---------------
void			push_swap(t_stack_node **a, t_stack_node **b);

// -------------push_swap_utils---------------
void			set_position(t_stack_node *stack);
void			intialize_stack(t_stack_node *a, t_stack_node *b);
void			set_target(t_stack_node *a, t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *a, t_stack_node *b);
void			finish_rotation_a(t_stack_node **a, t_stack_node *target);
void			finish_rotation_b(t_stack_node **b, t_stack_node *cheapest);
void			move_to_a(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);

#endif