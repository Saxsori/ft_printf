/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:55:18 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/06 18:53:45 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		printnbr(int nbr);
int		printunbr(unsigned int nbr);
int		printchar(int c);
int		printstr(char *string);
int		printhex(unsigned int h, int type);
int		printlen(va_list ap, const char *string);
int		printptr(unsigned long long ptr);
int		format(va_list ap, char form);
char	*ft_itoa(int n, int op);
int		ft_printf(const char *string, ...);

#endif
