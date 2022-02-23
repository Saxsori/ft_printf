/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:10:06 by aaljaber          #+#    #+#             */
/*   Updated: 2021/11/07 20:11:36 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	length(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*check(char *string, long num, size_t i)
{
	if (num == 0)
	{
		string[0] = '0';
		return (string);
	}
	string[i--] = '\0';
	while (num > 0)
	{
		string[i] = 48 + (num % 10);
		num /= 10;
		i--;
	}
	return (string);
}

static char	*ft_itoa(unsigned int n)
{
	char	*string;
	long	num;
	size_t	i;

	if (n == 0)
	{
		string = (char *)malloc(sizeof(char) * 2);
		if (!string)
			return (NULL);
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	num = n;
	i = length(num);
	string = (char *)malloc(sizeof(char) * i + 1);
	if (!string)
		return (NULL);
	check(string, num, i);
	return (string);
}

int	printunbr(unsigned int nbr)
{
	char	*num;
	int		i;

	num = ft_itoa(nbr);
	i = 0;
	while (num[i])
	{
		write(1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}
