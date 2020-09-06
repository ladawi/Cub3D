/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:15:34 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:43:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void		move_player_front(t_data *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx + data->game.ddirx *
			(data->game.fvforward * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayerx += data->game.ddirx * data->game.fvforward
			* time_elapsed;
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery + data->game.ddiry *
		(data->game.fvforward * time_elapsed))]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayery += data->game.ddiry * data->game.fvforward
			* time_elapsed;
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
}

void		move_player_back(t_data *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx - data->game.ddirx *
			(data->game.fvbackward * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayerx -= data->game.ddirx *
			(data->game.fvbackward * time_elapsed);
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery - data->game.ddiry *
		data->game.fvbackward * time_elapsed)]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayery -= data->game.ddiry *
			(data->game.fvbackward * time_elapsed);
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
}

void		move_player_left(t_data *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx + data->game.ddiry *
			(data->game.fstrafeleft * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayerx += data->game.ddiry *
			(data->game.fstrafeleft * time_elapsed);
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery + -data->game.ddirx *
		(data->game.fstrafeleft * time_elapsed))]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayery += -data->game.ddirx *
			(data->game.fstrafeleft * time_elapsed);
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = 'P';
	}
}

void		move_player_right(t_data *data, float time_elapsed)
{
	if (ft_findchar(data->map[(int)(data->game.fplayery)]
		[(int)(data->game.fplayerx + -data->game.ddiry *
			(data->game.fstraferight * time_elapsed))], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayerx += -data->game.ddiry *
			(data->game.fstraferight * time_elapsed);
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = 'P';
	}
	if (ft_findchar(data->map[(int)(data->game.fplayery + data->game.ddirx *
		(data->game.fstraferight * time_elapsed))]
			[(int)(data->game.fplayerx)], "123") == 0)
	{
		data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx] = data->game.prevpos;
		data->game.fplayery += data->game.ddirx *
			(data->game.fstraferight * time_elapsed);
		data->game.prevpos = data->map[(int)data->game.fplayery]
			[(int)data->game.fplayerx];
		data->map[(int)data->game.fplayery][(int)data->game.fplayerx] = 'P';
	}
}
