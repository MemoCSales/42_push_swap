/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:40:26 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/15 11:19:39 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_three(t_stack **a_head)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a_head);
	if (biggest_node == *a_head)
		ra(a_head, true);
	else if (biggest_node == (*a_head)->next)
		rra(a_head, true);
	if ((*a_head)->nbr > (*a_head)->next->nbr)
		sa(a_head, true);
}
