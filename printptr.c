/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:00:39 by aaljaber          #+#    #+#             */
/*   Updated: 2021/11/07 20:08:57 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putptr(unsigned long long ptr)
{
	if (ptr > 15)
	{
		putptr(ptr / 16);
		putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			printchar(ptr + '0');
		else
			printchar(ptr - 10 + 'a');
	}
}

static int	ptrlen(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

int	printptr(unsigned long long ptr)
{
	int	len;

	write(1, "0x", 2);
	len = 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		len = len + 1;
	}
	else
	{
		putptr(ptr);
		len = len + ptrlen(ptr);
	}
	return (len);
}
