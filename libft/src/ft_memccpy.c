/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:35:17 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:24:00 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		if (*(unsigned char*)(src + i) == (unsigned char)c)
			return ((dst + i + 1));
		i++;
	}
	return (0);
}
