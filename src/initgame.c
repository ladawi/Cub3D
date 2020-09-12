/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:01:45 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/12 16:54:07 by ladawi           ###   ########.fr       */
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
	free(lineconfig);
	if ((data->config.y == 0 && data->config.l == 0) && data->error == 0)
		data->error = "No map";
	if (data->error == 0)
		data->error = check_parsing(data);
	return (data->error);
}
