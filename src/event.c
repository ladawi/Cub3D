/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:24:15 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/15 14:09:06 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keypress(int keycode, t_data *data)
{
	(keycode == KEY_ESC) ? exitwindow(data) : 0;
	if (keycode == KEY_A)
		data->game.fstrafeleft = 4.923847658236450892f;
	if (keycode == KEY_D)
		data->game.fstraferight = 4.923847658236450892f;
	if (keycode == KEY_W)
		data->game.fvforward = 4.923847658236450892f;
	if (keycode == KEY_S)
		data->game.fvbackward = 4.923847658236450892f;
	if (keycode == KEY_UP)
		data->issou_up = 15;
	if (keycode == KEY_DOWN)
		data->issou_down = 15;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		data->game.frotaleft = -M_PI;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		data->game.frotaright = M_PI;
	if (keycode == KEY_SPACE)
		data->jump = -1 * (data->issou / 2);
	return (0);
}

void	freeall(t_data *data)
{
	int i;

	i = -1;
	if (data->line2)
	{
		free(data->line2);
		data->line2 = 0;
	}
	while (++i < data->config.l)
	{
		if (data->map[i])
		{
			free(data->map[i]);
			data->map[i] = 0;
		}
	}
	free(data->sprites.spritespos);
}

int		keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_A)
		data->game.fstrafeleft = 0;
	if (keycode == KEY_D)
		data->game.fstraferight = 0;
	if (keycode == KEY_UP)
		data->issou_up = 0;
	if (keycode == KEY_DOWN)
		data->issou_down = 0;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		data->game.frotaleft = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		data->game.frotaright = 0;
	if (keycode == KEY_W)
		data->game.fvforward = 0;
	if (keycode == KEY_S)
		data->game.fvbackward = 0;
	if (keycode == KEY_SPACE)
		data->jump = 0;
	return (0);
}
