/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:15:34 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/23 14:34:09 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void		move_player_front(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fPlayerY)]
		[(int)(data->game.fPlayerX + data->game.dDirX *
			(data->game.fVforward * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerX += data->game.dDirX * data->game.fVforward
			* time_elapsed;
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY][(int)data->game.fPlayerX] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fPlayerY + data->game.dDirY *
		(data->game.fVforward * time_elapsed))]
			[(int)(data->game.fPlayerX)], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerY += data->game.dDirY * data->game.fVforward
			* time_elapsed;
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY][(int)data->game.fPlayerX] = 'P';
	}
}

void		move_player_back(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fPlayerY)]
		[(int)(data->game.fPlayerX - data->game.dDirX *
			(data->game.fVbackward * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerX -= data->game.dDirX *
			(data->game.fVbackward * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fPlayerY - data->game.dDirY *
		data->game.fVbackward * time_elapsed)]
			[(int)(data->game.fPlayerX)], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerY -= data->game.dDirY *
			(data->game.fVbackward * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY][(int)data->game.fPlayerX] = 'P';
	}
}

void		move_player_left(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fPlayerY)]
		[(int)(data->game.fPlayerX + data->game.dDirY *
			(data->game.fStrafeLeft * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerX += data->game.dDirY *
			(data->game.fStrafeLeft * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY][(int)data->game.fPlayerX] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fPlayerY + -data->game.dDirX *
		(data->game.fStrafeLeft * time_elapsed))]
			[(int)(data->game.fPlayerX)], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerY += -data->game.dDirX *
			(data->game.fStrafeLeft * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = 'P';
	}
}

void		move_player_right(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fPlayerY)]
		[(int)(data->game.fPlayerX + -data->game.dDirY *
			(data->game.fStrafeRight * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerX += -data->game.dDirY *
			(data->game.fStrafeRight * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fPlayerY + data->game.dDirX *
		(data->game.fStrafeRight * time_elapsed))]
			[(int)(data->game.fPlayerX)], "123") == 0)
	{
		data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX] = data->game.PrevPos;
		data->game.fPlayerY += data->game.dDirX *
			(data->game.fStrafeRight * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fPlayerY]
			[(int)data->game.fPlayerX];
		data->map[(int)data->game.fPlayerY][(int)data->game.fPlayerX] = 'P';
	}
}
