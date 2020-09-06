/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:52:22 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 12:20:23 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int		ft_draw_pixel_map(data_t *data, int x, int y, char c)
{
	if (c == '1')
		data->sImg.str[x + (data->sImg.size_line * y)] = 1264551;
	else if (c == '0')
		data->sImg.str[x + (data->sImg.size_line * y)] = 16777215;
	else if (ft_findchar(c, "PNSEW") != 0)
		data->sImg.str[x + (data->sImg.size_line * y)] = 16711680;
	else if (c == '2')
		data->sImg.str[x + (data->sImg.size_line * y)] = 9849600;
	return (0);
}

int		ft_minimap_2(data_t *data)
{
	while (data->Minimap.mapy < data->Map.MaxWidth)
	{
		while (data->Minimap.mapx < data->Map.MaxHeight)
		{
			if (data->Minimap.x < data->res_width
				&& data->Minimap.y < data->res_height)
			{
				ft_draw_pixel_map(data, data->Minimap.x, data->Minimap.y,
					data->map[data->Minimap.mapx][data->Minimap.mapy]);
			}
			data->Minimap.y++;
			if (data->Minimap.y % data->Minimap.scaley == 0)
				data->Minimap.mapx++;
		}
		data->Minimap.y = 0;
		data->Minimap.x++;
		data->Minimap.mapx = 0;
		if (data->Minimap.x % data->Minimap.scalex == 0)
			data->Minimap.mapy++;
	}
	return (0);
}

int		ft_minimap(data_t *data)
{
	data->Minimap.mapx = 0;
	data->Minimap.mapy = 0;
	data->Minimap.x = 0;
	data->Minimap.y = 0;
	data->Minimap.scalex = (int)(data->res_width / 100);
	data->Minimap.scaley = (int)(data->res_height / 100);
	(data->Minimap.scalex < 1) ? data->Minimap.scalex = 1 : 0;
	(data->Minimap.scaley < 1) ? data->Minimap.scaley = 1 : 0;
	ft_minimap_2(data);
	return (0);
}
