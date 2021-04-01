/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:42:41 by pfile             #+#    #+#             */
/*   Updated: 2020/09/13 13:49:34 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_max_x_y(t_map *map, t_data *data)
{
	map->mx = MCSS * map->max_x;
	map->my = MCSS * map->max_y;
	data->mx = CUB_SIDE * map->max_x;
	data->my = CUB_SIDE * map->max_y;
}
