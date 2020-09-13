/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:01:45 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/13 18:48:09 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			setid(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	data->idparsing = ft_substr(str, 0, i);
	return (1);
}

void		calc_sf_dist(double height, double *r)
{
	int	i;

	i = 0;
	while (i < height)
	{
		r[i] = (height / (2. * (double)i - height));
		i++;
	}
}
int			shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}

char		*initgame(t_data *data)
{
	char	*lineconfig;
	int		ret;

	while ((ret = get_next_line(data->fd, &lineconfig) > 0)
		&& data->error == NULL)
	{
		get_next_line(data->fd2, &data->line2);
		setid(data, lineconfig);
		data->error = parsing(data, lineconfig);
		if (data->line2)
		{
			free(data->line2);
			data->line2 = 0;
		}
		free(data->idparsing);
		if (data->error != 0)
			return (data->error);
	}
	data->issou = data->res_height / 2;
	free(lineconfig);
	calc_sf_dist((double)(data->res_height), data->ray.sf_dist);
	if ((data->config.y == 0 && data->config.l == 0) && data->error == 0)
		data->error = "No map";
	if (data->error == 0)
		data->error = check_parsing(data);
	return (data->error);
}
