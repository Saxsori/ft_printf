/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:45:38 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/06 18:56:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list ap, const char form)
{
	int	len;

	len = 0;
	if (form == 'c')
		len = printchar(va_arg(ap, int));
	else if (form == 's')
		len = printstr(va_arg(ap, char *));
	else if (form == 'p')
		len = printptr(va_arg(ap, unsigned long long));
	else if (form == 'd' || form == 'i')
		len = printnbr(va_arg(ap, int));
	else if (form == 'u')
		len = printunbr(va_arg(ap, unsigned int));
	else if (form == 'x')
		len = printhex(va_arg(ap, unsigned int), 1);
	else if (form == 'X')
		len = printhex(va_arg(ap, unsigned int), 2);
	else if (form == '%')
		len = printchar('%');
	return (len);
}

int	printlen(va_list ap, const char *string)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			len = len + format(ap, string[i + 1]);
			i++;
		}
		else
			len = len + printchar(string[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, string);
	len = printlen(ap, string);
	va_end(ap);
	return (len);
}
