/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:49:24 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 16:14:15 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int			check_arg(char *str)
{
	if (ft_strncmp(str, "--save", 6) != 0)
		return (-1);
	else
		return (0);
}

void		print_err_and_exit(data_t *data)
{
	if (data->Error != 0)
	{
		ft_putendl_fd("Error :", 0);
		ft_putendl_fd(data->Error, 0);
		exit(1);
	}
}

void		run_game(data_t *data)
{
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_width,
		data->res_height, "Cub3D")))
	{
		data->Error = "mlx_new_window failed";
		print_err_and_exit(data);
	}
	data->sImg.img = mlx_new_image(data->mlx_ptr,
		data->res_width, data->res_height);
	data->sImg.str = (int *)mlx_get_data_addr(data->sImg.img, &data->sImg.bpp,
		&data->sImg.size_line, &data->sImg.endian);
	data->sImg.size_line = data->sImg.size_line / 4;
	mlx_hook(data->mlx_win, X_EVENT_KEY_PRESS, KeyPressMask, &keypress, data);
	mlx_hook(data->mlx_win, X_EVENT_KEY_RELEASE, KeyReleaseMask,
		&keyrelease, data);
	mlx_hook(data->mlx_win, X_EVENT_EXIT, KeyPressMask, &exitwindow, data);
	mlx_loop_hook(data->mlx_ptr, &gameloop, data);
	mlx_loop(data->mlx_ptr);
}

void		take_screenshot(data_t *data)
{
	data->sImg.img = mlx_new_image(data->mlx_ptr, data->res_width,
		data->res_height);
	data->sImg.str = (int *)mlx_get_data_addr(data->sImg.img, &data->sImg.bpp,
		&data->sImg.size_line, &data->sImg.endian);
	data->sImg.size_line = data->sImg.size_line / 4;
	gameloop(data);
	ft_screenshot(data);
	freeall(data);
	free(data->mlx_ptr);
	exit(1);
}

int			main(int ac, char **av)
{
	data_t		data;

	if (ac > 0 && ac < 4)
	{
		if ((ac == 3) && check_arg(av[2]) != 0)
		{
			data.Error = "Wrong argument";
			print_err_and_exit(&data);
		}
		if (!(data.mlx_ptr = mlx_init()))
		{
			data.Error = "mlx.init failed";
			print_err_and_exit(&data);
		}
		if (data.Error = initdata(&data, &data.tex, av[1]))
			print_err_and_exit(&data);
		if ((data.Error = initgame(&data, &data.tex)) != NULL)
			print_err_and_exit(&data);
		(ac == 2) ? run_game(&data) : take_screenshot(&data);
	}
	else
		ft_putendl_fd("Error : \nWrong nb of arguments", 0);
	return (0);
}
