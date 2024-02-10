/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:10:56 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/17 19:50:04 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*subs;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if (len > start + slen)
		len = start + slen;
	subs = (char *) malloc((len + 1) * sizeof(char));
	if (!(subs))
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
