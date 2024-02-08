/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:35:09 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/07 19:21:24 by mcruz-sa         ###   ########.fr       */
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
