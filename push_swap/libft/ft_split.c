/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:18:48 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/06 19:26:43 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, char chr)
{
	size_t	word;
	size_t	i;

	if (!str)
		return (0);
	word = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 || str[i -1] == chr) && str[i] != chr)
			word++;
		i++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	res = (char **) malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//     {
//         printf("Usage: %s <string> <delimiter>\n", argv[0]);
//         return 1;
//     }

//     const char *input_str = argv[1];
//     char delimiter = argv[2][0];

//     char **result = ft_split(input_str, delimiter);

//     if (!result)
//     {
//         printf("Error splitting the string.\n");
//         return 1;
//     }

//     printf("Words after splitting:\n");
//     for (int i = 0; result[i] != NULL; ++i)
//     {
//         printf("%s\n", result[i]);
//         free(result[i]); // Free each allocated word
//     }

//     free(result); // Free the array of words

//     return 0;
// }
