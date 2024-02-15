/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:18:41 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/15 15:29:23 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function that pushes the elements from stack A to B considering the indexes
void	first_push(t_stack **a_head, t_stack **b_head)
{
	int	len_a;
	int	i;
	int	count;

	len_a = stack_len(a_head);
	i = 0;
	count = 0;
	while (len_a > 6 && i < len_a && count < len_a / 2)
	{
		if ((*a_head)->index <= len_a / 2)
		{
			// printf("Node [%ld] -> to stack b\n", (*a_head)->nbr);
			pb(b_head, a_head, true);
			count++;
		}
		else
			ra(a_head, true);
		i++;
	}
	while (len_a - count > 3)
	{
		pb(b_head, a_head, true);
		count++;
	}
}

// Function to know the absolute value of a number
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

// This function finds the element with the cheapest cost to move to stack A
// and moves it to the correct position in stack A
void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*curr;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	curr = *stack_b;
	cheapest = INT_MAX;
	while (curr)
	{
		// printf("Cost a = %d // Cost b = %d // Cheapest = %d\n", curr->cost_a, curr->cost_b, cheapest);
		if (nb_abs(curr->cost_a) + nb_abs(curr->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(curr->cost_b) + nb_abs(curr->cost_a);
			// printf("current node %ld cheapest: %d\n", curr->nbr, cheapest);
			cost_a = curr->cost_a;
			cost_b = curr->cost_b;
			// printf("Cost_a %d \t Cost_b %d\n", cost_a, cost_b);
		}
		curr = curr->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	final_rotation(t_stack **stack_a)
{
	t_stack	*lowest_node;
	int		size;

	size = stack_len(stack_a);
	lowest_node = find_smallest(*stack_a);
	init_position(*stack_a);
	if (lowest_node->pos > size / 2)
	{
		while (lowest_node->pos != 0)
		{
			rra(stack_a, true);
			init_position(*stack_a);
			lowest_node = find_smallest(*stack_a);
		}
	}
	else
	{
		while (lowest_node->pos != 0)
		{
			ra(stack_a, true);
			init_position(*stack_a);
			lowest_node = find_smallest(*stack_a);
		}
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	indexing(stack_a);
	first_push(stack_a, stack_b);
	sort_three(stack_a);
	// t_stack	*curr = *stack_a;
	// printf("Stack a \t:");
	// while (curr != NULL)
	// {
	// 	printf("%ld->", curr->nbr);
	// 	curr = curr->next;
	// }
	// printf("\n");
	// curr = *stack_a;
	// printf("Index \t\t:");
	// while (curr != NULL)
	// {
	// 	printf("{%d}", curr->index);
	// 	curr = curr->next;
	// }
	// printf("\n");
	// printf("Stack b \t:");
	// t_stack	*curr2 = *stack_b;
	// while (curr2 != NULL)
	// {
	// 	printf("%ld->", curr2->nbr);
	// 	curr2 = curr2->next;
	// }
	// printf("\n");
	// curr2 = *stack_b;
	// printf("Index \t\t:");
	// while (curr2 != NULL)
	// {
	// 	printf("{%d}", curr2->index);
	// 	curr2 = curr2->next;
	// }
	// printf("\n");
	
	while (*stack_b)
	{
		init_node(stack_a, stack_b);
		// t_stack *curr2 = *stack_b;
		// printf("Price in a \t:");
		// while (curr2 != NULL)
		// {
		// 	printf("{%d}", curr2->cost_a);
		// 	curr2 = curr2->next;
		// }
		// printf("\n");
		// curr2 = *stack_b;
		// printf("Price in b \t:");
		// while (curr2 != NULL)
		// {
		// 	printf("{%d}", curr2->cost_b);
		// 	curr2 = curr2->next;
		// }
		// printf("\n");
		do_cheapest(stack_a, stack_b);
	}
	if (!sorted_stack(*stack_a))
	{
		final_rotation(stack_a);
	}
}
