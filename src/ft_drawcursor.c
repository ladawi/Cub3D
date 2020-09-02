/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawcursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:26:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/25 16:09:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void		drawcursor(data_t *data)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < data->res_width)
	{
		while (++y < data->res_height)
		{
			if ((y > (data->res_height / 2) - 2
				&& y < (data->res_height / 2) + 2) && (x > (data->res_width / 2)
					- 10 && x < (data->res_width / 2) + 10))
				data->sImg.str[x + (data->sImg.size_line * y)] = ~data->
					sImg.str[x + (data->sImg.size_line * y)] & 0xffffff;
			if ((x > (data->res_width / 2) - 2
				&& x < (data->res_width / 2) + 2) && (y > (data->res_height / 2)
					- 10 && y < (data->res_height / 2) + 10))
				data->sImg.str[x + (data->sImg.size_line * y)] = ~data->
					sImg.str[x + (data->sImg.size_line * y)] & 0xffffff;
		}
		y = -1;
	}
}
