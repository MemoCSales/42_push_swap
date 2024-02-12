/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:25:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/12 19:50:23 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

// STACK DEFINITION
typedef struct s_stack
{
	long			nbr;
	int				index;
	int				pos;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// STACK FUNCTIONS
long				ft_atol(const char *str);
void				create_stack(t_stack **stack_head, t_stack **stack_tail,
						int value);
void				stack_a_init(t_stack **a_head, t_stack **a_tail,
						char **args);

// STACK UTILS
void				insert_last(t_stack **a_tail, int value);
int					stack_len(t_stack **stack);
bool				sorted_stack(t_stack *stack);
t_stack				*find_biggest(t_stack *stack_head);
t_stack				*find_smallest(t_stack *stack_head);
t_stack				*find_last(t_stack *stack_head);

// INDEXING
int					*sort_array(t_stack **a_head);
void				indexing(t_stack **a_head);
void				swap_int(int *i, int *j);
void				bubble_sort(int *int_array, int size);
bool				is_cyclic(t_stack *stack_head);

// PUSH_SWAP RULES
void				swap(t_stack **stack_head);
void				sa(t_stack **a_head, bool print);

void				rotate(t_stack **stack_head);
void				ra(t_stack **a_head, bool print);
void				rb(t_stack **b_head, bool print);
void				rr(t_stack **a_head, t_stack **b_head);

void				rev_rotate(t_stack **stack_head);
void				rra(t_stack **a_head, bool print);
void				rrb(t_stack **b_head, bool print);
void				rrr(t_stack **a_head, t_stack **b_head);

void				push(t_stack **dst, t_stack **src);
void				pa(t_stack **a_head, t_stack **b_head, bool print);
void				pb(t_stack **b_head, t_stack **a_head, bool print);
t_stack				*pop(t_stack **stack);

// SORTING
void				sort_three(t_stack **a_head);
void				sort_stacks(t_stack **stack_a, t_stack **stack_b);
t_stack				*node_before_last(t_stack *list);
void				first_push(t_stack **a_head, t_stack **b_head);
void				init_position(t_stack *node);
void				set_target_node(t_stack **a_head, t_stack **b_head);
void				init_node(t_stack **a_head, t_stack **b_head);

// ERROR HANDLING
int					check_error_syntax(char *str);
void				error_check(t_stack **a_head, t_stack **a_tail,
						char **args);
void				duplicate_error(t_stack *a_head, t_stack *a_tail);

// DEALLOCATION
void				deallocate_stack(t_stack **a_head, t_stack **a_tail);
void				free_stack(t_stack **a_head, t_stack **a_tail);
void				free_split(char **split_argv);

#endif