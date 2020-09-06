/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:28:08 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 12:27:54 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char		*check_map(data_t *data)
{
	int	p;
	int u;
	int i;

	i = 0;
	p = -1;
	u = -1;
	while (++p < data->Map.MaxHeight && !data->Error)
	{
		while (++u < data->Map.MaxWidth && !data->Error)
		{
			data->Error = check_map2(data, p, u, i);
			data->Error = check_map3(data, p, u, i);
			i = 0;
		}
		u = -1;
	}
	return (data->Error);
}

char		*check_map_2(data_t *data)
{
	int	y;
	int x;

	y = -1;
	while (++y < data->Map.MaxHeight)
	{
		x = -1;
		while (++x < data->Map.MaxWidth)
		{
			if (ft_findchar(data->map[y][x], "02") != 0)
			{
				if (y > 0 && ft_findchar(data->map[y - 1][x], "012NSEW") == 0)
					return ("Invalid Map");
				if (y < data->Map.MaxHeight
					&& ft_findchar(data->map[y + 1][x], "012NSEW") == 0)
					return ("Invalid Map");
				if (x > 0 && ft_findchar(data->map[y][x - 1], "012NSEW") == 0)
					return ("Invalid Map");
				if (x < data->Map.MaxWidth
					&& ft_findchar(data->map[y][x + 1], "012NSEW") == 0)
					return ("Invalid Map");
			}
		}
	}
	return (0);
}

char		*get_map_heart(data_t *data, char *line)
{
	int		i;

	i = 0;
	if (data->Config.y >= data->Map.MaxWidth
		|| data->Config.l >= data->Map.MaxHeight)
		return ("Error Map");
	while (line[i] != 0 && line != 0)
	{
		get_map_heart_2(data, line, i);
		data->Config.y++;
		i++;
	}
	data->test[data->Config.y] = 0;
	return (0);
}

char		*get_specs_map(data_t *data, char *line)
{
	int		ret;
	char	*tofree;

	ret = -1;
	if (ft_strlen(data->line2) > 0)
		data->Map.MaxWidth = ft_strlen(data->line2);
	data->Map.MaxHeight = 1;
	while (ret != 0
		&& ft_strncmp(data->line2, "\n", ft_strlen(data->line2) != 0))
	{
		tofree = data->line2;
		ret = get_next_line(data->fd2, &data->line2);
		data->Map.MaxWidth = (ft_strlen(data->line2) > data->Map.MaxWidth)
			? ft_strlen(data->line2) : data->Map.MaxWidth;
		data->Map.MaxHeight++;
		if (tofree)
		{
			free(tofree);
			tofree = NULL;
		}
	}
	return (0);
}

char		*get_map(data_t *data, char *line)
{
	int		ret;

	ret = -1;
	get_specs_map(data, line);
	if (!(data->map = ft_calloc(data->Map.MaxHeight + 1, sizeof(char *))))
		return ("A malloc derped\n");
	while (ret != 0)
	{
		data->Config.y = 0;
		if (data->Config.l != 0)
			ret = get_next_line(data->fd, &line);
		if (!(data->test = ft_calloc(data->Map.MaxWidth + 1, sizeof(char))))
			return ("A malloc derped\n");
		data->map[data->Config.l] = data->test;
		if ((data->Error = get_map_heart(data, line)) != 0)
		{
			free(line);
			*line = 0;
			return (data->Error);
		}
		data->Config.l++;
		free(line);
		*line = 0;
	}
	return (get_map_2(data));
}
