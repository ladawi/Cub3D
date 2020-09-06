/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:51:25 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 13:54:55 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char		*get_color3(data_t *data, char *line)
{
	if (data->color.tab[0] > 255 || data->color.tab[0] < 0)
		return ("\033[1;91mRed color in floor or Ceiling not valid\n");
	if (data->color.tab[1] > 255 || data->color.tab[1] < 0)
		return ("\033[1;92mGreen color in floor or Ceiling not valid\n");
	if (data->color.tab[2] > 255 || data->color.tab[2] < 0)
		return ("\033[1;34mBlue color in floor or Ceiling not valid\n");
	data->color.tab[0] = data->color.tab[0] << 16;
	data->color.tab[1] = data->color.tab[1] << 8;
	if (ft_strnstr(data->idparsing, "F", 0) != 0)
		data->F_color = data->color.tab[0] + data->color.tab[1]
			+ data->color.tab[2];
	else if (ft_strnstr(data->idparsing, "C", 0) != 0)
		data->C_color = data->color.tab[0] + data->color.tab[1]
			+ data->color.tab[2];
	return (0);
}

char		*get_color2(data_t *data, char *line)
{
	int i;

	i = 0;
	while (*line != ',' && *line != 0)
	{
		line++;
		i++;
	}
	if (*line == 0 || i > 8)
		return ("Wrong color input");
	line++;
	data->color.tab[2] = atoi(line);
	i = 0;
	while (*line != ' ' && *line != 0)
	{
		line++;
		i++;
	}
	if (i > 8)
		return ("Wrong color input");
}

char		*get_color(data_t *data, char *line)
{
	int		i;

	i = -1;
	line += 1;
	while (line[++i] != 0)
		if (ft_isdigit(line[i]) != 1 && line[i] != ',' && line[i] != ' ')
			return ("Wrong color input");
	while (*line == ' ')
		line++;
	data->color.tab[0] = atoi(line);
	i = 0;
	while (*line != ',' && *line != 0)
	{
		line++;
		i++;
	}
	if (*line == 0 || i > 8)
		return ("Wrong color input");
	line++;
	data->color.tab[1] = atoi(line);
	data->Error = get_color2(data, line);
	data->Error = get_color3(data, line);
	return (data->Error);
}
