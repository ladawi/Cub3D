/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:39:47 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:24:12 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char			*ft_itoa_base(int n, long long int base)
{
	long long int	i;
	int				neg;
	char			*nbr;

	i = 1;
	neg = 0;
	if (n < 0)
	{
		if (base == 10)
			neg = 1;
		n = -n;
	}
	while (ft_pow(base, i) - 1 < n)
		i++;
	if (!(nbr = (char*)malloc(sizeof(char) * (i + neg + 1))))
		return (0);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (n % base) + (n % base > 9 ? 'a' - 10 : '0');
		n = n / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
