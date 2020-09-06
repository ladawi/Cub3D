/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:30:38 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:46:52 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void		spritesorting2(t_data *data, int *order, double *dist, int amount)
{
	int		o;
	double	k;

	data->var.i = -1;
	while (++data->var.i < amount)
	{
		data->sprites.spritespos[data->var.i].dist = dist[data->var.i];
		data->sprites.spritespos[data->var.i].order = order[data->var.i];
	}
	data->var.i = -1;
	while (++data->var.i + 1 < amount)
	{
		if (dist[data->var.i] < dist[data->var.i + 1])
		{
			o = order[data->var.i];
			k = dist[data->var.i];
			order[data->var.i] = order[data->var.i + 1];
			dist[data->var.i] = dist[data->var.i + 1];
			order[data->var.i + 1] = o;
			dist[data->var.i + 1] = k;
			data->var.i = -1;
		}
	}
}

char		*ft_spritesorting(t_data *data)
{
	double	*tofree;

	if (!(data->sdata.spriteorder =
		ft_calloc(data->sprites.numsprites + 1, sizeof(int))))
		return ("error malloc");
	if (!(data->sdata.spritedistance =
		ft_calloc(data->sprites.numsprites + 1, sizeof(double))))
		return ("error malloc");
	while (++data->var.i < data->sprites.numsprites)
	{
		data->sdata.spriteorder[data->var.i] = data->var.i;
		data->sdata.spritedistance[data->var.i] = (data->game.fplayerx
			- data->sprites.spritespos[data->var.i].x)
			* (data->game.fplayerx - data->sprites.spritespos[data->var.i].x)
				+ (data->game.fplayery -
					data->sprites.spritespos[data->var.i].y) *
						(data->game.fplayery -
							data->sprites.spritespos[data->var.i].y);
	}
	spritesorting2(data, data->sdata.spriteorder,
		data->sdata.spritedistance, data->sprites.numsprites);
	tofree = data->sdata.spritedistance;
	free(tofree);
	return (0);
}
