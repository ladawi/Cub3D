/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:16:42 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 17:43:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char		*get_texture_wall(t_data *data, char *line, int nb)
{
	line += 2;
	while (*line == ' ')
		line++;
	if (!(data->tex.tex[nb].tex = mlx_xpm_file_to_image(data->mlx_ptr, line,
		&data->tex.tex[nb].width, &data->tex.tex[nb].height)))
		return ("WRONG path for textures");
	data->tex.tex[nb].str = (int *)mlx_get_data_addr(data->tex.tex[nb].tex,
		&data->tex.tex[nb].bpp, &data->tex.tex[nb].size_line,
			&data->tex.tex[nb].endian);
	data->tex.tex[nb].size_line /= 4;
	return (0);
}

char		*get_sprite_texture(t_data *data, char *line)
{
	line += 1;
	while (*line == ' ')
		line++;
	if (!(data->tex.sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, line,
		&data->tex.s_x, &data->tex.s_y)))
		return ("\033[0;91merror\033[0m loading Sprite texture\n");
	data->tex.sprite.str = (int *)mlx_get_data_addr(data->tex.sprite.img,
		&data->tex.sprite.bpp,
		&data->tex.sprite.size_line, &data->tex.sprite.endian);
	data->tex.sprite.size_line = data->tex.sprite.size_line / 4;
	return (0);
}
