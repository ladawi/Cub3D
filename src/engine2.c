/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:38:01 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/04 18:10:25 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void		ft_rotate_player(data_t *data, double angle)
{
	double olddirx;
	double oldplanex;

	olddirx = data->game.dDirX;
	oldplanex = data->game.dPlaneX;
	data->game.dDirX = data->game.dDirX
		* cos(angle) - data->game.dDirY * sin(angle);
	data->game.dDirY = olddirx * sin(angle) + data->game.dDirY * cos(angle);
	data->game.dPlaneX = data->game.dPlaneX
		* cos(angle) - data->game.dPlaneY * sin(angle);
	data->game.dPlaneY = oldplanex
		* sin(angle) + data->game.dPlaneY * cos(angle);
}

char		*check_map2(data_t *data, int p, int u, int i)
{
	if (p == 0 && ft_findchar(data->map[p][u], "1 ") == 0
		&& u < ft_strlen(data->map[0]))
		return ("Wall Error North");
	if (p == data->Map.MaxHeight - 1 && ft_findchar(data->map[p][u], "1 ") == 0
		&& u < ft_strlen(data->map[data->Map.MaxHeight - 1]))
		return ("Wall Error South");
	if (ft_findchar(data->map[p][u], "2") != 0)
	{
		data->Sprites.SpritesPos[data->Config.indexSprite].x = u + 0.5;
		data->Sprites.SpritesPos[data->Config.indexSprite].y = p + 0.5;
		data->Config.indexSprite++;
	}
	return (0);
}

char		*check_map3(data_t *data, int p, int u, int i)
{
	while (ft_findchar(data->map[0 + i][u], " 02") != 0
				&& u < ft_strlen(data->map[0]) && u > 1)
	{
		if (ft_findchar(data->map[0 + i][u - 1], "1 ") != 0
			&& ft_findchar(data->map[0 + i][u + 1], "1 ") != 0)
			i++;
		else
			return ("Error : map is not closed");
	}
	i = 0;
	while (ft_findchar(data->map[data->Map.MaxHeight - 1 - i][u], " 02")
		!= 0 && u < ft_strlen(data->map[data->Map.MaxHeight - 1])
			&& u > 1)
	{
		if (ft_findchar(data->map[data->Map.MaxHeight - 1 - i][u - 1]
			, "1 ") != 0 && ft_findchar(data->map
				[data->Map.MaxHeight - 1 - i][u + 1], "1 ") != 0)
			i++;
		else
			return ("Error : map is not closed");
	}
	return (0);
}
