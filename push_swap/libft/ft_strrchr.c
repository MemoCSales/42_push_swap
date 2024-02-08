/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:32:29 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/06 19:27:29 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*ss;
	int		i;

	i = 0;
	ss = NULL;
	ch = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			ss = (char *) &s[i];
		i++;
	}
	if (s[i] == ch)
		return ((char *) &s[i]);
	return (ss);
}

// int main() {
//     const char *str = "Hello, World!";
//     int c = 'o';

//     char *result = ft_strrchr(str, c);

//     if (result) {
//         printf("'%c' in \"%s\" is at position: %ld\n", c, str, result - str);
//     } else {
//         printf("Character '%c' not found in \"%s\"\n", c, str);
//     }

//     return 0;
// }