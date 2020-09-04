/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:16:42 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/04 18:49:03 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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

char		*get_color2(data_t *data, char *line, unsigned int tab[3])
{
	if (tab[0] > 255 || tab[0] < 0)
		return ("\033[1;91mRed color in floor or Ceiling not valid\n");
	if (tab[1] > 255 || tab[1] < 0)
		return ("\033[1;92mGreen color in floor or Ceiling not valid\n");
	if (tab[2] > 255 || tab[2] < 0)
		return ("\033[1;34mBlue color in floor or Ceiling not valid\n");
	tab[0] = tab[0] << 16;
	tab[1] = tab[1] << 8;
	if (ft_strnstr(data->idparsing, "F", 0) != 0)
		data->F_color = tab[0] + tab[1] + tab[2];
	else if (ft_strnstr(data->idparsing, "C", 0) != 0)
		data->C_color = tab[0] + tab[1] + tab[2];
	return (0);
}

char		*get_color(data_t *data, char *line)
{
	unsigned int		tab[3];
	int					i;

	i = -1;
	line += 1;
	while (line[++i] != 0)
		if (ft_isdigit(line[i]) != 1 && line[i] != ',' && line[i] != ' ')
			return ("Wrong color input");
	while (*line == ' ')
		line++;
	tab[0] = atoi(line);
	i = 0;
	while (*line != ',' && *line != 0)
	{
		line++;
		i++;
	}
	if (*line == 0 || i > 8)
		return ("Wrong color input");
	line++;
	tab[1] = atoi(line);
	i = 0;
	while (*line != ',' && *line != 0)
	{
		line++;
		i++;
	}
	if (*line == 0 || i > 8)
		return ("Wrong color input");
	line++;
	tab[2] = atoi(line);
	i = 0;
	while (*line != ' ' && *line != 0)
	{
		line++;
		i++;
	}
	if (i > 8)
		return ("Wrong color input");
	data->Error = get_color2(data, line, tab);
	return (data->Error);
}
