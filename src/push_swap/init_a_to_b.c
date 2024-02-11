/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:18:41 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/11 00:57:52 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	first_push(stack_a, stack_b);
	sort_three(stack_a);
}
