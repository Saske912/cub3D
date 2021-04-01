/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:36:37 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 12:08:49 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		make_frames(t_data *data)
{
	make_image(data, data->mlx);
	mlx_key_hook(data->mlx->win, hook_keyboard, data->mlx);
	mlx_hook(data->mlx->win, 17, 0L, hook_exit, data->mlx);
	mlx_hook(data->mlx->win, 2, 0L, hook_move, data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	return (0);
}

void	make_image(t_data *data, t_mlx *mlx)
{
	if (!(mlx->img = mlx_new_image(mlx->mlx, data->parse->r_x,
					data->parse->r_y)))
		error_standart("zsh");
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel), \
			&(mlx->line_length), &(mlx->endian));
	print_floor_ceil(data, data->parse);
	print_walls(data);
	print_sprites(data, data->map);
	if (data->map->max_y * MCSS < data->parse->r_y - 2 &&
			data->map->max_x * MCSS < data->parse->r_x - 2)
	{
		print_map(data, data->map);
		print_map_player(data, data->map->c_s, \
			data->map->player_x, data->map->player_y);
		print_map_angle(data);
	}
}
