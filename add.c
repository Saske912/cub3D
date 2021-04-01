/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:41:26 by pfile             #+#    #+#             */
/*   Updated: 2020/09/18 12:50:49 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	add_color(t_mlx *mlx, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void			add_sprite_distance(t_data *data)
{
	int		i;
	int		diff_y;
	int		diff_x;

	i = 0;
	while (i < data->map->spr_count)
	{
		diff_y = data->player_y - data->spr[i].y;
		diff_x = data->player_x - data->spr[i].x;
		data->spr[i].dst = (int)hypot(diff_y, diff_x);
		data->spr[i].angle = atan2(abs(diff_y), abs(diff_x));
		if (diff_y < 0)
			data->spr[i].angle = 2 * M_PI - data->spr[i].angle;
		if (diff_x > 0)
			data->spr[i].angle = M_PI - data->spr[i].angle;
		if (diff_x > 0 && diff_y < 0)
			data->spr[i].angle += 2 * M_PI;
		i++;
	}
}

void			add_sprite_pos(t_data *data)
{
	int		i;
	int		k;
	int		n;

	data->spr = malloc(sizeof(t_spr) * data->map->spr_count);
	i = 0;
	n = 0;
	while (i < data->map->max_y)
	{
		k = 0;
		while (k < data->map->max_x)
		{
			if (data->map->map[i][k] == '2')
			{
				data->spr[n].y = i * CUB_SIDE + (int)CUB_SIDE / 2;
				data->spr[n].x = k * CUB_SIDE + (int)CUB_SIDE / 2;
				n++;
			}
			k++;
		}
		i++;
	}
}

char			*add_spaces(int nb)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * nb + 1);
	line[nb] = '\0';
	while (nb--)
		line[nb] = 32;
	return (line);
}
