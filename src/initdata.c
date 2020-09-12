/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:47:36 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/12 16:48:46 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		initdata_game(t_data *data)
{
	data->game.prevpos = '0';
	data->game.fplayerx = 0;
	data->game.fplayery = 0;
	data->game.frotaleft = 0;
	data->game.frotaright = 0;
	data->game.fvbackward = 0;
	data->game.fvforward = 0;
	data->game.fstrafeleft = 0;
	data->game.fstraferight = 0;
	data->game.ddirx = -1;
	data->game.ddiry = 0;
	data->game.dplanex = 0;
	data->game.dplaney = 0.66;
}

char		*initparsingcheck(t_data *data)
{
	data->parsing.no = 0;
	data->parsing.so = 0;
	data->parsing.we = 0;
	data->parsing.ea = 0;
	data->parsing.r = 0;
	data->parsing.s = 0;
	data->parsing.f = 0;
	data->parsing.c = 0;
	return (0);
}

char		*initdata(t_data *data, char *pathconfig)
{
	data->error = 0;
	data->res_width = -1;
	data->res_height = -1;
	data->idparsing = 0;
	data->max_res_width = 0;
	data->max_res_height = 0;
	data->mlx_win = 0;
	mlx_get_screen_size(data->mlx_ptr,
		&data->max_res_width, &data->max_res_height);
	data->fd = open(pathconfig, O_RDONLY);
	data->fd2 = open(pathconfig, O_RDONLY);
	data->config.l = 0;
	data->config.y = 0;
	data->config.indexsprite = 0;
	data->ray.time_elapsed = 0.03;
	data->ray.mapx = 0;
	data->ray.mapy = 0;
	if (data->fd < 0 || data->fd2 < 0)
		return ("Wrong .cub file");
	data->sprites.numsprites = 0;
	initdata_game(data);
	initparsingcheck(data);
	return (0);
}
