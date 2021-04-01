/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:06:24 by pfile             #+#    #+#             */
/*   Updated: 2020/09/17 19:03:37 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_hpr(double angle, t_spr *spr, t_hpr *hpr, t_data *data)
{
	hpr->min_a = angle - HF < 0 ? CI + angle - HF : angle - HF;
	hpr->max_a = angle + HF > CI ? angle + HF - CI : angle + HF;
	hpr->col = 0;
	hpr->koef_x = (double)data->parse->ss->width / hpr->ct;
	hpr->koef_y = (double)data->parse->ss->height / hpr->ct;
	hpr->diff_a = 0;
	hpr->angle = spr->angle;
	hpr->spr_min = spr->angle - hpr->diff_b < 0 ?
		CI + spr->angle - hpr->diff_b : spr->angle - hpr->diff_b;
	hpr->spr_max = spr->angle + hpr->diff_b > CI ?
		spr->angle + hpr->diff_b - CI : spr->angle + hpr->diff_b;
	hpr->i = 0;
	hpr->yy = data->parse->r_y / 2 - hpr->ct / 2;
}

t_map	*init_struct_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		error_exit(12);
	map->c_w = 0x00FFAA00;
	map->c_s = 0x00AA00FF;
	map->c_p_r = 0x00BBBB00;
	map->line_map = NULL;
	map->map = NULL;
	map->max_y = 0;
	map->max_x = 0;
	map->spr_count = 0;
	map->indef = 1;
	return (map);
}

t_tex	*init_struct_tex(void)
{
	t_tex	*tex;

	if (!(tex = malloc(sizeof(t_tex))))
		error_exit(12);
	tex->line_length = 0;
	tex->bits_per_pixel = 0;
	tex->endian = 0;
	tex->img = NULL;
	tex->addr = NULL;
	tex->mlx = NULL;
	tex->width = 0;
	tex->height = 0;
	return (tex);
}

t_parse	*init_struct_parse(void)
{
	t_parse *parse;

	if (!(parse = malloc(sizeof(t_parse))))
		error_exit(12);
	parse->no = init_struct_tex();
	parse->so = init_struct_tex();
	parse->we = init_struct_tex();
	parse->ea = init_struct_tex();
	parse->ss = init_struct_tex();
	parse->r_x = 0;
	parse->r_y = 0;
	parse->f = 0;
	parse->c = 0;
	parse->t = 0;
	parse->r = 0;
	parse->g = 0;
	parse->b = 0;
	return (parse);
}

t_data	*init_struct_params(int ac)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		error_exit(12);
	data->parse = init_struct_parse();
	data->map = init_struct_map();
	if (!(data->mlx = malloc(sizeof(t_mlx))))
		error_exit(12);
	data->player_x = 0;
	data->player_y = 0;
	data->screen = ac;
	return (data);
}
