/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printxsc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:12:56 by aaljaber          #+#    #+#             */
/*   Updated: 2021/11/10 21:08:22 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthex(unsigned int h, int type)
{
	if (h > 15)
	{
		puthex(h / 16, type);
		puthex(h % 16, type);
	}
	else
	{
		if (h <= 9)
			printchar(h + '0');
		else
		{
			if (type == 1)
				printchar(h - 10 + 'a');
			if (type == 2)
				printchar(h - 10 + 'A');
		}
	}
}

static int	hexlen(unsigned int h)
{
	int	len;

	len = 0;
	while (h != 0)
	{
		len++;
		h = h / 16;
	}
	return (len);
}

int	printhex(unsigned int h, int type)
{
	if (h == 0)
	{
		printchar('0');
		return (1);
	}
	else
	{
		puthex(h, type);
		return (hexlen(h));
	}
}

int	printstr(char *string)
{
	int		i;
	char	*n;

	i = 0;
	n = "(null)";
	if (string == NULL)
	{
		while (n[i])
		{
			write(1, &n[i], 1);
			i++;
		}
		return (i);
	}
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}

int	printchar(int c)
{
	write (1, &c, 1);
	return (1);
}
