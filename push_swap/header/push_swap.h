/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:25:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/07 19:23:44 by mcruz-sa         ###   ########.fr       */
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
	long			index;
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

// PUSH_SWAP RULES
void				swap(t_stack **stack_head);
void				sa(t_stack **a_head, bool print);

void				rotate(t_stack **stack_head, t_stack **stack_tail);
void				ra(t_stack **a_head, t_stack **a_tail, bool print);
void				rb(t_stack **b_head, t_stack **b_tail, bool print);
void				rrr(t_stack **a_head, t_stack **a_tail, t_stack **b_head,
						t_stack **b_tail, bool print);

// SORTING 3
void				sort_three(t_stack **a_head, t_stack **a_tail);

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