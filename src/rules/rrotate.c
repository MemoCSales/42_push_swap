/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:59:34 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/11 01:08:04 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rev_rotate(t_stack **stack_head)
{
	t_stack	*last_node;
	t_stack	*prev_node;

	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	last_node = find_last(*stack_head);
	prev_node = node_before_last(*stack_head);
	prev_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack_head;
	(*stack_head)->prev = last_node;
	*stack_head = last_node;
	// exit(1);
}

t_stack		*node_before_last(t_stack *list)
{
	while (list && list->next && list->next->next != NULL)
		list = list->next;
	return (list);
}

// Function that reverse rotate stack a
void	rra(t_stack **a_head, bool print)
{
	rev_rotate(a_head);
	if (print)
		write(1, "rra\n", 4);
}

// Function that reverse rotate stack b
void	rrb(t_stack **b_head, bool print)
{
	rev_rotate(b_head);
	if (print)
		write(1, "rrb\n", 4);
}

// Function that reverse rotate both
void	rrr(t_stack **a_head, t_stack **b_head)
{
	rev_rotate(a_head);
	rev_rotate(b_head);
	write(1, "rrr\n", 4);
}
