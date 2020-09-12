/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:49:24 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/12 18:34:31 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_arg(char *str)
{
	if (ft_strncmp(str, "--save", 6) != 0)
		return (-1);
	else
		return (0);
}

void		print_err_and_exit(t_data *data)
{
	if (data->error != 0)
	{
		ft_putendl_fd("Error :", 0);
		ft_putendl_fd(data->error, 0);
		exit(1);
	}
}

void		run_game(t_data *data)
{
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_width,
		data->res_height, "Cub3D")))
	{
		data->error = "mlx_new_window failed";
		print_err_and_exit(data);
	}
	data->simg.img = mlx_new_image(data->mlx_ptr,
		data->res_width, data->res_height);
	data->simg.str = (int *)mlx_get_data_addr(data->simg.img, &data->simg.bpp,
		&data->simg.size_line, &data->simg.endian);
	data->simg.size_line = data->simg.size_line / 4;
	mlx_hook(data->mlx_win, X_EVENT_KEY_PRESS, KeyPressMask, &keypress, data);
	mlx_hook(data->mlx_win, X_EVENT_KEY_RELEASE, KeyReleaseMask,
		&keyrelease, data);
	mlx_hook(data->mlx_win, X_EVENT_EXIT, 1L << 17, &exitwindow, data);
	mlx_loop_hook(data->mlx_ptr, &gameloop, data);
	mlx_loop(data->mlx_ptr);
}

void		take_screenshot(t_data *data)
{
	data->simg.img = mlx_new_image(data->mlx_ptr, data->res_width,
		data->res_height);
	data->simg.str = (int *)mlx_get_data_addr(data->simg.img, &data->simg.bpp,
		&data->simg.size_line, &data->simg.endian);
	data->simg.size_line = data->simg.size_line / 4;
	gameloop(data);
	ft_screenshot(data);
	freeall(data);
	free(data->mlx_ptr);
	exit(1);
}

int			main(int ac, char **av)
{
	t_data		data;

	if (ac > 0 && ac < 4)
	{
		if ((ac == 3) && check_arg(av[2]) != 0)
		{
			data.error = "Wrong argument";
			print_err_and_exit(&data);
		}
		if (!(data.mlx_ptr = mlx_init()))
		{
			data.error = "mlx.init failed";
			print_err_and_exit(&data);
		}
		if ((data.error = initdata(&data, av[1])))
			print_err_and_exit(&data);
		if ((data.error = initgame(&data)) != NULL)
			print_err_and_exit(&data);
		(ac == 2) ? run_game(&data) : take_screenshot(&data);
	}
	else
		ft_putendl_fd("error : \nWrong nb of arguments", 0);
	return (0);
}
