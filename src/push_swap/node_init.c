/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:04:49 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/14 16:42:42 by mcruz-sa         ###   ########.fr       */
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
	while (curr_b)
	{
		best_node = INT_MAX;
		curr_a = *a_head;
		while (curr_a)
		{
			if (curr_a->index > curr_b->index && curr_a->index < best_node)
			{
				best_node = curr_a->index;
				target_node = curr_a;
				// printf("index in b [%d] // index in a [%d] -> best node {%ld}\n", curr_b->index, curr_a->index, target_node->nbr);
			}
			curr_a = curr_a->next;
			if (best_node == INT_MAX)
			{
				curr_b->target_node = find_smallest(*a_head);
				// printf("Node [%ld] -> target node {%ld}\n", curr_b->nbr, curr_b->target_node->nbr);
			}
			else
			{
				curr_b->target_node = target_node;
				// printf("Target node <%d>\n", curr_b->target_node->index);
			}
		}
		curr_b = curr_b->next;
	}
}

void	set_price(t_stack **a_head, t_stack **b_head)
{
	t_stack	*curr_a;
	t_stack	*curr_b;
	int		size_a;
	int		size_b;

	size_a = stack_len(a_head);
	size_b = stack_len(b_head);
	curr_a = *a_head;
	curr_b = *b_head;
	while (curr_b)
	{
		curr_b->price_b = curr_b->pos;
		if (curr_b->pos > size_a / 2)
		{
			curr_b->price_b = (size_b - curr_b->pos) * -1;
			// printf("Nodo -> %ld \t Precio b del nodo %d\n", curr_b->nbr, curr_b->price_b);
		}
		curr_b->price_a = curr_b->target_node->pos;
		if (curr_b->target_node->pos > size_a / 2)
		{
			curr_b->price_a = (size_a - curr_b->target_node->pos) * -1;
			// printf("Nodo -> %ld \t Precio a del nodo %d\n", curr_b->nbr, curr_b->price_a);
		}
		curr_b = curr_b->next;
	}
}

void	init_node(t_stack **a_head, t_stack **b_head)
{
	init_position(*a_head);
	init_position(*b_head);
	set_target_node(a_head, b_head);
	set_price(a_head, b_head);
}
