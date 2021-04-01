/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:15:49 by pfile             #+#    #+#             */
/*   Updated: 2020/09/17 19:03:39 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**c_w - color_walls
**c_s - color_sprite
**c_p_r - color_player_rays
*/

typedef struct			s_fileheader
{
	unsigned int		size;
	short				reserv1;
	short				reserv2;
	unsigned int		bitoffset;
}						t_fileheader;

typedef struct			s_infoheader
{
	unsigned int		infoheader_bitsize;
	unsigned int		width;
	int					height;
	short int			reserv;
	short int			bpp;
	unsigned int		compression;
	unsigned int		image_bitsize;
	unsigned int		pix_per_metr_x;
	unsigned int		pix_per_metr_y;
	unsigned int		table_color_size;
	unsigned int		table_color_full;
}						t_infoheader;

typedef struct			s_hpr
{
	double				min_a;
	double				max_a;
	unsigned int		col;
	double				koef_x;
	double				koef_y;
	double				spr_min;
	double				spr_max;
	int					x;
	int					y;
	int					ct;
	double				diff_a;
	double				diff_b;
	double				angle;
	int					dst;
	int					i;
	int					yy;
}						t_hpr;

typedef struct			s_spr
{
	int					y;
	int					x;
	int					dst;
	double				angle;
}						t_spr;

typedef struct			s_map
{
	char				**map;
	char				*line_map;
	int					max_y;
	int					max_x;
	int					player_x;
	int					player_y;
	unsigned int		c_w;
	unsigned int		c_s;
	unsigned int		c_p_r;
	int					mx;
	int					my;
	int					spr_count;
	int					indef;
}						t_map;

typedef struct			s_tex
{
	int					line_length;
	int					bits_per_pixel;
	int					endian;
	void				*img;
	char				*addr;
	void				*mlx;
	int					width;
	int					height;
}						t_tex;

typedef struct			s_parse
{
	int					r_x;
	int					r_y;
	t_tex				*no;
	t_tex				*so;
	t_tex				*we;
	t_tex				*ea;
	t_tex				*ss;
	int					f;
	int					c;
	unsigned char		t;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_parse;

typedef struct			s_mlx
{
	void				*win;
	void				*mlx;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_mlx;

/*
**f_a - free angle
**a_s - angle_step(RAD)
**p_b_x - player base x
**p_b_y - player base y
**p_p - projection plane
*/

typedef struct			s_data
{
	t_parse				*parse;
	t_map				*map;
	t_mlx				*mlx;
	t_spr				*spr;
	double				angle;
	double				f_a;
	double				a_s;
	int					p_b_x;
	int					p_b_y;
	int					player_x;
	int					player_y;
	int					x;
	int					y;
	double				ind;
	int					p_p;
	int					mx;
	int					my;
	int					screen;
}						t_data;

#endif
