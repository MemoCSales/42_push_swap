/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:39:38 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/17 19:47:25 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = malloc(count * size);
	i = 0;
	if (!(tmp))
		return (NULL);
	while (i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
