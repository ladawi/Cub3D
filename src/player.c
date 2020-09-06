/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:15:34 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 16:36:47 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void		move_player_front(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx + data->game.dDirX *
			(data->game.fvforward * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayerx += data->game.dDirX * data->game.fvforward
			* time_elapsed;
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery + data->game.dDirY *
		(data->game.fvforward * time_elapsed))]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayery += data->game.dDirY * data->game.fvforward
			* time_elapsed;
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
}

void		move_player_back(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx - data->game.dDirX *
			(data->game.fvbackward * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayerx -= data->game.dDirX *
			(data->game.fvbackward * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery - data->game.dDirY *
		data->game.fvbackward * time_elapsed)]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayery -= data->game.dDirY *
			(data->game.fvbackward * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
}

void		move_player_left(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx + data->game.dDirY *
			(data->game.fstrafeleft * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayerx += data->game.dDirY *
			(data->game.fstrafeleft * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery + -data->game.dDirX *
		(data->game.fstrafeleft * time_elapsed))]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayery += -data->game.dDirX *
			(data->game.fstrafeleft * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = 'P';
	}
}

void		move_player_right(data_t *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx + -data->game.dDirY *
			(data->game.fstraferight * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayerx += -data->game.dDirY *
			(data->game.fstraferight * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery + data->game.dDirX *
		(data->game.fstraferight * time_elapsed))]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.PrevPos;
		data->game.fplayery += data->game.dDirX *
			(data->game.fstraferight * time_elapsed);
		data->game.PrevPos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
}
