/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:29:16 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 12:30:55 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_vector(t_data *data, double angle)
{
	int		scale;

	scale = 0;
	while (1)
	{
		data->x = data->map->player_x + scale * cos(angle);
		data->y = data->map->player_y - scale * sin(angle);
		if (data->map->map[(int)(data->y / MCSS)][(int)(data->x / MCSS)] == '1'
				|| data->map->map[(int)(data->y / MCSS)]
				[(int)(data->x / MCSS)] == ' ')
		{
			break ;
		}
		ft_mlx_pixel_put(data->mlx, data->x, data->y, 0x00FF7711);
		scale++;
	}
}

void	print_map_box(t_data *data, int color, int x, int y)
{
	int		scale;
	int		scale2;

	x *= MCSS;
	y *= MCSS;
	scale = 0;
	while (scale < MCSS - 1)
	{
		scale2 = 0;
		while (scale2 < MCSS - 1)
		{
			ft_mlx_pixel_put(data->mlx, scale + x, scale2 + y, color);
			scale2++;
		}
		scale++;
	}
}

void	print_map(t_data *data, t_map *map)
{
	data->y = 0;
	while (map->map[(data->y)])
	{
		data->x = 0;
		while (map->map[(data->y)][(data->x)])
		{
			if (map->map[data->y][data->x] == '1')
				print_map_box(data, map->c_w, data->x, data->y);
			if (map->map[data->y][data->x] == '2')
				print_map_box(data, map->c_s, data->x, data->y);
			if (map->map[data->y][data->x] == '0')
				print_map_box(data, map->c_p_r, data->x, data->y);
			if (map->map[data->y][data->x] == 'E' || \
					map->map[data->y][data->x] == \
				'W' || map->map[data->y][data->x] == 'S' || \
				map->map[data->y][data->x] == 'N')
				print_map_box(data, map->c_p_r, data->x, data->y);
			data->x += 1;
		}
		data->y += 1;
	}
}

void	print_map_player(t_data *data, int color, int x, int y)
{
	int		i;
	int		k;

	x -= 2;
	y -= 2;
	k = 0;
	while (k < 5)
	{
		i = 0;
		while (i < 5)
		{
			ft_mlx_pixel_put(data->mlx, x + k, y + i, color);
			i++;
		}
		k++;
	}
}

void	print_map_angle(t_data *data)
{
	double	angle;
	double	angle2;

	angle = 0;
	angle2 = data->angle - HF < 0 ? CI + data->angle - HF : data->angle - HF;
	print_map_player(data, data->map->c_s, \
			data->map->player_x, data->map->player_y);
	while (angle < FOV)
	{
		print_map_vector(data, angle2 + angle);
		angle += data->a_s * 10;
	}
}
