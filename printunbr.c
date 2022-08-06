/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:10:06 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/06 18:52:51 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printunbr(unsigned int nbr)
{
	char	*num;
	int		i;

	num = ft_itoa(nbr, 'u');
	i = 0;
	while (num[i])
	{
		write(1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}
