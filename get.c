/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:08:52 by pfile             #+#    #+#             */
/*   Updated: 2020/09/18 12:58:01 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_tex *tex, char *string)
{
	tex->mlx = mlx_init();
	if (!(tex->img = mlx_xpm_file_to_image(tex->mlx, string,
					&tex->width, &tex->height)))
		error_exit_self("No image in file\n");
	tex->addr = mlx_get_data_addr(tex->img, \
	&(tex->bits_per_pixel), &(tex->line_length), &(tex->endian));
}

void	get_resolution(char *line, t_parse *parse)
{
	int		i;

	i = 1;
	if (parse->r_x || parse->r_y)
		error_exit_self("Double resolution declaration\n");
	while (line[i] == 32)
		i++;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		parse->r_x = parse->r_x * 10 + (line[i++] - 48);
	while (line[i] == 32)
		i++;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		parse->r_y = parse->r_y * 10 + (line[i++] - 48);
	while (line[i] == 32)
		i++;
	if (line[i])
		error_exit_self("not valid resolution\n");
	if (!parse->r_x || !parse->r_y)
		error_exit_self("min resolution: 1x1\n");
	while (parse->r_x % 64 != 0)
		(parse->r_x)++;
}

int		get_step_x(double angle, int x, int step)
{
	if (angle >= M_PI / 2 && angle <= 3 * M_PI / 2)
		return ((int)(x + round(step * cos(angle))) / CUB_SIDE);
	else
		return ((int)floor((x + round(step * cos(angle))) / CUB_SIDE));
}

int		get_step_y(double angle, int y, int step)
{
	if (angle >= 0 && angle <= M_PI)
		return ((int)(y - round(step * sin(angle))) / CUB_SIDE);
	else
		return ((int)floor((y - round(step * sin(angle))) / CUB_SIDE));
}

void	get_window(t_data *data, t_map *map, t_parse *parse, t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		return ;
	init_screen_size(mlx->mlx, parse);
	init_angle(data);
	init_player_position(map, data);
	init_map_max_x_y(map, data);
	init_projection_plan_and_angle_step(data);
	if (data->screen != 3)
	{
		if (!(mlx->win = mlx_new_window(mlx->mlx,\
			parse->r_x, parse->r_y, "cub3D")))
			return ;
		mlx_loop_hook(mlx->mlx, make_frames, data);
		mlx_loop(mlx->mlx);
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	else
	{
		make_image(data, data->mlx);
		save_screen(data->mlx, data->parse->r_y, data->parse->r_x);
		exit(0);
	}
}
