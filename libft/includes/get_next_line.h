/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:22:09 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/31 11:52:15 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

int		get_next_line(int fd, char **line);
size_t	ft_gnlstrlen(const char *s);
void	*ft_gnlmemcpy(void *dst, const void *src, size_t n);
char	*ft_gnlstrjoin(char const *s1, char *s2);
char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len);
int		ft_gnlstrchr(const char *s, int c);

#endif
