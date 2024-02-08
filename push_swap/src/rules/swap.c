/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:08 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/07 19:26:20 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function that makes the work of swapping
void	swap(t_stack **stack_head)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	first_node = *stack_head;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->prev = second_node;
	*stack_head = second_node;
}

// Function that swaps the first 2 nodes of stack a
void	sa(t_stack **a_head, bool print)
{
	swap(a_head);
	if (print)
		write(1, "sa\n", 3);
}

// Function that swaps the first 2 nodes of stack b

// Function that swaps both stacks at the same time