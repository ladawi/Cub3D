/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:28:23 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:24:43 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_gnlstrlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_gnlstrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_gnlmemcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_gnlstrjoin(char const *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0)
		return (NULL);
	len_s1 = ft_gnlstrlen(s1);
	len_s2 = ft_gnlstrlen(s2);
	if (!(str = (char*)malloc(len_s1 + len_s2 + 1)))
		return (0);
	ft_gnlmemcpy(str, s1, len_s1);
	ft_gnlmemcpy(str + ft_gnlstrlen(s1), s2, len_s2 + 1);
	free((void*)s1);
	return (str);
}

char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_gnlstrlen(s))
		return (str);
	if (start + len > ft_gnlstrlen(s))
		len = ft_gnlstrlen(s) - start;
	ft_gnlmemcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
