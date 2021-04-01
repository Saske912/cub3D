/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:59:52 by pfile             #+#    #+#             */
/*   Updated: 2020/09/13 13:50:39 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step_stack(t_data *data, double angle, int x)
{
	int		scale;

	scale = 0;
	while (1)
	{
		data->x = data->player_x + round(scale * cos(angle));
		data->y = data->player_y - round(scale * sin(angle));
		if (get_map_value(data->map->map, data->y, data->x, angle) == '1' || \
				get_map_value(data->map->map, data->y, data->x, angle) == ' ')
		{
			print_line(data, scale, x, angle);
			break ;
		}
		scale += 1;
	}
}

void	step_any(t_data *data, int keycode, t_map *map)
{
	double	x_angle;

	if (keycode == 13)
		x_angle = data->angle;
	else if (keycode == 2)
		x_angle = data->angle - M_PI / 2 < 0 ? data->angle + 3 * M_PI / 2 : \
			data->angle - M_PI / 2;
	else if (keycode == 1)
		x_angle = data->angle - M_PI < 0 ? data->angle + M_PI : \
				data->angle - M_PI;
	else
		x_angle = data->angle - 3 * M_PI / 2 < 0 ? data->angle + M_PI / 2 : \
			data->angle - 3 * M_PI / 2;
	if (map->map[get_step_y(x_angle, data->player_y, MCSS)]\
			[get_step_x(x_angle, data->player_x, MCSS)] != '1' && \
			map->map[get_step_y(x_angle, data->player_y, MCSS)]\
			[get_step_x(x_angle, data->player_x, MCSS)] != ' ' && \
			map->map[get_step_y(x_angle, data->player_y, MCSS)]\
			[get_step_x(x_angle, data->player_x, MCSS)] != '2')
	{
		data->player_x += round(MCSS * cos(x_angle));
		data->player_y -= round(MCSS * sin(x_angle));
		map->player_x = (int)round(data->player_x / 4);
		map->player_y = (int)round(data->player_y / 4);
	}
}
