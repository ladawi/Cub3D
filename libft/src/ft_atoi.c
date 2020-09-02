/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:01:17 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:24:16 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while ((*str == 32 || (*str >= 9 && *str <= 13)) && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb * sign);
}
