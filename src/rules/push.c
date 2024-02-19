/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:05:00 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/19 13:00:17 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (*src == NULL || src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*dst == NULL)
	{
		*dst = push_node;
		(*dst)->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		*dst = push_node;
	}
}

void	pa(t_stack **a_head, t_stack **b_head, bool print)
{
	push(a_head, b_head);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b_head, t_stack **a_head, bool print)
{
	push(b_head, a_head);
	if (print)
		write(1, "pb\n", 3);
}
