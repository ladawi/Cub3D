/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:28:08 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:53:44 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char		*check_map(t_data *data)
{
	int	p;
	int u;
	int i;

	i = 0;
	p = -1;
	u = -1;
	while (++p < data->mapcarac.maxheight && !data->error)
	{
		while (++u < data->mapcarac.maxwidth && !data->error)
		{
			data->error = check_map2(data, p, u, i);
			data->error = check_map3(data, p, u, i);
			i = 0;
		}
		u = -1;
	}
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

char		*get_map_heart(t_data *data, char *line)
{
	int		i;

	i = 0;
	if (data->config.y >= data->mapcarac.maxwidth
		|| data->config.l >= data->mapcarac.maxheight)
		return ("error mapcarac");
	while (line[i] != 0 && line != 0)
	{
		get_map_heart_2(data, line, i);
		data->config.y++;
		i++;
	}
	data->str[data->config.y] = 0;
	return (0);
}

char		*get_specs_map(t_data *data, char *line)
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
		data->mapcarac.maxwidth = (ft_strlen(data->line2)
			> data->mapcarac.maxwidth) ? ft_strlen(data->line2)
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

char		*get_map(t_data *data, char *line)
{
	int		ret;

	ret = -1;
	get_specs_map(data, line);
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
		if ((data->error = get_map_heart(data, line)) != 0)
		{
			free(line);
			*line = 0;
			return (data->error);
		}
		data->config.l++;
		free(line);
		*line = 0;
	}
	return (get_map_2(data));
}
