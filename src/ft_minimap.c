/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:52:22 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:43:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int		ft_draw_pixel_map(t_data *data, int x, int y, char c)
{
	if (c == '1')
		data->simg.str[x + (data->simg.size_line * y)] = 1264551;
	else if (c == '0')
		data->simg.str[x + (data->simg.size_line * y)] = 16777215;
	else if (ft_findchar(c, "PNSEW") != 0)
		data->simg.str[x + (data->simg.size_line * y)] = 16711680;
	else if (c == '2')
		data->simg.str[x + (data->simg.size_line * y)] = 9849600;
	return (0);
}

int		ft_minimap_2(t_data *data)
{
	while (data->minimap.mapy < data->mapcarac.maxwidth)
	{
		while (data->minimap.mapx < data->mapcarac.maxheight)
		{
			if (data->minimap.x < data->res_width
				&& data->minimap.y < data->res_height)
			{
				ft_draw_pixel_map(data, data->minimap.x, data->minimap.y,
					data->map[data->minimap.mapx][data->minimap.mapy]);
			}
			data->minimap.y++;
			if (data->minimap.y % data->minimap.scaley == 0)
				data->minimap.mapx++;
		}
		data->minimap.y = 0;
		data->minimap.x++;
		data->minimap.mapx = 0;
		if (data->minimap.x % data->minimap.scalex == 0)
			data->minimap.mapy++;
	}
	return (0);
}

int		ft_minimap(t_data *data)
{
	data->minimap.mapx = 0;
	data->minimap.mapy = 0;
	data->minimap.x = 0;
	data->minimap.y = 0;
	data->minimap.scalex = (int)(data->res_width / 100);
	data->minimap.scaley = (int)(data->res_height / 100);
	(data->minimap.scalex < 1) ? data->minimap.scalex = 1 : 0;
	(data->minimap.scaley < 1) ? data->minimap.scaley = 1 : 0;
	ft_minimap_2(data);
	return (0);
}
