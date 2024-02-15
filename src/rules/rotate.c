/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:14:10 by mcruz-sa	       #+#    #+#             */
/*   Updated: 2024/02/15 11:19:27 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function that makes the work of the rotation rule
void	rotate(t_stack **stack_head)
{
	t_stack	*first_node;
	t_stack	*last_node;

	last_node = find_last(*stack_head);
	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	first_node = *stack_head;
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node->next;
	last_node->next = first_node;
	last_node = first_node;
}

// Function that rotate stack a
void	ra(t_stack **a_head, bool print)
{
	rotate(a_head);
	if (print)
		write(1, "ra\n", 3);
}

// Function that rotate stack b
void	rb(t_stack **b_head, bool print)
{
	rotate(b_head);
	if (print)
		write(1, "rb\n", 3);
}

// Function that rotates both
void	rr(t_stack **a_head, t_stack **b_head)
{
	rotate(a_head);
	rotate(b_head);
	write(1, "rr\n", 3);
}
