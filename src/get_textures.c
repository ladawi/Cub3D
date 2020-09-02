/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:16:42 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/02 12:13:05 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

char		*get_texture_wall(data_t *data, char *line, int nb)
{
	line += 2;
	while (*line == ' ')
		line++;
	if (!(data->tex.TEX[nb].tex = mlx_xpm_file_to_image(data->mlx_ptr, line,
		&data->tex.TEX[nb].width, &data->tex.TEX[nb].height)))
		return ("WRONG path for textures");
	data->tex.TEX[nb].str = (int *)mlx_get_data_addr(data->tex.TEX[nb].tex,
		&data->tex.TEX[nb].bpp, &data->tex.TEX[nb].size_line,
			&data->tex.TEX[nb].endian);
	data->tex.TEX[nb].size_line /= 4;

	return (0);
}

char		*get_sprite_texture(data_t *data, char *line)
{
	line += 1;
	while (*line == ' ')
		line++;
	if (!(data->tex.Sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, line,
		&data->tex.S_x, &data->tex.S_y)))
		return ("\033[0;91mError\033[0m loading Sprite texture\n");
	data->tex.Sprite.str = (int *)mlx_get_data_addr(data->tex.Sprite.img,
		&data->tex.Sprite.bpp,
		&data->tex.Sprite.size_line, &data->tex.Sprite.endian);
	data->tex.Sprite.size_line = data->tex.Sprite.size_line / 4;
	return (0);
}
