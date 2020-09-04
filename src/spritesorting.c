/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:30:38 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/04 17:45:05 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void		spritesorting2(data_t *data, int *order, double *dist, int amount)
{
	int		o;
	double	k;

	data->Var.i = -1;
	while (++data->Var.i < amount)
	{
		data->Sprites.SpritesPos[data->Var.i].dist = dist[data->Var.i];
		data->Sprites.SpritesPos[data->Var.i].order = order[data->Var.i];
	}
	data->Var.i = -1;
	while (++data->Var.i + 1 < amount)
	{
		if (dist[data->Var.i] < dist[data->Var.i + 1])
		{
			o = order[data->Var.i];
			k = dist[data->Var.i];
			order[data->Var.i] = order[data->Var.i + 1];
			dist[data->Var.i] = dist[data->Var.i + 1];
			order[data->Var.i + 1] = o;
			dist[data->Var.i + 1] = k;
			data->Var.i = -1;
		}
	}
}

char		*ft_spritesorting(data_t *data)
{
	double	*tofree;

	if (!(data->Sdata.spriteOrder =
		ft_calloc(data->Sprites.numSprites + 1, sizeof(int))))
		return ("error malloc");
	if (!(data->Sdata.spriteDistance =
		ft_calloc(data->Sprites.numSprites + 1, sizeof(double))))
		return ("error malloc");
	while (++data->Var.i < data->Sprites.numSprites)
	{
		data->Sdata.spriteOrder[data->Var.i] = data->Var.i;
		data->Sdata.spriteDistance[data->Var.i] = (data->game.fPlayerX
			- data->Sprites.SpritesPos[data->Var.i].x)
			* (data->game.fPlayerX - data->Sprites.SpritesPos[data->Var.i].x)
				+ (data->game.fPlayerY -
					data->Sprites.SpritesPos[data->Var.i].y) *
						(data->game.fPlayerY -
							data->Sprites.SpritesPos[data->Var.i].y);
	}
	spritesorting2(data, data->Sdata.spriteOrder,
		data->Sdata.spriteDistance, data->Sprites.numSprites);
	tofree = data->Sdata.spriteDistance;
	if (tofree)
	{
		free(tofree);
		tofree = NULL;
	}
	return (0);
}
