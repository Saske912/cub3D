/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:48:45 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 14:29:09 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_hpr *hpr, t_data *data, t_spr *spr)
{
	int				x;
	int				y;
	int				m;
	int				h;

	x = 0;
	while (x < hpr->ct)
	{
		y = -1;
		if (find_wall(data, hpr->spr_max, x, spr->dst))
		{
			while (++y < hpr->ct)
			{
				m = (int)(x * hpr->koef_x);
				h = (int)(y * hpr->koef_y);
				hpr->col = find_texture_color(data->parse->ss, m, h);
				if (hpr->i + x < data->parse->r_x && hpr->i + x > 0 && hpr->yy
				+ y < data->parse->r_y && hpr->yy + y > 0 &&
				hpr->col != 0xFF000000)
					ft_mlx_pixel_put(data->mlx, hpr->i + x,
							hpr->yy + y, hpr->col);
			}
		}
		x++;
	}
}

void	display_sprite_step(double *diff_a, double a_s, int *i)
{
	*diff_a += a_s;
	(*i)++;
}

void	spr_min_more_then_min_a(t_hpr *hpr, double a_s, int *i)
{
	while (fmod(hpr->spr_min + hpr->diff_a, CI) > hpr->min_a)
		display_sprite_step(&hpr->diff_a, a_s, i);
	while (fmod(hpr->spr_min + hpr->diff_a, CI) < hpr->max_a)
		display_sprite_step(&hpr->diff_a, a_s, i);
}

void	display_sprite(t_spr *spr, t_data *data, double angle, int dst)
{
	t_hpr			*hpr;

	if (!(hpr = find_range(spr, data, dst)))
		error_standart("zsh");
	init_struct_hpr(angle, spr, hpr, data);
	if (hpr->max_a > hpr->spr_min)
		while (hpr->max_a - hpr->diff_a > hpr->spr_min)
			display_sprite_step(&hpr->diff_a, data->a_s, &hpr->i);
	else
	{
		if (hpr->spr_min > hpr->min_a)
			spr_min_more_then_min_a(hpr, data->a_s, &hpr->i);
		else if (hpr->spr_min < hpr->min_a && hpr->spr_min < hpr->max_a)
			while (hpr->spr_min + hpr->diff_a < hpr->max_a)
				display_sprite_step(&hpr->diff_a, data->a_s, &hpr->i);
		else
		{
			while (hpr->spr_min < hpr->min_a - hpr->diff_a)
				display_sprite_step(&hpr->diff_a, data->a_s, &hpr->i);
			hpr->i = data->parse->r_x - (hpr->ct - hpr->i) + hpr->ct;
		}
	}
	hpr->i -= hpr->ct;
	display(hpr, data, spr);
	free(hpr);
}
