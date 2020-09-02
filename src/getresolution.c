/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getresolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:20:49 by ladawi            #+#    #+#             */
/*   Updated: 2020/08/27 13:54:11 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

char			*get_resolutiom_check(data_t *data, char *line)
{
	if (data->res_height <= 0 || data->res_width <= 0)
	{
		printf("muk\n");
		data->Error = "wrong res";
	}
	if (data->res_width > data->max_res_width)
		data->res_width = data->max_res_width;
	if (data->res_height > data->max_res_height)
		data->res_height = data->max_res_height;
	if (*line != 0)
		data->Error = "wrong res";
	return (data->Error);
}

char			*all_c_ok(data_t *data, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) != 1 && line[i] != ' ' && line[i] != '\n')
			data->Error = "Wrong Carac in Res";
		i++;
	}
	return (data->Error);
}

char			*set_res(data_t *data, char *line, int nb)
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
	return (data->Error);
}

char			*get_resolution(data_t *data, char *line)
{
	int			i;

	i = 0;
	while (ft_findchar(line[i], "R 0") != 0)
		line++;
	if ((data->Error = all_c_ok(data, line)) != 0)
		return (data->Error);
	i = 0;
	set_res(data, line, 0);
	i = 0;
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
	return (get_resolutiom_check(data, line));
}
