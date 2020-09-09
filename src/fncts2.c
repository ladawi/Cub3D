/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:04:29 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/09 16:15:10 by ladawi           ###   ########.fr       */
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
			data->error = check_map3(data, u, i);
			i = 0;
		}
		u = -1;
	}
	if (data->error == 0)
		data->error = check_spawn(data);
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
			if (ft_findchar(data->map[y][x], "02") != 0)
			{
				if (y > 0 && ft_findchar(data->map[y - 1][x], "012NSEW") == 0)
					return ("Invalid mapcarac");
				if (y < data->mapcarac.maxheight
					&& ft_findchar(data->map[y + 1][x], "012NSEW") == 0)
					return ("Invalid mapcarac");
				if (x > 0 && ft_findchar(data->map[y][x - 1], "012NSEW") == 0)
					return ("Invalid mapcarac");
				if (x < data->mapcarac.maxwidth
					&& ft_findchar(data->map[y][x + 1], "012NSEW") == 0)
					return ("Invalid mapcarac");
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
		data->map[data->config.l] = data->str;
		data->error = get_map_3(data, line);
		data->config.l++;
	}
	return (get_map_2(data));
}
