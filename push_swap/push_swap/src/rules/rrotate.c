/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:59:34 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/08 18:18:32 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rev_rotate(t_stack **stack_head, t_stack **stack_tail)
{
	t_stack	*last_node;
	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	last_node = *stack_tail;
	*stack_tail = (*stack_tail)->prev;
	(*stack_tail)->next = NULL;
	last_node->next = *stack_head;
	last_node->prev = NULL;
	(*stack_head)->prev = last_node;
	*stack_head = last_node;
}

// Function that reverse rotate stack a
void	rra(t_stack **a_head, t_stack **a_tail, bool print)
{
	rev_rotate(a_head, a_tail);
	if (print)
		write(1, "rra\n", 4);
}

// Function that reverse rotate stack b
void	rrb(t_stack **b_head, t_stack **b_tail, bool print)
{
	rev_rotate(b_head, b_tail);
	if (print)
		write(1, "rrb\n", 4);
}

// Function that reverse rotate both
void	rrr(t_stack **a_head, t_stack **a_tail, t_stack **b_head,
		t_stack **b_tail)
{
	rotate(a_head, a_tail);
	rotate(b_head, b_tail);
	write(1, "rrr\n", 4);
}
