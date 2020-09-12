/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:30:07 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/12 20:30:57 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		checkraydir(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->game.fplayerx - data->ray.mapx)
			* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->game.fplayerx)
			* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->game.fplayery - data->ray.mapy)
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->game.fplayery)
			* data->ray.deltadisty;
	}
}

void		gameloop2(t_data *data, int x)
{
	data->ray.camerax = 2 * (data->res_width - 1 - x)
		/ (double)(data->res_width) - 1;
	data->ray.raydirx = data->game.ddirx + data->game.dplanex
		* data->ray.camerax;
	data->ray.raydiry = data->game.ddiry + data->game.dplaney
		* data->ray.camerax;
	data->ray.mapx = (int)(data->game.fplayerx);
	data->ray.mapy = (int)(data->game.fplayery);
	data->ray.deltadistx = fabs(1 / data->ray.raydirx);
	data->ray.deltadisty = fabs(1 / data->ray.raydiry);
	data->ray.hit = 0;
	checkraydir(data);
}

void		gameloop3(t_data *data)
{
	while (data->ray.hit == 0 || data->ray.hit == 2)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
		if (data->map[data->ray.mapy][data->ray.mapx] == '2')
			data->ray.hit = 2;
	}
	if (data->ray.side == 0)
		data->ray.perpwalldist = ((data->ray.mapx - data->game.fplayerx
			+ (1 - data->ray.stepx) / 2)) / data->ray.raydirx;
	else
		data->ray.perpwalldist = ((data->ray.mapy - data->game.fplayery
			+ (1 - data->ray.stepy) / 2)) / data->ray.raydiry;
}

void		set_tex(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydirx > 0)
	{
		data->ray.texx = data->tex.tex[EAST].width - data->ray.texx - 1;
		data->ray.texx = (int)(data->ray.wallx
			* (double)(data->tex.tex[EAST].width));
	}
	else if (data->ray.side == 0 && data->ray.raydirx < 0)
	{
		data->ray.texx = data->tex.tex[WEST].width - data->ray.texx - 1;
		data->ray.texx = (int)(data->ray.wallx
			* (double)(data->tex.tex[WEST].width));
	}
	else if (data->ray.side == 1 && data->ray.raydiry < 0)
	{
		data->ray.texx = data->tex.tex[NORTH].width - data->ray.texx - 1;
		data->ray.texx = (int)(data->ray.wallx
			* (double)(data->tex.tex[NORTH].width));
	}
	else if (data->ray.side == 1 && data->ray.raydiry > 0)
	{
		data->ray.texx = data->tex.tex[SOUTH].width - data->ray.texx - 1;
		data->ray.texx = (int)(data->ray.wallx
			* (double)(data->tex.tex[SOUTH].width));
	}
}

void		draw_column(t_data *data, int x)
{
	int y;

	y = -1;
	while (++y < data->res_height)
	{
		if (y <= data->ray.drawstart)
			data->simg.str[x + (data->simg.size_line * y)] = data->c_color;
		else if (y > data->ray.drawstart && y < data->ray.drawend)
		{
			if (data->ray.hit == 1 && data->ray.raydirx > 0 && !data->ray.side)
				ft_putpixel(data, EAST, x, y);
			if (data->ray.hit == 1 && data->ray.raydirx < 0 && !data->ray.side)
				ft_putpixel(data, WEST, x, y);
			if (data->ray.hit == 1 && data->ray.raydiry > 0 && data->ray.side)
				ft_putpixel(data, SOUTH, x, y);
			if (data->ray.hit == 1 && data->ray.raydiry < 0 && data->ray.side)
				ft_putpixel(data, NORTH, x, y);
		}
		else if (y >= data->ray.drawend)
			data->simg.str[x + (data->simg.size_line * y)] = data->f_color;
	}
}
