/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:12:02 by pfile             #+#    #+#             */
/*   Updated: 2020/09/17 18:32:12 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "structs.h"

/*
**FIND
*/
t_hpr			*find_range(t_spr *spr, t_data *data, int dst);
int				find_wall(t_data *data, double angle, int x, int dst);
unsigned int	find_texture_color(t_tex *tex, int x, int y);
int				find_pixel_in_tex(t_tex *tex, int i, double coef_z);
int				find_fov_hit_side(t_data *data, char **map, \
				double angle, double coef_z);
/*
**GET
*/
void			get_texture(t_tex *tex, char *string);
int				get_step_y(double angle, int y, int step);
int				get_step_x(double angle, int x, int step);
void			get_resolution(char *line, t_parse *parse);
void			get_window(t_data *data, t_map *map, \
				t_parse *parse, t_mlx *mlx);
int				get_next_line(int fd, char **line);
/*
**GET_MAP
*/
char			get_map_value(char **map, int y, int x, double angle);
void			get_map_next_line(char *line, t_map *map);
void			get_map_source(char *line, t_parse *parse, t_map *map);
unsigned int	get_map_color(t_mlx *mlx, int x, int y);
void			get_map_box(t_map *map);
/*
**CHECK
*/
void			check_file(int fd, t_data *data, t_map *map);
void			check_file_name(char *str);
/*
**VALID
*/
void			valid_map(t_data *data, t_map *map);
void			valid_pos(int i, int k, t_data *data, t_map *map);
void			valid_pos2(int i, int k, t_data *data, t_map *map);
/*
**FT
*/
int				ft_atoi_ground(char *str, int *valid, int *i);
void			ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
/*
**ERROR
*/
void			error_exit(int err);
void			error_exit_self(char *str);
int				error_standart(char *str);
/*
**INIT_STRUCT
*/
t_tex			*init_struct_tex(void);
t_map			*init_struct_map(void);
t_parse			*init_struct_parse(void);
t_data			*init_struct_params(int	ac);
void			init_struct_hpr(double angle, t_spr *spr, t_hpr *hpr,
				t_data *data);
/*
**INIT
*/
void			init_player_position(t_map *map, t_data *data);
void			init_angle(t_data *data);
int				init_color(t_parse *parse);
void			init_screen_size(void *mlx, t_parse *parse);
void			init_projection_plan_and_angle_step(t_data *data);
/*
**INIT_MAP
*/
void			init_map_max_x_y(t_map *map, t_data *data);
/*
**PATH
*/
void			path_wall(int p, char *line, t_parse *parse);
void			path_ground(int	p, char	*line, t_parse *parse);
int				path_free(char *line, t_map *map);
/*
**MAKE
*/
void			make_image(t_data *data, t_mlx *mlx);
int				make_frames(t_data *data);
/*
**HOOK
*/
int				hook_keyboard(int keycode, t_mlx *mlx);
int				hook_move(int keycode, t_data *data);
int				hook_exit(t_mlx *mlx);
/*
**STEP
*/
void			step_any(t_data *data, int keycode, t_map *map);
void			step_stack(t_data *data, double angle, int x);
/*
**PRINT
*/
void			print_floor_ceil(t_data *data, t_parse *parse);
void			print_walls(t_data *data);
void			print_line(t_data *data, int scale, int x, double angle);
void			print_sprites(t_data *data, t_map *map);
/*
**PRINT_MAP
*/
void			print_map_box(t_data *data, int	color, int x, int y);
void			print_map(t_data *data, t_map *map);
void			print_map_angle(t_data *data);
void			print_map_vector(t_data *data, double angle);
void			print_map_player(t_data *data, int color, int x, int y);
/*
**ADD
*/
char			*add_spaces(int nb);
void			add_sprite_pos(t_data *data);
void			add_sprite_distance(t_data *data);
unsigned int	add_color(t_mlx *mlx, int x, int y);
/*
**SORT
*/
void			sort_sprites(t_spr *spr, t_map *map);
/*
**DISPLAY
*/
void			display_sprite(t_spr *spr, t_data *data, double angle, int dst);
/*
**SAVE
*/
void			save_screen(t_mlx *mlx, int height, int width);

#endif
