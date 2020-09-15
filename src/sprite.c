/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:43:36 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/15 13:59:38 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		spritecalc(t_data *data)
{
	data->sdata.fix = 0;
	data->sdata.spritex = data->sprites.spritespos
		[data->sdata.spriteorder[data->var.u]].x - data->game.fplayerx;
	data->sdata.spritey = data->sprites.spritespos
		[data->sdata.spriteorder[data->var.u]].y - data->game.fplayery;
	data->sdata.invdet = 1.0 / (data->game.dplanex * data->game.ddiry
		- data->game.ddirx * data->game.dplaney);
	data->sdata.transformx = data->sdata.invdet * (data->game.ddiry
		* data->sdata.spritex - data->game.ddirx * data->sdata.spritey);
	data->sdata.transformy = data->sdata.invdet * (-data->game.dplaney
		* data->sdata.spritex + data->game.dplanex * data->sdata.spritey);
	data->sdata.spritescreenx = (int)((data->res_width / 2)
		* (1 + data->sdata.transformx / data->sdata.transformy));
	data->sdata.vmovescreen = (int)(VMOVE / data->sdata.transformy)
		+ data->jump / data->sdata.transformy;
}

void		spritecalc2(t_data *data)
{
	data->sdata.spriteheight =
		abs((int)(data->res_height / data->sdata.transformy)) / VDIV;
	data->sdata.drawstarty = -data->sdata.spriteheight / 2
		+ data->issou + data->sdata.vmovescreen;
	(data->sdata.drawstarty < 0) ? data->sdata.drawstarty = 0 : 0;
	data->sdata.drawendy = data->sdata.spriteheight / 2
		+ data->issou + data->sdata.vmovescreen;
	(data->sdata.drawendy >= data->res_height) ?
		data->sdata.drawendy = data->res_height : 0;
	data->sdata.spritewidth =
		abs((int)(data->res_height / data->sdata.transformy)) / UDIV;
	data->sdata.drawstartx = -data->sdata.spritewidth / 2
		+ data->sdata.spritescreenx;
	(data->sdata.drawstartx < 0) ? data->sdata.drawstartx = 0 : 0;
	data->sdata.drawendx = data->sdata.spritewidth / 2
		+ data->sdata.spritescreenx;
	(data->sdata.drawendx > data->res_width)
		? data->sdata.drawendx = data->res_width : 0;
	data->sdata.stripe = data->sdata.drawstartx;
	(data->sdata.drawendx == data->res_width) ? data->sdata.fix = 1 : 0;
}

void		drawsprites2(t_data *data, unsigned int color, double *zbuffer)
{
	while (++data->sdata.stripe <= data->sdata.drawendx)
	{
		data->sdata.texx = (int)(256 * (data->sdata.stripe -
			(-data->sdata.spritewidth / 2 + data->sdata.spritescreenx))
				* data->tex.s_x / data->sdata.spritewidth) / 256;
		data->var.h = data->sdata.drawstarty;
		if (data->sdata.transformy > 0 && data->sdata.stripe > 0 &&
			data->sdata.stripe < data->res_width && data->sdata.transformy <
				zbuffer[data->res_width - data->sdata.stripe])
		{
			while (++data->var.h <= data->sdata.drawendy)
			{
				data->var.d = (data->var.h - data->sdata.vmovescreen) * 256 -
					data->issou * 2 * 128 + data->sdata.spriteheight * 128;
				data->sdata.texy = ((data->var.d * data->tex.s_y) /
					data->sdata.spriteheight) / 256;
				color = data->tex.sprite.str[data->tex.s_x
					* data->sdata.texy + data->sdata.texx];
				if ((color & 0x00FFFFFF) != 0)
					data->simg.str[(data->res_width - data->sdata.stripe
						- data->sdata.fix) +
							(data->simg.size_line * data->var.h)] = color;
			}
		}
	}
}

char		*drawsprites(t_data *data, double *zbuffer)
{
	unsigned int	color;
	int				*tofree;

	data->var.u = -1;
	data->var.i = -1;
	data->var.h = -1;
	data->var.d = 0;
	color = 0;
	ft_spritesorting(data);
	while (++data->var.u < data->sprites.numsprites)
	{
		spritecalc(data);
		spritecalc2(data);
		drawsprites2(data, color, zbuffer);
	}
	tofree = data->sdata.spriteorder;
	if (tofree)
	{
		free(tofree);
		tofree = NULL;
	}
	return (0);
}
