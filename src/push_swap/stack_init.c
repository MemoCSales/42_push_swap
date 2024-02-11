/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:21:56 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/10 22:45:51 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Function to convert a char to a long number. In case the input
// passed is bigger than the integer limits
long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' && *(str + 1) != '-')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	if (sign % 2)
		return (-result);
	else
		return (result);
}

void	create_stack(t_stack **stack_head, t_stack **stack_tail, int value)
{
	t_stack	*new_node;

	if (!stack_head || !stack_tail)
		return ;
	if (!(*stack_head))
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return ;
		new_node->nbr = value;
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack_head = new_node;
		*stack_tail = new_node;
	}
	else
		insert_last(stack_tail, value);
}

// Function to initialize the stack handling all the errors
void	stack_a_init(t_stack **a_head, t_stack **a_tail, char **args)
{
	int		i;
	long	n;

	i = 0;
	while (args[i])
	{
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_stack(a_head, a_tail);
		create_stack(a_head, a_tail, (int)n);
		i++;
	}
	duplicate_error(*a_head, *a_tail);
}
