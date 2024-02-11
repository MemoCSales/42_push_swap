/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:35:09 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/10 22:08:12 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function to free all the memory allocated
void	deallocate_stack(t_stack **a_head, t_stack **a_tail)
{
	t_stack	*curr;
	t_stack	*new_node;

	if (*a_head == NULL)
		return ;
	curr = *a_head;
	while (curr != NULL)
	{
		new_node = curr->next;
		free(curr);
		curr = new_node;
	}
	*a_head = NULL;
	*a_tail = NULL;
}

// Function to free the stack
void	free_stack(t_stack **a_head, t_stack **a_tail)
{
	deallocate_stack(a_head, a_tail);
	write(2, "Error\n", 6);
	exit(1);
}
