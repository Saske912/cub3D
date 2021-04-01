/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:02:01 by pfile             #+#    #+#             */
/*   Updated: 2020/09/18 12:48:19 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_sprites(t_data *data, t_map *map)
{
	int		i;

	i = 0;
	add_sprite_distance(data);
	sort_sprites(data->spr, map);
	while (i < map->spr_count)
	{
		display_sprite(&data->spr[i], data, data->angle, data->spr[i].dst);
		i++;
	}
}

void	print_walls(t_data *data)
{
	int		x;
	double	angle;
	double	angle2;

	data->f_a = data->angle - HF < 0 ? CI + data->angle - HF : data->angle - HF;
	x = data->parse->r_x;
	angle = 0;
	while (angle < FOV)
	{
		angle2 = data->f_a + angle > CI ? data->f_a +
			angle - CI : data->f_a + angle;
		step_stack(data, angle2, x);
		angle += data->a_s;
		x--;
	}
}

void	print_floor_ceil(t_data *data, t_parse *parse)
{
	int		scale;
	int		scale2;

	scale = 0;
	while (scale < parse->r_x)
	{
		scale2 = 0;
		while (scale2 < parse->r_y)
		{
			if (scale2 < (int)(parse->r_y / 2))
				ft_mlx_pixel_put(data->mlx, scale, scale2++, parse->f);
			else
				ft_mlx_pixel_put(data->mlx, scale, scale2++, parse->c);
		}
		scale++;
	}
}

void	print_line(t_data *data, int scale, int x, double angle)
{
	double	high;
	int		line;
	double	koef_z;
	int		line_full;

	line = (int)CUB_SIDE * data->p_p / round(scale * cos(data->angle - angle));
	line_full = line;
	high = (int)data->parse->r_y / 2 - round(line / 2);
	while (line--)
	{
		if (high + line < data->parse->r_y - 2 && high + line > 0)
		{
			koef_z = (double)line / line_full;
			ft_mlx_pixel_put(data->mlx, x, high + line, \
				find_fov_hit_side(data, data->map->map, angle, koef_z));
		}
	}
}
