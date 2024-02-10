/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:43:46 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/14 21:04:32 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ilen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	else if (n < 0)
	{
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	count_zeros(int n)
{
	int		len;
	int		temp;
	int		i;

	len = ft_ilen(n);
	i = 1;
	temp = 1;
	while (len > 1)
	{
		temp = i * 10;
		i = temp;
		len--;
	}
	return (temp);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;
	int		temp;
	int		len;

	len = ft_ilen(n);
	num = n;
	temp = count_zeros(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	while (len != 0)
	{
		c = (num / temp) % 10 + 48;
		ft_putchar_fd(c, fd);
		temp = temp / 10;
		len--;
	}
}
