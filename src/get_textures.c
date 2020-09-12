/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:16:42 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/12 16:56:59 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*check_parsing(t_data *data)
{
	int i;

	i = 0;
	i += data->parsing.so;
	i += data->parsing.no;
	i += data->parsing.ea;
	i += data->parsing.we;
	if (data->parsing.r != 1 && data->error == 0)
		data->error = "Invalid Res input";
	if (data->parsing.f != 1 && data->error == 0)
		data->error = "Invalid Floor input";
	if (data->parsing.c != 1 && data->error == 0)
		data->error = "Invalid Ceiling input";
	if (i != 4 && data->error == 0)
		data->error = "Missing texture input";
	return (data->error);
}

char		*check_text(t_data *data, int nb)
{
	if (nb == NORTH && data->parsing.no == 1)
		return ("wrong north text input");
	else if (nb == SOUTH && data->parsing.so == 1)
		return ("wrong south text input");
	else if (nb == EAST && data->parsing.ea == 1)
		return ("wrong east text input");
	else if (nb == WEST && data->parsing.we == 1)
		return ("wrong west text input");
	if (nb == NORTH)
		data->parsing.no = 1;
	else if (nb == SOUTH)
		data->parsing.so = 1;
	else if (nb == EAST)
		data->parsing.ea = 1;
	else if (nb == WEST)
		data->parsing.we = 1;
	return (0);
}

char		*get_texture_wall(t_data *data, char *line, int nb)
{
	data->error = check_text(data, nb);
	if (data->error)
		return (data->error);
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
	if (data->parsing.s == 1)
		return ("Invalid Sprites input");
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
	data->parsing.s = 1;
	return (0);
}
