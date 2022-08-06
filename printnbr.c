/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:58:22 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/06 18:53:19 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	length(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*check(char *string, long num, size_t i, int op)
{
	if (num == 0)
	{
		string[0] = '0';
		return (string);
	}
	else if (num < 0 && op == 's')
	{
		string[0] = '-';
		num = num * -1;
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

char	*ft_itoa(int n, int op)
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
	check(string, num, i, op);
	return (string);
}

int	printnbr(int nbr)
{
	char	*num;
	int		i;

	num = ft_itoa(nbr, 's');
	i = 0;
	while (num[i])
	{
		write(1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}
