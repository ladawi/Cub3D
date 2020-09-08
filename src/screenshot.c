/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 09:51:54 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/08 17:20:23 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_head(t_data *data, t_header *head)
{
	head->type = 0x4d42;
	head->size = 54 + 4 * data->res_height * data->res_width;
	head->start = 54;
	head->header_size = 40;
	head->planes = 1;
	head->bpp = 32;
	head->raw_size = 4 * data->res_height * data->res_width;
	head->res = 2835;
}

void		create_header(t_data *data, char *header)
{
	t_header	head;

	ft_bzero(header, 54);
	init_head(data, &head);
	ft_memcpy(&header[0], &head.type, 2);
	ft_memcpy(&header[2], &head.size, 4);
	ft_memcpy(&header[10], &head.start, 4);
	ft_memcpy(&header[14], &head.header_size, 4);
	ft_memcpy(&header[18], &data->res_width, 4);
	ft_memcpy(&header[22], &data->res_height, 4);
	ft_memcpy(&header[26], &head.planes, 2);
	ft_memcpy(&header[28], &head.bpp, 2);
	ft_memcpy(&header[34], &head.raw_size, 4);
	ft_memcpy(&header[38], &head.res, 4);
	ft_memcpy(&header[42], &head.res, 4);
}

static	int	*fill_file(t_data *data)
{
	int *file;
	int	i;
	int	j;
	int k;

	if (!(file = ft_calloc(data->res_height * data->res_width, sizeof(int))))
		return (NULL);
	j = 0;
	while (j < data->res_height)
	{
		i = 0;
		while (i < data->res_width)
		{
			k = (data->res_height - 1 - j) * data->simg.size_line + i;
			file[k] = data->simg.str[i + (j * data->simg.size_line)];
			i++;
		}
		j++;
	}
	return (file);
}

char		*ft_screenshot(t_data *data)
{
	int		fdscreen;
	char	*file;
	char	header[54];
	char	*tofree;

	fdscreen = open("./screenshot/Cub3d screen.bmp", O_CREAT | O_WRONLY, 0666);
	create_header(data, &header[0]);
	file = (char*)fill_file(data);
	write(fdscreen, header, 54);
	write(fdscreen, file, 4 * data->res_height * data->res_width);
	close(fdscreen);
	if (*file)
	{
		free(file);
		*file = 0;
	}
	return (0);
}
