/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:01:45 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/02 15:01:00 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int			setid(data_t *data, char *str)
{
	int			i;
	char	*tofree;
	
	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	data->idparsing = ft_substr(str, 0, i);
	data->idparsing[i + 1] = 0;
	return (1);
}

char		*initgame(data_t *data, texture_t *textures)
{
	char	*lineconfig;
	char	*tofree;
	
	while (get_next_line(data->fd, &lineconfig) > 0 && data->Error == NULL)
	{
		get_next_line(data->fd2, &data->line2);
		setid(data, lineconfig);
		parsing(data, textures, lineconfig);
		if (data->line2)
		{
			free(data->line2);
			data->line2 = 0;
		}
		if (data->idparsing)
		{
			free(data->idparsing);
			data->idparsing = 0;
		}
	}
	if (lineconfig)
	{
		free(lineconfig);
		lineconfig = 0;
	}
	return (data->Error);
}
