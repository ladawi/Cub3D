/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:57 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/29 15:20:17 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	update_window(data_t *data)
{
	if (data->mlx_win != 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->sImg.img, 0, 0);
}
