/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:43:36 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/02 12:42:31 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void		spritecalc(data_t *data)
{
	data->Sdata.fix = 0;
	data->Sdata.spriteX = data->Sprites.SpritesPos
		[data->Sdata.spriteOrder[data->Var.u]].x - data->game.fPlayerX;
	data->Sdata.spriteY = data->Sprites.SpritesPos
		[data->Sdata.spriteOrder[data->Var.u]].y - data->game.fPlayerY;
	data->Sdata.invDet = 1.0 / (data->game.dPlaneX * data->game.dDirY
		- data->game.dDirX * data->game.dPlaneY);
	data->Sdata.transformX = data->Sdata.invDet * (data->game.dDirY
		* data->Sdata.spriteX - data->game.dDirX * data->Sdata.spriteY);
	data->Sdata.transformY = data->Sdata.invDet * (-data->game.dPlaneY
		* data->Sdata.spriteX + data->game.dPlaneX * data->Sdata.spriteY);
	data->Sdata.spriteScreenX = (int)((data->res_width / 2)
		* (1 + data->Sdata.transformX / data->Sdata.transformY));
	data->Sdata.vMoveScreen = (int)(VMOVE / data->Sdata.transformY);
}

void		spritecalc2(data_t *data)
{
	data->Sdata.SpriteHeight =
		abs((int)(data->res_height / data->Sdata.transformY)) / VDIV;
	data->Sdata.drawStartY = -data->Sdata.SpriteHeight / 2
		+ data->res_height / 2 + data->Sdata.vMoveScreen;
	(data->Sdata.drawStartY < 0) ? data->Sdata.drawStartY = 0 : 0;
	data->Sdata.drawEndY = data->Sdata.SpriteHeight / 2
		+ data->res_height / 2 + data->Sdata.vMoveScreen;
	(data->Sdata.drawEndY >= data->res_height) ?
		data->Sdata.drawEndY = data->res_height : 0;
	data->Sdata.spriteWidth =
		abs((int)(data->res_height / data->Sdata.transformY)) / UDIV;
	data->Sdata.drawStartX = -data->Sdata.spriteWidth / 2
		+ data->Sdata.spriteScreenX;
	(data->Sdata.drawStartX < 0) ? data->Sdata.drawStartX = 0 : 0;
	data->Sdata.drawEndX = data->Sdata.spriteWidth / 2
		+ data->Sdata.spriteScreenX;
	(data->Sdata.drawEndX > data->res_width)
		? data->Sdata.drawEndX = data->res_width : 0;
	data->Sdata.stripe = data->Sdata.drawStartX - 1;
	(data->Sdata.drawEndX == data->res_width) ? data->Sdata.fix = 1 : 0;
}

void		drawsprites2(data_t *data, unsigned int color, double *zbuffer)
{
	while (++data->Sdata.stripe < data->Sdata.drawEndX)
	{
		data->Sdata.texX = (int)(256 * (data->Sdata.stripe -
			(-data->Sdata.spriteWidth / 2 + data->Sdata.spriteScreenX))
				* data->tex.S_x / data->Sdata.spriteWidth) / 256;
		data->Var.h = data->Sdata.drawStartY;
		if (data->Sdata.transformY > 0 && data->Sdata.stripe > 0 &&
			data->Sdata.stripe < data->res_width && data->Sdata.transformY <
				zbuffer[data->res_width - data->Sdata.stripe])
		{
			while (++data->Var.h < data->Sdata.drawEndY)
			{
				data->Var.d = (data->Var.h - data->Sdata.vMoveScreen) * 256 -
					data->res_height * 128 + data->Sdata.SpriteHeight * 128;
				data->Sdata.texY = ((data->Var.d * data->tex.S_y) /
					data->Sdata.SpriteHeight) / 256;
				color = data->tex.Sprite.str[data->tex.S_x
					* data->Sdata.texY + data->Sdata.texX];
				if ((color & 0x00FFFFFF) != 0)
					data->sImg.str[(data->res_width - data->Sdata.stripe
						- data->Sdata.fix) +
							(data->sImg.size_line * data->Var.h)] = color;
			}
		}
	}
}

char		*drawsprites(data_t *data, double *zbuffer)
{
	unsigned int	color;
	int			*tofree;
	
	data->Var.u = -1;
	data->Var.i = -1;
	data->Var.h = -1;
	data->Var.d = 0;
	ft_spritesorting(data);
	while (++data->Var.u < data->Sprites.numSprites)
	{
		spritecalc(data);
		spritecalc2(data);
		drawsprites2(data, color, zbuffer);
	}
	tofree = data->Sdata.spriteOrder;
	if (tofree)
	{
		free(tofree);
		tofree = NULL;
	}
	return (0);
}
