/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:04:49 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/12 18:16:41 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	init_position(t_stack *node)
{
	int	i;
	
	i = 0;
	if (!node)
		return ;
	while (node)
	{
		node->pos = i;
		node = node->next;
		i++;
	}
}

void	set_target_node(t_stack **a_head, t_stack **b_head)
{
	t_stack	*curr_a;
	t_stack	*curr_b;
	t_stack	*target_node;
	int		best_node;
	
	curr_b = *b_head;
	while(curr_b)
	{
		curr_a = *a_head;
		best_node = INT_MAX;
		while (curr_a)
		{
			if (curr_a->index > curr_b->index && curr_a->index < best_node)
			{
				best_node = curr_a->index;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
			if (best_node == INT_MAX)
				curr_b->target_node = find_smallest(*a_head);
			else
				curr_b->target_node = target_node;
		}
		curr_b = curr_b->next;
	}
}

void	init_node(t_stack **a_head, t_stack **b_head)
{
	init_position(*a_head);
	init_position(*b_head);
	set_target_node(a_head, b_head);
}