/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:38:01 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/09 13:44:39 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_rotate_player(t_data *data, double angle)
{
	double olddirx;
	double oldplanex;

	olddirx = data->game.ddirx;
	oldplanex = data->game.dplanex;
	data->game.ddirx = data->game.ddirx
		* cos(angle) - data->game.ddiry * sin(angle);
	data->game.ddiry = olddirx * sin(angle) + data->game.ddiry * cos(angle);
	data->game.dplanex = data->game.dplanex
		* cos(angle) - data->game.dplaney * sin(angle);
	data->game.dplaney = oldplanex
		* sin(angle) + data->game.dplaney * cos(angle);
}

char		*check_map2(t_data *data, int p, int u, int i)
{
	if (p == 0 && ft_findchar(data->map[p][u], "1 ") == 0
		&& u < ft_strlen(data->map[0]))
		return ("Wall error North");
	if (p == data->mapcarac.maxheight - 1
		&& ft_findchar(data->map[p][u], "1 ") == 0
		&& u < ft_strlen(data->map[data->mapcarac.maxheight - 1]))
		return ("Wall error South");
	if (ft_findchar(data->map[p][u], "2") != 0)
	{
		data->sprites.spritespos[data->config.indexsprite].x = u + 0.5;
		data->sprites.spritespos[data->config.indexsprite].y = p + 0.5;
		data->config.indexsprite++;
	}
	return (0);
}

char		*check_map3(t_data *data, int p, int u, int i)
{
	while (ft_findchar(data->map[0 + i][u], " 02NSEW") != 0
				&& u < ft_strlen(data->map[0]) && u > 1)
	{
		if (ft_findchar(data->map[0 + i][u - 1], "1 ") != 0
			&& ft_findchar(data->map[0 + i][u + 1], "1 ") != 0)
			i++;
		else
			return ("map is not closed");
	}
	i = 0;
	while (ft_findchar(data->map[data->mapcarac.maxheight - 1 - i][u],
		" 02NSEW") != 0 && u <
			ft_strlen(data->map[data->mapcarac.maxheight - 1]) && u > 1)
	{
		if (ft_findchar(data->map[data->mapcarac.maxheight - 1 - i][u - 1]
			, "1 ") != 0 && ft_findchar(data->map
				[data->mapcarac.maxheight - 1 - i][u + 1], "1 ") != 0)
			i++;
		else
			return ("map is not closed");
	}
	return (0);
}
