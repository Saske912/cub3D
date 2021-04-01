/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:04:30 by pfile             #+#    #+#             */
/*   Updated: 2020/09/17 19:44:15 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_util(int i, int k, char c, t_map *map)
{
	if (i != 0 && k != 0 && i != map->max_y - 1 && k != map->max_x - 1)
		if (map->map[i - 1][k] != c && map->map[i + 1][k] != c &&
			map->map[i][k - 1] != c && map->map[i][k + 1] != c)
			return (0);
		else
			return (1);
	else
		return (1);
}

void	valid_pos2(int i, int k, t_data *data, t_map *map)
{
	if (map->map[i][k] == 'N' || map->map[i][k] == 'S' || \
			map->map[i][k] == 'E' || map->map[i][k] == 'W')
	{
		if (data->p_b_x && data->p_b_y)
			error_exit_self("Beta-versioin 0.01, no multiplayer sorry\n");
		else if (valid_util(i, k, ' ', map))
			error_exit_self("Some space or end map around player\n");
		else
		{
			data->p_b_y = i;
			data->p_b_x = k;
		}
	}
	else if (map->map[i][k] == '2')
		map->spr_count += 1;
	if (valid_util(i, k, ' ', map))
		error_exit_self("Space in map border\n");
}

void	valid_pos(int i, int k, t_data *data, t_map *map)
{
	if (map->map[i][k] == '1' || map->map[i][k] == ' ')
		return ;
	else if (map->map[i][k] == '0' || map->map[i][k] == '2' || \
			map->map[i][k] == 'N' || map->map[i][k] == 'S' || \
			map->map[i][k] == 'E' || map->map[i][k] == 'W')
		valid_pos2(i, k, data, map);
	else
		error_exit_self("Bad simvol in map\n");
}

void	valid_map(t_data *data, t_map *map)
{
	int		i;
	int		k;

	i = -1;
	while (map->map[++i])
	{
		k = -1;
		while (map->map[i][++k])
			valid_pos(i, k, data, map);
	}
	if (!data->p_b_x && !data->p_b_y)
		error_exit_self("Bad map /or no player\n");
}
