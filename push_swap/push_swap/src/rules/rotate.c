/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:01 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/08 17:59:42 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
// Function that makes the work of the rotation rule
void	rotate(t_stack **stack_head, t_stack **stack_tail)
{
	t_stack	*first_node;
	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	first_node = *stack_head;
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = (*stack_tail)->next;
	(*stack_tail)->next = first_node;
	*stack_tail = first_node;
}

// Function that rotate stack a
void	ra(t_stack **a_head, t_stack **a_tail, bool print)
{
	rotate(a_head, a_tail);
	if (print)
		write(1, "ra\n", 3);
}

// Function that rotate stack b
void	rb(t_stack **b_head, t_stack **b_tail, bool print)
{
	rotate(b_head, b_tail);
	if (print)
		write(1, "rb\n", 3);
}

// Function that rotates both
void	rr(t_stack **a_head, t_stack **a_tail, t_stack **b_head,
		t_stack **b_tail)
{
	rotate(a_head, a_tail);
	rotate(b_head, b_tail);
	write(1, "rr\n", 3);
}
