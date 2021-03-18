/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:13:29 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 18:11:14 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define FALSE					0
# define TRUE					1
# define BUFFER_SIZE			16

# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_4					21
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35
# define KEY_J					38
# define KEY_K					40
# define KEY_L					37
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_UP 				126
# define KEY_DOWN				125
# define KEY_MINUS				27
# define KEY_PLUS				24

# define KEY_TAB				48
# define KEY_MAJ				257
# define KEY_ESC				53

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_GAME_CLEAR		7
# define X_EVENT_KEY_EXIT		17

# define NSEW					"NSEW"
# define MOVESPEED				2

# define SPRITE					2

# define TEXTURES				8
# define TEX_NORTH				0
# define TEX_SOUTH				1
# define TEX_WEST				2
# define TEX_EAST				3
# define TEX_SPRITE				4
# define TEX_EXTRA				5
# define TEX_LB					6
# define TEX_GC					7

# define C_R					6
# define C_NO					0
# define C_SO					1
# define C_WE					2
# define C_EA					3
# define C_S					4
# define C_EXTRA				5
# define C_LB					6
# define C_GC					7
# define C_F 					8
# define C_C					9
# define C_MAP					10

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct		s_ray_sprite
{
	double			relative_dist_x;
	double			relative_dist_y;
	double			inverse_determinant;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				sprite_screen_x;
}					t_ray_sprite;

typedef struct		s_player
{
	float			x;
	float			y;
	float			posx;
	float			posy;
	float			width;
	float			height;
	int				turndirection;
	int				walk_forward;
	int				move_lr;
	float			rotationangle;
	float			walkspeed;
	float			turnspeed;
	double			rotationspeed;
	double			move_speed;
	double			rot_speed;
	double			eyelevel;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	char			direction;
}					t_player;

typedef	struct		s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}					t_ray;

typedef struct		s_tex
{
	char			*tex_path;
	int				*texture;
	double			width;
	double			height;
}					t_tex;

typedef struct		s_config
{
	int				screenwidth;
	int				screenheight;
	int				rows;
	int				colums;
	double			tile;
	t_tex			tex[TEXTURES];
	int				floor_color;
	int				ceiling_color;
	char			**map;
	double			rotation_speed;
	double			updown_speed;
	double			eyelevel;
	double			fov;
	int				t_num;
	int				istype[C_MAP + 1];
	int				sprite_num;
	int				padding;
}					t_config;

typedef struct		s_sprite_y
{
	double			x;
	double			y;
	double			distance;
}					t_sprite_y;

typedef struct		s_game
{
	int				**buf;
	double			*z_buf;
	t_config		config;
	void			*mlx;
	void			*win;
	t_img			img;
	t_ray			ray;
	t_player		player;
	t_sprite_y		*sprite;
	t_ray_sprite	ray_sprite;
}					t_game;

/*
** calc_*.c
*/
void				set_sprite(t_game *g);
void				set_ray_item(t_game *g, int x);
void				calc_raycasting(t_game *g);
void				calc_sprite(t_game *g);

/*
** check_map.c
*/
int					check_map_validation(t_game *game, t_config config);
int					check_values(t_game *game);
int					check_02(t_game *g, int i, int j);

/*
** draw.c
*/
void				draw_ceil_floor(t_game *game);
void				draw(t_game *game);

/*
**exit.c
*/
int					exit_error(t_game *game, int code, char const *str);
int					exit_error_line(char *line, int code, char const *str);
int					exit_game(t_game *game);

/*
** free.c
*/
void				free_double(char **str);
void				free_machine(t_game *game);
void				all_free(t_game *game);

/*
** get_next_line.c
*/
int					get_next_line(int fd, char **line);

/*
** init.c
*/
void				init_player(t_game *game);
void				init_config(t_game *game);
void				init_buffer(t_game *game);
void				init_mlx_functions(t_game *game);

/*
** key_event.c
*/
int					key_press(int key_code, t_game *game);
int					key_release(int key_code, t_game *game);

/*
** main.c
*/
void				check_argument(t_game *game, int argc, char *option);
void				start_raycasting(t_game *game);
int					main_loop(t_game *game);

/*
** move_player.c
*/
void				move_player(t_game *game, t_player *p);

/*
** parse_*.c
*/
int					parse_config(t_game *game, t_config *config,\
					char const *path);
int					parse_line(int ret, t_config *c, int type, char *line);

/*
** parse_utils.c
*/
int					is_endwith(char const *path, char const *str);
int					is_space(int x);
int					count_element(char **str);
int					check_digit(char *str);
int					is_upper(int x);

/*
** parse_utils2.c
*/
int					check_rgb_range(char **rgb);
char				*add_str(char *tmp, char *line);

/*
** screenshot.c
*/
int					screenshot(t_game *game);

/*
** texture.c
*/
void				load_texture(t_game *game);

#endif
