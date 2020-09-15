/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getresolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:20:49 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/14 14:13:43 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			*get_resolutiom_check(t_data *data, char *line)
{
	if (data->res_height <= 0 || data->res_width <= 0)
		data->error = "wrong res";
	if (data->res_width > data->max_res_width)
		data->res_width = data->max_res_width;
	if (data->res_height > data->max_res_height)
		data->res_height = data->max_res_height;
	if (*line != 0)
		data->error = "wrong res";
	return (data->error);
}

char			*all_c_ok(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) != 1 && line[i] != ' ' && line[i] != '\n')
			data->error = "Wrong Carac in Res";
		i++;
	}
	return (data->error);
}

char			*set_res(t_data *data, char *line, int nb)
{
	int i;

	i = 0;
	if (nb == 0)
	{
		while (ft_isdigit(line[i]) == 1 && line[i] != 0)
		{
			if (++i > 9)
				data->res_width = data->max_res_width;
			else
				data->res_width = ft_atoi(line);
		}
	}
	else if (nb == 1)
	{
		while (ft_isdigit(line[i]) == 1 && line[i] != 0)
		{
			if (++i > 9)
				data->res_height = data->max_res_height;
			else
				data->res_height = ft_atoi(line);
		}
	}
	return (data->error);
}

char			*get_resolution(t_data *data, char *line)
{
	int			i;

	i = 0;
	if (data->parsing.r > 1)
		return ("Invalid Parsing");
	while (ft_findchar(line[i], "R 0") != 0)
		line++;
	if ((data->error = all_c_ok(data, line)) != 0)
		return (data->error);
	i = 0;
	set_res(data, line, 0);
	while (ft_isdigit(*line++) == 1 && *line)
		i++;
	while (ft_isdigit(*line) == 0 && *line != 0)
		line++;
	i = 0;
	while (*line == ' ' || *line == '0')
		line++;
	set_res(data, line, 1);
	while (ft_isdigit(*line) == 1 && *line)
		line++;
	while (*line == ' ')
		line++;
	data->parsing.r += 1;
	return (get_resolutiom_check(data, line));
}
