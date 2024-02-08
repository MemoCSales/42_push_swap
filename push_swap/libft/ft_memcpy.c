/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:59 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/17 19:48:31 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_s;

	temp_s = (unsigned char *) src;
	temp_dest = (unsigned char *) dst;
	if (n == 0)
		return (dst);
	if (src == NULL && dst == NULL)
		return (dst);
	while (n > 0)
	{
		*(temp_dest++) = *(temp_s++);
		n--;
	}
	return (dst);
}
