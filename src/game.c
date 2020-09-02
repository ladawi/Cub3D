/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:54:01 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/02 12:29:11 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void		ft_putpixel(data_t *data, int side, int x, int y)
{
	data->ray.texy = (y - data->ray.drawstart)
		* data->tex.TEX[side].height / data->ray.lineheight;
	data->ray.color = data->tex.TEX[side].str[data->tex.TEX[side].height
		* data->ray.texy + data->ray.texx];
	data->sImg.str[x + (data->sImg.size_line * y)] = data->ray.color;
}

void		wallcasting(data_t *data, int x, double *zbuffer)
{
	while (++x < data->res_width)
	{
		gameloop2(data, x);
		gameloop3(data);
		data->ray.lineheight = (int)(data->res_height / data->ray.perpwalldist);
		data->ray.drawstart = -data->ray.lineheight / 2 + data->res_height / 2;
		data->ray.drawend = data->ray.lineheight / 2 + data->res_height / 2;
		data->ray.wallx = 0;
		if (data->ray.side == 0)
			data->ray.wallx = data->game.fPlayerY + data->ray.perpwalldist
				* data->ray.raydiry;
		else
			data->ray.wallx = data->game.fPlayerX + data->ray.perpwalldist
				* data->ray.raydirx;
		data->ray.wallx -= floor((data->ray.wallx));
		data->ray.texx = 0;
		set_tex(data);
		draw_column(data, x);
		zbuffer[x] = data->ray.perpwalldist;
	}
}

void		player_move(data_t *data)
{
	if (data->game.fVforward != 0)
		move_player_front(data, data->ray.time_elapsed);
	if (data->game.fVbackward != 0)
		move_player_back(data, data->ray.time_elapsed);
	if (data->game.fStrafeLeft != 0)
		move_player_left(data, data->ray.time_elapsed);
	if (data->game.fStrafeRight != 0)
		move_player_right(data, data->ray.time_elapsed);
	if (data->game.fRotaLeft != 0)
		ft_rotate_player(data, data->game.fRotaLeft * data->ray.time_elapsed);
	if (data->game.fRotaRight != 0)
		ft_rotate_player(data, data->game.fRotaRight * data->ray.time_elapsed);
}

int			gameloop(data_t *data)
{
	int		x;
	double	zbuffer[data->res_width];

	x = -1;
	wallcasting(data, x, zbuffer);
	drawsprites(data, zbuffer);
	drawcursor(data);
	player_move(data);
	ft_minimap(data);
	update_window(data);
	// exitwindow(data);
	return (0);
}
