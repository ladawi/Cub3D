/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:47:36 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/27 16:03:48 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void		initdata_game(data_t *data)
{
	data->game.PrevPos = '0';
	data->game.fPlayerX = 0;
	data->game.fPlayerY = 0;
	data->game.fRotaLeft = 0;
	data->game.fRotaRight = 0;
	data->game.fVbackward = 0;
	data->game.fVforward = 0;
	data->game.fStrafeLeft = 0;
	data->game.fStrafeRight = 0;
	data->game.dDirX = -1;
	data->game.dDirY = 0;
	data->game.dPlaneX = 0;
	data->game.dPlaneY = 0.66;
}

char		*initdata(data_t *data, texture_t *textures, char *pathconfig)
{
	data->Error = 0;
	data->res_width = -1;
	data->res_height = -1;
	data->idparsing = 0;
	data->max_res_width = 2560;
	data->max_res_height = 1440;
	data->fd = open(pathconfig, O_RDONLY);
	data->fd2 = open(pathconfig, O_RDONLY);
	data->Config.l = 0;
	data->Config.y = 0;
	data->Config.indexSprite = 0;
	data->ray.time_elapsed = 0.03;
	data->ray.mapx = 0;
	data->ray.mapy = 0;
	if (data->fd < 0 || data->fd2 < 0)
		return ("Wrong .cub file");
	data->Sprites.numSprites = 0;
	initdata_game(data);
	return (0);
}
