/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:26:35 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 11:45:33 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_name(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || \
			str[i - 4] != '.')
		error_exit(5);
}

void	check_file(int fd, t_data *data, t_map *map)
{
	int		i;
	char	*line;

	i = -1;
	while (1 == get_next_line(fd, &line))
	{
		get_map_source(line, data->parse, map);
		free(line);
	}
	get_map_source(line, data->parse, map);
	free(line);
	if (!data->parse->r_x || !data->parse->r_y || !data->parse->no->img ||
	!data->parse->we->img || !data->parse->so->img || !data->parse->ea->img
	|| !data->parse->ss->img || !data->parse->f || !data->parse->c)
		error_exit_self("Missed config\n");
	if (!(map->map = ft_split(map->line_map, '\n')))
		error_exit(12);
	free(map->line_map);
	get_map_box(map);
	while (map->map[++i])
		;
	map->max_y = i;
	valid_map(data, map);
	add_sprite_pos(data);
}
