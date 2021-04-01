/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:48:05 by pfile             #+#    #+#             */
/*   Updated: 2020/09/17 15:02:56 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_position(t_map *map, t_data *data)
{
	map->player_x = data->p_b_x * MCSS + (int)(MCSS * 0.5);
	map->player_y = data->p_b_y * MCSS + (int)(MCSS * 0.5);
	data->player_x = data->p_b_x * CUB_SIDE + (int)(CUB_SIDE * 0.5);
	data->player_y = data->p_b_y * (int)CUB_SIDE + (int)(CUB_SIDE * 0.5);
}

void	init_screen_size(void *mlx, t_parse *parse)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	parse->r_x = parse->r_x > 6000 ? 6000 : parse->r_x;
	parse->r_y = parse->r_y > 6000 ? 6000 : parse->r_y;
	mlx_get_screen_size(mlx, &x, &y);
	parse->r_x = parse->r_x > x ? x : parse->r_x;
	parse->r_y = parse->r_y > y ? y : parse->r_y;
}

int		init_color(t_parse *parse)
{
	return (parse->t << 24 | parse->r << 16 | parse->g << 8 | parse->b);
}

void	init_projection_plan_and_angle_step(t_data *data)
{
	data->p_p = data->parse->r_x / 2 / tan(HF);
	data->a_s = (double)FOV / data->parse->r_x;
}

void	init_angle(t_data *data)
{
	if (data->map->map[data->p_b_y][data->p_b_x] == 'N')
		data->angle = M_PI / 2;
	else if (data->map->map[data->p_b_y][data->p_b_x] == 'W')
		data->angle = M_PI;
	else if (data->map->map[data->p_b_y][data->p_b_x] == 'S')
		data->angle = 3 * M_PI / 2;
	else if (data->map->map[data->p_b_y][data->p_b_x] == 'E')
		data->angle = 2 * M_PI;
}
