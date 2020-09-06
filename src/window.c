/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:57 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:43:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	update_window(t_data *data)
{
	if (data->mlx_win != 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->simg.img, 0, 0);
}

int		exitwindow(t_data *data)
{
	freeall(data);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(1);
	return (0);
}
