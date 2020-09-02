/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:38:01 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/26 15:01:03 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

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

char		*get_color2(data_t *data, char *line, unsigned int tab[3])
{
	if (tab[0] > 255 || tab[0] < 0)
		return ("\033[1;91mRed color in floor or Ceiling not valid\n");
	if (tab[1] > 255 || tab[1] < 0)
		return ("\033[1;92mGreen color in floor or Ceiling not valid\n");
	if (tab[2] > 255 || tab[2] < 0)
		return ("\033[1;34mBlue color in floor or Ceiling not valid\n");
	tab[0] = tab[0] << 16;
	tab[1] = tab[1] << 8;
	if (ft_strnstr(data->idparsing, "F", 0) != 0)
		data->F_color = tab[0] + tab[1] + tab[2];
	else if (ft_strnstr(data->idparsing, "C", 0) != 0)
		data->C_color = tab[0] + tab[1] + tab[2];
	return (0);
}

char		*get_color(data_t *data, char *line)
{
	unsigned int		tab[3];
	int					i;

	i = -1;
	line += 1;
	while (line[++i] != 0)
		if (ft_isdigit(line[i]) != 1 && line[i] != ',' && line[i] != ' ')
			return ("Wrong color input");
	while (*line == ' ')
		line++;
	tab[0] = atoi(line);
	while (*line != ',' && *line != 0)
		line++;
	if (*line == 0)
		return ("Wrong color input");
	line++;
	tab[1] = atoi(line);
	while (*line != ',' && *line != 0)
		line++;
	if (*line == 0)
		return ("Wrong color input");
	line++;
	tab[2] = atoi(line);
	get_color2(data, line, tab);
	return (0);
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
