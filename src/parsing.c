/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:10:25 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/15 13:59:25 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			*parsing(t_data *data, char *line)
{
	if (ft_strnstr(data->idparsing, "R", 0) != 0)
		data->error = get_resolution(data, line);
	else if (ft_strnstr(data->idparsing, "NO", 0) != 0)
		data->error = get_texture_wall(data, line, NORTH);
	else if (ft_strnstr(data->idparsing, "SO", 0) != 0)
		data->error = get_texture_wall(data, line, SOUTH);
	else if (ft_strnstr(data->idparsing, "WE", 0) != 0)
		data->error = get_texture_wall(data, line, WEST);
	else if (ft_strnstr(data->idparsing, "EA", 0) != 0)
		data->error = get_texture_wall(data, line, EAST);
	else if (ft_strnstr(data->idparsing, "S", 0) != 0)
		data->error = get_sprite_texture(data, line);
	else if (ft_strnstr(data->idparsing, "F", 0) != 0)
		data->error = get_color(data, line);
	else if (ft_strnstr(data->idparsing, "C", 0) != 0)
		data->error = get_color(data, line);
	else if (ft_findchar(data->idparsing[0], " 012NSEW") != 0)
		data->error = get_map(data, line);
	else if ((int)(ft_strlen(data->idparsing) > 1))
	{
		free(line);
		return ("wrong parsing file");
	}
	(line) ? free(line) : 0;
	return (data->error);
}
