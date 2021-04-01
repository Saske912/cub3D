/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:05:46 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 14:04:19 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_hpr			*find_range(t_spr *spr, t_data *data, int dst)
{
	t_hpr	*hpr;
	int		a;

	if (!(hpr = malloc(sizeof(t_hpr))))
		error_exit(12);
	hpr->dst = dst;
	hpr->diff_b = 0;
	hpr->x = spr->x;
	hpr->y = spr->y;
	hpr->ct = (int)CUB_SIDE * data->p_p / dst;
	a = 0;
	while (a++ < (int)hpr->ct / 2)
		hpr->diff_b += data->a_s;
	return (hpr);
}

int				find_wall(t_data *data, double angle, int x, int dst)
{
	int		i;
	int		xx;
	int		y;

	i = 0;
	while (i < dst)
	{
		xx = data->player_x + (int)round(i * cos(angle - data->a_s * x));
		y = data->player_y - (int)round(i * sin(angle - data->a_s * x));
		if (data->map->map[(int)y / CUB_SIDE][(int)xx / CUB_SIDE] == '1')
			return (0);
		i++;
	}
	return (1);
}

unsigned int	find_texture_color(t_tex *tex, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int				find_pixel_in_tex(t_tex *tex, int i, double koef_z)
{
	double	mod_2d;

	mod_2d = (double)fmod(i, CUB_SIDE) / CUB_SIDE;
	return (find_texture_color(tex, mod_2d * tex->width, \
				(int)round(tex->height * koef_z)));
}

int				find_fov_hit_side(t_data *data, char **map, \
		double angle, double koef_z)
{
	if (angle >= 0 && angle <= M_PI && \
			get_map_value(map, data->y + 1, data->x, angle) != '1')
		return (find_pixel_in_tex(data->parse->no, data->x, koef_z));
	else if (angle >= M_PI / 2 && angle <= 3 * M_PI / 2 && \
			get_map_value(map, data->y, data->x + 1, angle) != '1')
		return (find_pixel_in_tex(data->parse->so, data->y, koef_z));
	else if (angle >= M_PI && angle <= 2 * M_PI && \
			get_map_value(map, data->y - 1, data->x, angle) != '1')
		return (find_pixel_in_tex(data->parse->we, data->x, koef_z));
	else if ((angle >= 3 * M_PI / 2 || angle <= M_PI / 2) && \
			get_map_value(map, data->y, data->x - 1, angle) != '1')
		return (find_pixel_in_tex(data->parse->ea, data->y, koef_z));
	else
		return (CC);
}
