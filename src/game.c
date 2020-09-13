/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:54:01 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/13 18:48:29 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_putpixel(t_data *data, int side, int x, int y)
{
	data->ray.texy = (y - data->ray.drawstart)
		* data->tex.tex[side].height / data->ray.lineheight;
	data->ray.color = data->tex.tex[side].str[data->tex.tex[side].height
		* data->ray.texy + data->ray.texx];
	data->simg.str[x + (data->simg.size_line * y)] = shade_color(data->ray.color, data->ray.perpwalldist / 1.5);
	// data->simg.str[x + (data->simg.size_line * y)] = data->ray.color;
}

void		wallcasting(t_data *data, int x, double *zbuffer)
{
	while (++x < data->res_width)
	{
		gameloop2(data, x);
		gameloop3(data);
		data->ray.lineheight = (int)(data->res_height / data->ray.perpwalldist);
		data->ray.drawstart = -data->ray.lineheight / 2 + data->issou;
		data->ray.drawend = data->ray.lineheight / 2 + data->issou;
		data->ray.wallx = 0;
		if (data->ray.side == 0)
			data->ray.wallx = data->game.fplayery + data->ray.perpwalldist
				* data->ray.raydiry;
		else
			data->ray.wallx = data->game.fplayerx + data->ray.perpwalldist
				* data->ray.raydirx;
		data->ray.wallx -= floor((data->ray.wallx));
		data->ray.texx = 0;
		set_tex(data);
		draw_column(data, x);
		zbuffer[x] = data->ray.perpwalldist;
	}
}

void		player_move(t_data *data)
{
	if (data->jump != 0)
	{
		if (data->game.fstraferight == 5.0f)
			data->game.fstraferight *= 0.5f;
		if (data->game.fstrafeleft == 5.0f)
			data->game.fstrafeleft *= 0.5f;
		if (data->game.fvforward == 5.0f)
			data->game.fvforward *= 0.5f;
		if (data->game.fvbackward == 5.0f)
			data->game.fvbackward *= 0.5f;
	}
	if (data->game.fvforward != 0)
		move_player_front(data, data->ray.time_elapsed);
	if (data->game.fvbackward != 0)
		move_player_back(data, data->ray.time_elapsed);
	if (data->game.fstrafeleft != 0)
		move_player_left(data, data->ray.time_elapsed);
	if (data->game.fstraferight != 0)
		move_player_right(data, data->ray.time_elapsed);
	if (data->game.frotaleft != 0)
		ft_rotate_player(data, data->game.frotaleft * data->ray.time_elapsed);
	if (data->game.frotaright != 0)
		ft_rotate_player(data, data->game.frotaright * data->ray.time_elapsed);
	if ((data->issou - data->issou_down) > 0)
	{
		data->issou -= data->issou_down;
		// calc_sf_dist(data->res_height , data->ray.sf_dist);
	}
	if ((data->issou + data->issou_up) < data->res_height)
	{
		data->issou += data->issou_up;
		// calc_sf_dist(data->res_height + data->issou, data->ray.sf_dist);
	}
}

int			gameloop(t_data *data)
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
	return (0);
}
