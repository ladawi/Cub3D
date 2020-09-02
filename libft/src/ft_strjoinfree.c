/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:47:16 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:23:49 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strjoinfree(char const *s1, char *s2, int nb)
{
	char	*str;
	char	*to_free1;
	char	*to_free2;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0)
		return (NULL);
	to_free1 = (char *)s1;
	to_free2 = (char *)s2;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char*)malloc(len_s1 + len_s2 + 1)))
		return (0);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + ft_strlen(s1), s2, len_s2 + 1);
	if (to_free1 && (nb == 0 || nb == 2) && nb != -1)
		free(to_free1);
	if (to_free2 && (nb == 1 || nb == 2) && nb != -1)
		free(to_free2);
	to_free1 = 0;
	to_free2 = 0;
	return (str);
}
