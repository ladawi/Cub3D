/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:08:43 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:23:45 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	int		slen;
	char	*ptr;

	slen = ft_strlen(s) + 1;
	if (!(ptr = malloc(n + 1)))
		return (NULL);
	ptr[n + 1] = 0;
	ft_memcpy(ptr, s, n);
	return (ptr);
}
