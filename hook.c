/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:34:10 by pfile             #+#    #+#             */
/*   Updated: 2020/09/13 14:44:03 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hook_move(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		step_any(data, keycode, data->map);
	if (keycode == 124)
		data->angle = data->angle - data->a_s * 100 < 0 ? CI + \
			data->angle - data->a_s * 100 : data->angle - data->a_s * 100;
	if (keycode == 123)
		data->angle = data->angle + data->a_s * 100 > CI ? \
		data->angle + data->a_s * 100 - CI : \
		data->angle + data->a_s * 100;
	return (0);
}

int		hook_keyboard(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int		hook_exit(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
	return (0);
}
