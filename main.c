/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:44:33 by pfile             #+#    #+#             */
/*   Updated: 2020/09/20 12:56:20 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (argc == 2 || argc == 3)
	{
		data = init_struct_params(argc);
		check_file_name(argv[1]);
		if (argc == 3 && ft_strncmp("--save", argv[2], 6))
			error_exit(14);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error_standart("zsh");
		check_file(fd, data, data->map);
		get_window(data, data->map, data->parse, data->mlx);
	}
	else
		ft_putstr("Cub3D get 1 or 2 args\n");
	return (0);
}
