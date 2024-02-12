/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:20:29 by jimenasando       #+#    #+#             */
/*   Updated: 2024/02/13 00:37:42 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//This function reverse rotate both stacks until one of them is in position
//The cost is negative sice both are located in the bottom half of their stacks
// The cost is increasing as the stacks are rotated when one reaches 0
// the stacks has been rotated as far as possible and the top position is
// correct
static void	do_rr_both(t_stack **a_head, t_stack **b_head, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a_head, b_head);
	}
}

static void do_r_both(t_stack **a_head, t_stack **b_head, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a_head, b_head);
	}
}

void	do_move(t_stack **a_head, t_stack **b_head, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rr_both(a_head, b_head, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_r_both(a_head, b_head, &cost_a, &cost_b);
	//finish rotation
	//finish rotation
	//push to a
}
