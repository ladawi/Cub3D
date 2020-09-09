/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:04:29 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/09 13:23:43 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*get_map_heart_3(t_data *data, char *line, int i)
{
	if (ft_findchar(line[i], "N") != 0)
		ft_rotate_player(data, M_PI_2);
	if (ft_findchar(line[i], "E") != 0)
		ft_rotate_player(data, M_PI);
	if (ft_findchar(line[i], "S") != 0)
		ft_rotate_player(data, M_PI_2 * 3);
	data->game.fplayerx = i + 0.5;
	data->game.fplayery = data->config.l + 0.5;
	data->player.x = i;
	data->player.y = data->config.l;
}

char		*get_map_heart_2(t_data *data, char *line, int i)
{
	if (ft_findchar(line[i], "012NSEW ") != 0)
	{
		if (ft_findchar(line[i], "NSEW") != 0)
		{
			if (data->game.fplayerx == 0 && data->game.fplayery == 0)
			{
				get_map_heart_3(data, line, i);
			}
			else
				return ("error to many spawn");
		}
		if (ft_findchar(line[i], "2") != 0)
			data->sprites.numsprites++;
		data->str[data->config.y] = line[i];
	}
	else
		data->error = "Wrong carac in map\n";
	return (data->error);
}

char		*get_map_2(t_data *data)
{
	if (!(data->sprites.spritespos =
		ft_calloc((data->sprites.numsprites + 1), sizeof(t_sprit))))
		return ("a malloc derped\n");
	if (data->game.fplayerx == 0 && data->game.fplayery == 0)
		return ("No spawn placed\n");
	data->game.nmapwidth = data->config.y;
	data->game.nmapheight = data->config.l;
	data->error = check_map(data);
	if (data->error == 0)
		data->error = check_map_2(data);
	return (data->error);
}

char		*get_map_3(t_data *data, char *line)
{
	if ((data->error = get_map_heart(data, line)) != 0)
	{
		free(line);
		*line = 0;
		return (data->error);
	}
	if (data->config.l != 0)
	{
		free(line);
		line = 0;
	}
	return (data->error);
}
