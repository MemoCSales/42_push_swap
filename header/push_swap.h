/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:25:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/14 21:25:35 by jimenasando      ###   ########.fr       */
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
	int				cost_a;
	int				cost_b;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// DEALLOCATION
void				deallocate_stack(t_stack **a_head, t_stack **a_tail);
void				free_stack(t_stack **a_head, t_stack **a_tail);

// ERROR HANDLING
int					check_error_syntax(char *str);
void				error_check(t_stack **a_head, t_stack **a_tail,
						char **args);
void				duplicate_error(t_stack *a_head, t_stack *a_tail);

// INDEXING
int					*sort_array(t_stack **a_head);
void				indexing(t_stack **a_head);
void				swap_int(int *i, int *j);
void				bubble_sort(int *int_array, int size);
bool				is_cyclic(t_stack *stack_head); // havent used yet

// INIT_A_TO_B
void				first_push(t_stack **a_head, t_stack **b_head);
void				do_cheapest(t_stack **stack_a, t_stack **stack_b);
void				sort_stacks(t_stack **stack_a, t_stack **stack_b);
int					nb_abs(int nb);

// NODE INITIALIZATION
void				init_position(t_stack *node);
void				set_target_node(t_stack **a_head, t_stack **b_head);
void				set_cost(t_stack **a_head, t_stack **b_head);
void				init_node(t_stack **a_head, t_stack **b_head);

// STACK_INIT
long				ft_atol(const char *str);
void				create_stack(t_stack **stack_head, t_stack **stack_tail,
						int value);
void				stack_a_init(t_stack **a_head, t_stack **a_tail,
						char **args);

// STACK UTILS
void				insert_last(t_stack **a_tail, int value);
int					stack_len(t_stack **stack);
bool				sorted_stack(t_stack *stack);

// STACK UTILS 2
t_stack				*find_biggest(t_stack *stack_head);
t_stack				*find_smallest(t_stack *stack_head);
t_stack				*find_last(t_stack *stack_head);
t_stack				*node_before_last(t_stack *list);

// MOVES
void			do_rr_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void			do_r_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void			do_rotate_a(t_stack **a, int *cost_a);
void			do_rotate_b(t_stack **b, int *cost_b);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

// PUSH_SWAP RULES
void				push(t_stack **dst, t_stack **src);
void				pa(t_stack **a_head, t_stack **b_head, bool print);
void				pb(t_stack **b_head, t_stack **a_head, bool print);
t_stack				*pop(t_stack **stack);

void				rotate(t_stack **stack_head);
void				ra(t_stack **a_head, bool print);
void				rb(t_stack **b_head, bool print);
void				rr(t_stack **a_head, t_stack **b_head);

void				rev_rotate(t_stack **stack_head);
void				rra(t_stack **a_head, bool print);
void				rrb(t_stack **b_head, bool print);
void				rrr(t_stack **a_head, t_stack **b_head);

void				swap(t_stack **stack_head);
void				sa(t_stack **a_head, bool print);
void				sb(t_stack **b_head, bool print);
void				ss(t_stack **a_head, t_stack **b_head, bool print);

// SORTING
void				sort_three(t_stack **a_head);

#endif