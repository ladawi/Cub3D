/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:18:17 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:24:14 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		ft_intlen(long int nb)
{
	int				len;
	long int		i;

	i = (nb >= 0) ? 1 : -1;
	len = 0;
	if (nb >= 0)
	{
		while (nb > i - 1)
		{
			i = i * 10;
			len++;
		}
	}
	if (nb < 0)
	{
		while (nb < i + 1)
		{
			i *= 10;
			len++;
		}
	}
	len = (len == 0) ? 1 : len;
	return (len);
}
