/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:50:18 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/10 17:17:23 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	t_stack	*b_head;
	t_stack	*b_tail;
	t_stack	*curr;

	(void)curr;

	a_head = NULL;
	a_tail = NULL;
	b_head = NULL;
	b_tail = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	error_check(&a_head, &a_tail, argv + 1);
	stack_a_init(&a_head, &a_tail, argv + 1);
	// if (!(sorted_stack(a_head)))
	// {
	// 	if (stack_len(&a_head) == 2)
	// 		sa(&a_head, true);
	// 	else if (stack_len(&a_head) == 3)
	// 		sort_three(&a_head, &a_tail);
	// 	// else
	// 	// 	sort_stacks(&a_head, &b_head);
	// }
	// curr = a_head;
	// while (curr != NULL)
	// {
	// 	printf("%ld->", curr->nbr);
	// 	curr = curr->next;
	// }
	// printf("\n");
	// deallocate_stack(&a_head, &a_tail);

	curr = a_head;
	indexing(&curr);
	curr = a_head;
	while (curr != NULL)
	{
		printf("%ld\t", curr->nbr);
		curr = curr->next;
	}
	printf("\n");
	curr = a_head;
	while (curr != NULL)
	{
		printf("{%d}\t", curr->sorted_idx);
		curr = curr->next;
	}
	printf("\n");
	int	*sorted_arr = sort_array(&a_head);
	int	i;
	int	len;
	
	len = stack_len(&a_head);
	i = 0;
	while (i < len)
	{
		printf("[%d] ", sorted_arr[i]);
		i++;
	}
	printf("\n");
	free(sorted_arr);
	deallocate_stack(&a_head, &a_tail);
	return (0);
}
