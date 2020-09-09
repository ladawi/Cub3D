/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:28:08 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/09 15:57:53 by ladawi           ###   ########.fr       */
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
	return (data->error);
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
		data->error = "Wrong carac in map";
	return (data->error);
}

char		*get_map_heart(t_data *data, char *line)
{
	int		i;

	i = 0;
	if (data->config.y >= data->mapcarac.maxwidth
		|| data->config.l >= data->mapcarac.maxheight)
		return ("error mapcarac");
	while (line[i] != 0 && line != 0)
	{
		data->error = get_map_heart_2(data, line, i);
		data->config.y++;
		i++;
	}
	data->str[data->config.y] = 0;
	return (data->error);
}

char		*get_specs_map(t_data *data)
{
	int		ret;
	char	*tofree;

	ret = -1;
	if (ft_strlen(data->line2) > 0)
		data->mapcarac.maxwidth = ft_strlen(data->line2);
	data->mapcarac.maxheight = 1;
	while (ret != 0
		&& ft_strncmp(data->line2, "\n", ft_strlen(data->line2) != 0))
	{
		tofree = data->line2;
		ret = get_next_line(data->fd2, &data->line2);
		data->mapcarac.maxwidth = ((int)(ft_strlen(data->line2))
			> data->mapcarac.maxwidth) ? (int)(ft_strlen(data->line2))
				: data->mapcarac.maxwidth;
		data->mapcarac.maxheight++;
		if (tofree)
		{
			free(tofree);
			tofree = NULL;
		}
	}
	return (0);
}
