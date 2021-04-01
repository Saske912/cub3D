/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:06:24 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 13:05:07 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	path_wall(int p, char *line, t_parse *parse)
{
	char	*string;
	int		fd;

	if (!(string = ft_strtrim(&line[2], " ")))
		error_exit(12);
	if ((fd = open(string, O_RDONLY)) == -1)
		error_exit(2);
	close(fd);
	if (p == 1 && !parse->no->img)
		get_texture(parse->no, string);
	else if (p == 2 && !parse->so->img)
		get_texture(parse->so, string);
	else if (p == 3 && !parse->we->img)
		get_texture(parse->we, string);
	else if (p == 4 && !parse->ea->img)
		get_texture(parse->ea, string);
	else if (p == 5 && !parse->ss->img)
		get_texture(parse->ss, string);
	else
		error_exit_self("Double texture/sprite declaration\n");
	free(string);
}

void	path_ground(int p, char *line, t_parse *parse)
{
	char	*string;
	int		i;
	int		valid;

	i = 0;
	valid = 1;
	if (!(string = ft_strtrim(&line[1], " ")))
		error_exit(12);
	parse->r = (char)ft_atoi_ground(string, &valid, &i);
	if (string[i++] != ',' || !valid)
		error_exit_self("not valid color\n");
	parse->g = (char)ft_atoi_ground(string, &valid, &i);
	if (string[i++] != ',' || !valid)
		error_exit_self("not valid color\n");
	parse->b = (char)ft_atoi_ground(string, &valid, &i);
	if (string[i] || !valid)
		error_exit_self("not valid color\n");
	if (p == 1 && !parse->f)
		parse->f = init_color(parse);
	else if (p == 2 && !parse->c)
		parse->c = init_color(parse);
	else
		error_exit_self("Double Floor/Ceiling color declaration\n");
	free(string);
}

int		path_free(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i] == 32)
		i++;
	if (!line[i])
		return (1);
	else if (line[i] == '1')
	{
		if (!(map->line_map = ft_strjoin(line, "\n")))
			error_exit(12);
		map->max_x = ft_strlen(line);
		return (1);
	}
	else
		return (0);
}
