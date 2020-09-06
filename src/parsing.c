/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:10:25 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 14:59:54 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char			*parsing(data_t *data, texture_t *textures, char *line)
{
	if (ft_strnstr(data->idparsing, "R", 0) != 0)
		data->Error = get_resolution(data, line);
	else if (ft_strnstr(data->idparsing, "NO", 0) != 0)
		data->Error = get_texture_wall(data, line, NORTH);
	else if (ft_strnstr(data->idparsing, "SO", 0) != 0)
		data->Error = get_texture_wall(data, line, SOUTH);
	else if (ft_strnstr(data->idparsing, "WE", 0) != 0)
		data->Error = get_texture_wall(data, line, WEST);
	else if (ft_strnstr(data->idparsing, "EA", 0) != 0)
		data->Error = get_texture_wall(data, line, EAST);
	else if (ft_strnstr(data->idparsing, "S", 0) != 0)
		data->Error = get_sprite_texture(data, line);
	else if (ft_strnstr(data->idparsing, "F", 0) != 0)
		data->Error = get_color(data, line);
	else if (ft_strnstr(data->idparsing, "C", 0) != 0)
		data->Error = get_color(data, line);
	else if (ft_strncmp(line, "\n", ft_strlen(line)) != 0)
		data->Error = get_map(data, line);
	else
	{
		free(line);
		*line = 0;
	}
	(*line) ? free(line) : 0;
	return (data->Error);
}
