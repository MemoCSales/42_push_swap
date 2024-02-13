/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:25 by jimenasando       #+#    #+#             */
/*   Updated: 2024/02/13 19:03:52 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function to find the node with the biggest number
t_stack	*find_biggest(t_stack *stack_head)
{
	t_stack	*curr;
	t_stack	*max_node;

	if (!stack_head)
		return (NULL);
	curr = stack_head;
	max_node = curr;
	while (curr != NULL)
	{
		if (curr->nbr > max_node->nbr)
			max_node = curr;
		curr = curr->next;
	}
	return (max_node);
}

// Function to find the node with the smallest number
t_stack	*find_smallest(t_stack *stack_head)
{
	t_stack	*curr;
	t_stack	*min_node;

	if (!stack_head)
		return (NULL);
	curr = stack_head;
	min_node = curr;
	while (curr != NULL)
	{
		if (curr->nbr < min_node->nbr)
			min_node = curr;
		curr = curr->next;
	}
	return (min_node);
}

t_stack	*find_last(t_stack *stack_head)
{
	t_stack	*curr;

	curr = stack_head;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

t_stack	*node_before_last(t_stack *list)
{
	while (list && list->next && list->next->next != NULL)
		list = list->next;
	return (list);
}
