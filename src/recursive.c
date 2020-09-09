/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:49:17 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/09 13:12:43 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_west(t_data *data, int x, int y)
{
	if (data->map[y][x] == ' ')
		return (0);
	if (data->map[y][x] == '1')
		return (1);
	if (x - 1 < 0)
		return (0);
	if (y - 1 < 0)
		return (0);
	return (check_west(data, x - 1, y) && check_west(data, x, y - 1));
}

int			check_est(t_data *data, int x, int y)
{
	if (data->map[y] == 0)
		return (0);
	if (data->map[y][x] == ' ')
		return (0);
	if (data->map[y][x] == '1')
	{
		return (1);
	}
	if (data->map[y][x] == 0)
		return (0);
	return (check_est(data, x + 1, y) && check_est(data, x, y + 1));
}

int			check_north(t_data *data, int x, int y)
{
	if (data->map[y][x] == ' ')
		return (0);
	if (data->map[y][x] == '1')
		return (1);
	if (data->map[y][x] == 0)
		return (0);
	if (y - 1 < 0)
		return (0);
	return (check_north(data, x + 1, y) && check_north(data, x, y - 1));
}

int			check_south(t_data *data, int x, int y)
{
	if (data->map[y] == 0)
		return (0);
	if (data->map[y][x] == ' ')
		return (0);
	if (data->map[y][x] == '1')
		return (1);
	if (x - 1 < 0)
		return (0);
	return (check_south(data, x - 1, y) && check_south(data, x, y + 1));
}

char		*check_spawn(t_data *data)
{
	int i;

	i = 0;
	i += check_west(data, data->player.x - 1, data->player.y);
	i += check_north(data, data->player.x, data->player.y - 1);
	i += check_est(data, data->player.x + 1, data->player.y);
	i += check_south(data, data->player.x, data->player.y + 1);
	if (i != 4)
		return ("Spawn not valid");
	return (0);
}
