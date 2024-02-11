/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:33:28 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/10 22:47:51 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	indexing(t_stack **a_head)
{
	t_stack	*curr;
	int		*sorted_arr;
	int		j;
	int		*temp;

	curr = *a_head;
	sorted_arr = sort_array(a_head);
	while (curr)
	{
		j = 1;
		temp = sorted_arr;
		while (*temp)
		{
			if (curr->nbr == *temp)
			{
				curr->index = j;
				break ;
			}
			temp++;
			j++;
		}
		curr = curr->next;
	}
	free(sorted_arr);
}

int	*sort_array(t_stack **a_head)
{
	int		*int_arr;
	int		*tmp;
	int		size;
	t_stack	*curr;

	curr = *a_head;
	size = stack_len(a_head);
	int_arr = malloc(sizeof(int) * size);
	if (!int_arr)
		return (NULL);
	tmp = int_arr;
	while (curr)
	{
		*tmp = curr->nbr;
		tmp++;
		curr = curr->next;
	}
	bubble_sort(int_arr, size);
	return (int_arr);
}

void	swap_int(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	bubble_sort(int *int_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < (size - i) - 1)
		{
			if (int_array[j] > int_array[j + 1])
				swap_int(&int_array[j], &int_array[j + 1]);
			j++;
		}
		i++;
	}
}

// Function to check if the stack is cyclically sorted
bool	is_cyclic(t_stack *stack_head)
{
	t_stack	*curr;

	if (!stack_head || !stack_head->next)
		return (false);
	curr = find_biggest(stack_head);
	while (curr != NULL)
	{
		if (curr->prev && (curr->nbr < curr->prev->nbr))
			return (false);
		curr = curr->prev;
	}
	curr = find_biggest(stack_head)->next;
	if (curr && curr->nbr != find_smallest(stack_head)->nbr)
		return (false);
	while (curr->next != NULL)
	{
		if (curr->next && (curr->nbr > curr->next->nbr))
			return (false);
		curr = curr->next;
	}
	return (true);
}
