/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:41 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/25 16:24:08 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!(*alst))
		*alst = new;
	else if (!(*alst)->next)
		(*alst)->next = new;
	else
		ft_lstadd_back(&((*alst)->next), new);
}
