/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:54:57 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/21 13:16:20 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "tester/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

/*
** Stack Node Data Structure
*/
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					rank;
	int					push_price;
	bool				above_moy;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

/*
** ------------------ Stack Management ------------------
*/
void			create_stack(t_stack_node **a, int ac, char **av);
void			exit_error(void);
void			add_node(t_stack_node **stack, int value);
int				is_repeated(t_stack_node *stack, int value);
int				is_sorted(t_stack_node *stack);
int				is_digit(char *str);
void			free_stack(t_stack_node **stack);
int				ft_atoi(const char *str);
void			free_split(char **split);
int				len_stack(t_stack_node *stack);
int				ft_count_words(char **str);
void			set_i_ac(int *ac, int *i, char **av);

/*
** ------------------ Rank and Chunk Operations ------------------
*/
void			set_rank(t_stack_node *stack);
void			move_by_chunks(t_stack_node **a, t_stack_node **b, int chunk);
int				no_elements_in_chunk(t_stack_node *a, int chunk_min,
					int chunk_max);
int				*create_table(t_stack_node *stack);
void			sort_table(int *tab, int len);
int				get_rank(int *tab, int len, int value);

/*
** ------------------ Operations ------------------
*/
void			swap_a(t_stack_node **a);
void			swap_b(t_stack_node **b);
void			swap_ab(t_stack_node **a, t_stack_node **b);
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **b, t_stack_node **a);
void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_ab(t_stack_node **a, t_stack_node **b);
void			rotate(t_stack_node **b);
void			reverse_rotate_a(t_stack_node **a);
void			reverse_rotate_b(t_stack_node **b);
void			reverse_rotate_ab(t_stack_node **a, t_stack_node **b);
void			reverse_rotate(t_stack_node **b);

/*
** ------------------ Operations Utilities ------------------
*/
t_stack_node	*ft_lastnode(t_stack_node *lst);

/*
** ------------------ Algorithms ------------------
*/
void			tiny_sort(t_stack_node **a);
t_stack_node	*ft_highest(t_stack_node *lst);
t_stack_node	*ft_lowest(t_stack_node *lst);
t_stack_node	*get_cheapest(t_stack_node *b);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			bring_to_top(t_stack_node **a, t_stack_node *target,
					void (*rotate)(t_stack_node **),
					void (*reverse_rotate)(t_stack_node **));
void			find_and_push_smallest(t_stack_node **a, t_stack_node **b);

/*
** ------------------ Push Swap Algorithm ------------------
*/
void			push_swap(t_stack_node **a, t_stack_node **b);

/*
** ------------------ Push Swap Utilities ------------------
*/
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
int				max_between(int a, int b);
void			calculate_price_above_moy(t_stack_node *b, int len_a);
void			calculate_price_below_moy(t_stack_node *b, int len_a,
					int len_b);

/*
** ------------------ String Utilities ------------------
*/
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
int				ft_isdigit(int c);
void			ft_putstr(char *str);

/*
** ------------------ Bonus Operations ------------------
*/
void			swap_a__bonus(t_stack_node **a);
void			swap_b__bonus(t_stack_node **b);
void			swap_ab__bonus(t_stack_node **a, t_stack_node **b);
void			push_a__bonus(t_stack_node **a, t_stack_node **b);
void			push_b__bonus(t_stack_node **b, t_stack_node **a);
void			rotate_a__bonus(t_stack_node **a);
void			rotate_b__bonus(t_stack_node **b);
void			rotate__bonus(t_stack_node **b);
void			rotate_ab__bonus(t_stack_node **a, t_stack_node **b);
void			reverse_rotate_a__bonus(t_stack_node **a);
void			reverse_rotate_b__bonus(t_stack_node **b);
void			reverse_rotate__bonus(t_stack_node **b);
void			reverse_rotate_ab__bonus(t_stack_node **a, t_stack_node **b);
void			do_operation(t_stack_node **a, t_stack_node **b,
					char *operation);

/*
** ------------------ Additional Utilities ------------------
*/
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
char			**ft_split(char const *s, char c);
t_stack_node	*ft_lastnode__bonus(t_stack_node *lst);
int				ft_strcmp(const char *s1, const char *s2);

#endif