/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:04:29 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/13 16:01:56 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*check_map(t_data *data)
{
	int	p;
	int u;
	int i;

	i = 0;
	p = -1;
	u = -1;
	while (++p < data->mapcarac.maxheight)
	{
		while (++u < data->mapcarac.maxwidth)
		{
			data->error = check_map2(data, p, u);
			if (data->error != 0)
				return (data->error);
			data->error = check_map3(data, u, i);
			i = 0;
		}
		u = -1;
	}
	// if (data->error == 0)
	// 	data->error = check_close(data, data->player.x, data->player.y);
	return (data->error);
}

char		*check_map_2(t_data *data)
{
	int	y;
	int x;

	y = -1;
	while (++y < data->mapcarac.maxheight)
	{
		x = -1;
		while (++x < data->mapcarac.maxwidth)
		{
			if (ft_findchar(data->map[y][x], "0") != 0)
			{
				data->map[y][x] = '.';
				data->error = check_close(data,x, y);
				if (data->error != 0)
					return (data->error);
			}
		}
	}
	return (0);
}

char		*get_map_2(t_data *data)
{
	if (!(data->sprites.spritespos =
		ft_calloc((data->sprites.numsprites + 1), sizeof(t_sprit))))
		return ("a malloc derped");
	if (data->game.fplayerx == 0 && data->game.fplayery == 0)
		return ("No spawn placed");
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

char		*get_map(t_data *data, char *line)
{
	int		ret;

	ret = -1;
	get_specs_map(data);
	if (!(data->map = ft_calloc(data->mapcarac.maxheight + 1, sizeof(char *))))
		return ("A malloc derped\n");
	while (ret != 0)
	{
		data->config.y = 0;
		if (data->config.l != 0)
			ret = get_next_line(data->fd, &line);
		if (!(data->str = ft_calloc(data->mapcarac.maxwidth + 1, sizeof(char))))
			return ("A malloc derped\n");
		data->error = get_map_3(data, line);
		data->map[data->config.l] = data->str;
		data->config.l++;
		if (data->error != 0)
			return (data->error);
	}
	return (get_map_2(data));
}
