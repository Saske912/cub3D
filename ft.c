/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:13:03 by pfile             #+#    #+#             */
/*   Updated: 2020/09/15 11:54:19 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * \
			(mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		ft_atoi_ground(char *str, int *valid, int *i)
{
	int		number;

	number = 0;
	if (!str || !str[*i])
		*valid = 0;
	if (str[*i] >= 47 && str[*i] <= 58)
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
			number = number * 10 + (str[(*i)++] - 48);
	else
		*valid = 0;
	if (number < 0 || number > 255)
		*valid = 0;
	return (number);
}
