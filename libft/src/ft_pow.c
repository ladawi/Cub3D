/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:51:21 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:40:04 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_pow(long long int nb, long long int pow)
{
	if (pow == 0)
		return (1);
	return (nb * ft_pow(nb, pow - 1));
}
