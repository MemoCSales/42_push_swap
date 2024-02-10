/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:58:23 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/17 19:48:36 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*temp_src;
	char		*temp_dst;

	temp_src = src;
	temp_dst = dst;
	if (temp_dst == temp_src)
		return (dst);
	if (temp_dst < temp_src || temp_dst >= temp_src + len)
	{
		while (len--)
		{
			*temp_dst++ = *temp_src++;
		}
	}
	else
	{
		temp_dst += len;
		temp_src += len;
		while (len--)
		{
			*(--temp_dst) = *(--temp_src);
		}
	}
	return (dst);
}
