/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:05:31 by pfile             #+#    #+#             */
/*   Updated: 2020/09/13 18:38:11 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fileheader	fileheader_init(t_fileheader fh, unsigned int size, int hs)
{
	fh.size = size;
	fh.reserv1 = 0;
	fh.reserv2 = 0;
	fh.bitoffset = 54;
	return (fh);
}

t_infoheader	infoheader_init(t_infoheader ih, int w, int h, int bpp)
{
	ih.infoheader_bitsize = sizeof(ih);
	ih.width = w;
	ih.height = -h;
	ih.reserv = 1;
	ih.bpp = bpp;
	ih.compression = 0;
	ih.image_bitsize = w * h * ((short)bpp / 8) + 54;
	ih.pix_per_metr_x = 3780;
	ih.pix_per_metr_y = 3780;
	ih.table_color_size = 0;
	ih.table_color_full = 0;
	return (ih);
}

void			save_screen(t_mlx *mlx, int height, int width)
{
	t_fileheader	fileheader;
	t_infoheader	infoheader;
	unsigned int	size;
	int				fd;

	size = width * height * (mlx->bits_per_pixel / 8) + sizeof(fileheader)
		+ sizeof(infoheader) + 2;
	fileheader = fileheader_init(fileheader, size, sizeof(fileheader) +
			sizeof(infoheader) + 2);
	infoheader = infoheader_init(infoheader, width, height,
			mlx->bits_per_pixel);
	if ((fd = open(BMP, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) == -1)
		error_standart("zsh");
	write(fd, "BM", 2);
	write(fd, &fileheader, sizeof(fileheader));
	write(fd, &infoheader, sizeof(infoheader));
	write(fd, mlx->addr, width * height * 4);
	close(fd);
}
