/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:19:29 by pfile             #+#    #+#             */
/*   Updated: 2020/09/17 19:29:45 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			get_map_value(char **map, int y, int x, double angle)
{
	if (angle >= 0 && angle <= M_PI / 2)
		return (map[(int)(y / CUB_SIDE)][(int)floor(x / CUB_SIDE)]);
	else if (angle >= M_PI / 2 && angle <= M_PI)
		return (map[(int)(y / CUB_SIDE)][(int)(x / CUB_SIDE)]);
	else if (angle >= M_PI && angle <= 3 * M_PI / 2)
		return (map[(int)floor(y / CUB_SIDE)][(int)(x / CUB_SIDE)]);
	else if (angle >= 3 * M_PI / 2 && angle <= 2 * M_PI)
		return (map[(int)floor(y / CUB_SIDE)][(int)floor(x / CUB_SIDE)]);
	else
		return (0);
}

void			get_map_box(t_map *map)
{
	char	*str;
	int		i;
	int		k;
	int		diff;
	char	*spaces;

	i = 0;
	while (map->map[i])
	{
		if ((k = ft_strlen(map->map[i])) < map->max_x)
		{
			if (!(str = ft_strdup(map->map[i])))
				error_exit(12);
			free(map->map[i]);
			diff = map->max_x - k;
			if (!(spaces = add_spaces(diff)))
				error_exit(12);
			if (!(map->map[i] = ft_strjoin(str, spaces)))
				error_exit(12);
			free(str);
			free(spaces);
		}
		i++;
	}
}

unsigned int	get_map_color(t_mlx *mlx, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void			get_map_source(char *line, t_parse *parse, \
		t_map *map)
{
	if (map->line_map && map->indef)
		get_map_next_line(line, map);
	else if (!ft_strncmp("R ", line, 2))
		get_resolution(line, parse);
	else if (!ft_strncmp("NO ", line, 3))
		path_wall(1, line, parse);
	else if (!ft_strncmp("WE ", line, 3))
		path_wall(2, line, parse);
	else if (!ft_strncmp("SO ", line, 3))
		path_wall(3, line, parse);
	else if (!ft_strncmp("EA ", line, 3))
		path_wall(4, line, parse);
	else if (!ft_strncmp("S ", line, 2))
		path_wall(5, line, parse);
	else if (!ft_strncmp("C ", line, 2))
		path_ground(1, line, parse);
	else if (!ft_strncmp("F ", line, 2))
		path_ground(2, line, parse);
	else if (path_free(line, map))
		;
	else
		error_exit_self("Not valid parametr\n");
}

void			get_map_next_line(char *line, t_map *map)
{
	char	*map1;
	char	*map2;

	if (*line == '\0')
		map->indef = 0;
	if (!(map1 = ft_strjoin(line, "\n")))
		error_exit(12);
	if ((int)ft_strlen(line) > map->max_x)
		map->max_x = (int)ft_strlen(line);
	if (!(map2 = ft_strdup(map->line_map)))
		error_exit(12);
	free(map->line_map);
	if (!(map->line_map = ft_strjoin(map2, map1)))
		error_exit(12);
	free(map1);
	free(map2);
}
