/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:18:27 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:23:56 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int a;

	if (n < 0)
	{
		write(fd, "-", 1);
		a = -n;
	}
	else
		a = n;
	if (a > 9)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd(a % 10 + 48, fd);
}
