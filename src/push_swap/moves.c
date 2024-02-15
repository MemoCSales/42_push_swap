/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:20:29 by mcruz-sa	       #+#    #+#             */
/*   Updated: 2024/02/15 11:18:30 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// This function reverse rotate both stacks until one of them is in position
// The cost is negative sice both are located in the bottom half
// of their stacks. The cost is increasing as the stacks are rotated 
// when one reaches 0 the stacks has been rotated as 
// far as possible and the top position is correct
void	do_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
	// init_position(*a);
	// init_position(*b);
}

// This function rotate both stack until one of them is in position.
// The cost is positive since both are located in the bottom 
// half of their stacks. The cost is decreasing as the stacks 
// are rotated when one reaches 0 the stacls has been rotated as
// bar as possible and the top position is correct
void	do_r_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
	// init_position(*a);
	// init_position(*b);
}

void	do_rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(a, true);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(a, true);
			(*cost_a)++;
		}
	}
}

void	do_rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(b, true);
			// printf("Nodo en b");
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(b, true);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	// printf("Cost a %d, cost b %d\n", cost_a, cost_b);
	if (cost_a < 0 && cost_b < 0)
		do_rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_r_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	pa(a, b, true);
}
