/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:04:29 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:13:33 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char		*get_map_heart_2(data_t *data, char *line, int i)
{
	if (ft_findchar(line[i], "012NSEW ") != 0)
	{
		if (ft_findchar(line[i], "NSEW") != 0)
		{
			if (data->game.fplayerx == 0 && data->game.fplayery == 0)
			{
				if (ft_findchar(line[i], "N") != 0)
					ft_rotate_player(data, M_PI_2);
				if (ft_findchar(line[i], "E") != 0)
					ft_rotate_player(data, M_PI);
				if (ft_findchar(line[i], "S") != 0)
					ft_rotate_player(data, M_PI_2 * 3);
				data->game.fplayerx = i + 0.5;
				data->game.fplayery = data->Config.l + 0.5;
			}
			else
				data->error = "error to many spawn\n";
		}
		if (ft_findchar(line[i], "2") != 0)
			data->Sprites.numSprites++;
		data->str[data->Config.y] = line[i];
	}
	else
		data->error = "Wrong carac in map\n";
	return (data->error);
}

char		*get_map_2(data_t *data)
{
	if (!(data->Sprites.SpritesPos =
		ft_calloc((data->Sprites.numSprites + 1), sizeof(Sprit_t))))
		return ("a malloc derped\n");
	if (data->game.fplayerx == 0 && data->game.fplayery == 0)
		return ("No spawn placed\n");
	data->game.nmapwidth = data->Config.y;
	data->game.nmapheight = data->Config.l;
	data->error = check_map(data);
	data->error = check_map_2(data);
	return (data->error);
}
