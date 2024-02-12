/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:18:41 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/13 00:25:15 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//Function that pushes the elements from stack A to B considering the indexes
void	first_push(t_stack **a_head, t_stack **b_head)
{
	int		len_a;
	int		i;
	int		count;
	
	len_a = stack_len(a_head);
	i = 0;
	count = 0;
	while (i < len_a && count < len_a / 2)
	{
		if ((*a_head)->index <= len_a / 2)
		{
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

//Function to know the absolute value of a number
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
		if(nb_abs(curr->price_a) + nb_abs(curr->price_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(curr->price_b) + nb_abs(curr->price_b);
			cost_a = curr->price_a;
			cost_b = curr->price_b;
		}
		curr = curr->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	first_push(stack_a, stack_b);
	sort_three(stack_a);
	while(*stack_b)
	{
		init_node(stack_a, stack_b);
		do_cheapest(stack_a, stack_b);
	}
}
