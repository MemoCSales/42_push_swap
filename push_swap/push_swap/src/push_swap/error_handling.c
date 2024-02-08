/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:55:02 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/08 17:39:13 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	else if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

// Function to check error syntax
void	error_check(t_stack **a_head, t_stack **a_tail, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_error_syntax(args[i]))
			free_stack(a_head, a_tail);
		i++;
	}
}

// Function to check for duplicates before passing to the stack
void	duplicate_error(t_stack *a_head, t_stack *a_tail)
{
	t_stack	*curr;
	t_stack	*runner;

	curr = a_head;
	if (!a_head)
		return ;
	while (curr != NULL)
	{
		runner = curr;
		while (runner->next != NULL)
		{
			if (curr->nbr == runner->next->nbr)
				free_stack(&a_head, &a_tail);
			runner = runner->next;
		}
		curr = curr->next;
	}
	return ;
}
