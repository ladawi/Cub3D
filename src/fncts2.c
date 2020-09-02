/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:04:29 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/01 18:33:00 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

char		*get_map_heart_2(data_t *data, char *line, int i)
{
	if (ft_findchar(line[i], "012NSEW ") != 0)
	{
		if (ft_findchar(line[i], "NSEW") != 0)
		{
			if (data->game.fPlayerX == 0 && data->game.fPlayerY == 0)
			{
				if (ft_findchar(line[i], "N") != 0)
					ft_rotate_player(data, M_PI_2);
				if (ft_findchar(line[i], "E") != 0)
					ft_rotate_player(data, M_PI);
				if (ft_findchar(line[i], "S") != 0)
					ft_rotate_player(data, M_PI_2 * 3);
				data->game.fPlayerX = i + 0.5;
				data->game.fPlayerY = data->Config.l + 0.5;
			}
			else
				data->Error = "Error to many spawn\n";
		}
		if (ft_findchar(line[i], "2") != 0)
			data->Sprites.numSprites++;
		data->test[data->Config.y] = line[i];
	}
	else
		data->Error = "Wrong carac in map\n";
	return (data->Error);
}

char		*get_map_2(data_t *data)
{
	int i = -1;
	int y = -1;
	if (!(data->Sprites.SpritesPos =
		ft_calloc((data->Sprites.numSprites + 1), sizeof(Sprit_t))))
		return ("a malloc derped\n");
	if (data->game.fPlayerX == 0 && data->game.fPlayerY == 0)
		return ("No spawn placed\n");
	data->game.nMapWidth = data->Config.y;
	data->game.nMapHeight = data->Config.l;
	while (++i < data->Map.MaxHeight)
	{
		while (++y < data->Map.MaxWidth)
		{
			printf("%c", data->map[i][y]);

		}
		y = -1;
		printf("\n");
	}
	data->Error = check_map(data);
	data->Error = check_map_2(data);
	return (data->Error);
}
