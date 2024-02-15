/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:07 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/15 11:18:53 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function to append a node
void	insert_last(t_stack **a_tail, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = *a_tail;
	(*a_tail)->next = new_node;
	*a_tail = new_node;
}

// Function to know the lenght of the stack
int	stack_len(t_stack **stack)
{
	int		len;
	t_stack	*curr;

	len = 0;
	curr = *stack;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

// Function to check if the stack is sorted
bool	sorted_stack(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
