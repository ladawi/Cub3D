/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:24:15 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 11:28:45 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int		keypress(int keycode, data_t *data)
{
	(keycode == KEY_ESC) ? exitwindow(data) : 0;
	if (keycode == KEY_A)
		data->game.fStrafeLeft = 5.0f;
	if (keycode == KEY_D)
		data->game.fStrafeRight = 5.0f;
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		data->game.fVforward = 5.0f;
	if (keycode == KEY_S || keycode == KEY_BACKWARD)
		data->game.fVbackward = 5.0f;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		data->game.fRotaLeft = -M_PI;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		data->game.fRotaRight = M_PI;
	return (0);
}

void	freeall(data_t *data)
{
	int i;

	i = -1;
	if (data->line2)
	{
		free(data->line2);
		data->line2 = 0;
	}
	while (++i < data->Config.l)
	{
		if (data->map[i])
		{
			free(data->map[i]);
			data->map[i] = 0;
		}
	}
	if (data->Error)
	{
		free(data->Error);
		data->Error = 0;
	}
	free(data->Sprites.SpritesPos);
}

int		keyrelease(int keycode, data_t *data)
{
	if (keycode == KEY_A)
		data->game.fStrafeLeft = 0;
	if (keycode == KEY_D)
		data->game.fStrafeRight = 0;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		data->game.fRotaLeft = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		data->game.fRotaRight = 0;
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		data->game.fVforward = 0;
	if (keycode == KEY_S || keycode == KEY_BACKWARD)
		data->game.fVbackward = 0;
	return (0);
}
