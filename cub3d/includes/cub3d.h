/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/05 13:07:39 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "animation.h"
# include "libft.h"
# include "parser.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ESC 65307
# define WIDTH 4096
# define HEIGHT 720
# define W 119
# define A 97
# define S 115
# define D 100
# define SPACE 32
# define C 99
# define LEFT 65361
# define RIGHT 65363
# define SPEED 300
# define ANGLE_SPEED 3.0
# define PI 3.14159265359
# define LENGTH 50
# define MINI_MAP_SIZE 252
# define MINI_MAP_CELL 12
# define MINI_MAP_PLAYER 8
# define MAX_DIST 99999.0

typedef struct s_para	t_para;
typedef struct s_col	t_col;

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	DOOR,
	EXIT
}						t_dir;

typedef struct s_dda
{
	float				delta_dist_x;
	float				delta_dist_y;
	float				side_dist_x;
	float				side_dist_y;
	float				angle_x;
	float				angle_y;
	float				pos_x;
	float				pos_y;
	float				wall_height;
	int					step_x;
	int					step_y;
	int					map_x;
	int					map_y;
	int					side;
	int					texture;
	int					texture_x;
}						t_dda;

typedef struct s_player
{
	float				x;
	float				y;
	float				angle;
	bool				key_up;
	bool				key_down;
	bool				key_right;
	bool				key_left;
	bool				rotate_left;
	bool				rotate_right;
}						t_player;

typedef struct s_img
{
	void				*img;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct s_door_cal
{
	float				dist;
	float				door_dist;
	float				door_wall_x;
	float				end;
	float				start_y;
	float				door_height;
	float				lvl;
	float				step;
	float				tex_pos;
	int					texture_x;
	int					draw_start_y;
}						t_door_cal;

typedef struct s_door
{
	int					x;
	int					y;
	int					state;
	float				open_lvl;
	double				timer;
	int					hit_door;
	int					door_map_x;
	int					door_map_y;
	t_dda				door_dda;
}						t_door;

typedef struct s_ray
{
	int					count;
	int					*x;
	int					*y;
	t_dda				*dda;
}						t_ray;

typedef struct s_cub
{
	t_player			*player;
	t_dda				dda;
	t_img				col_texture[6];
	t_img				texture[5];
	t_img				screen;
	t_img				hud_texture[6];
	t_img				*tex_w_e;
	t_anim				hud_anim;
	t_img				exit_texture[6];
	t_anim				exit_anim;
	t_para				*para;
	t_col				*col;
	t_door				*door;
	t_ray				*ray_mem;
	int					c_col;
	int					is_exit;
	int					exit_open;
	float				wall_dist[WIDTH];
	void				*mlx;
	void				*win;
	double				time;
	double				old_time;
	int					mouse_locked;
	float				door_dist_screen[WIDTH];
	int					door_solid_top[WIDTH];
}						t_cub;

t_cub					*create_cub(void);
t_player				*create_player(void);
t_para					*create_para(void);
void					open_win(t_cub *cub);

void					all_free(t_para **para, t_cub **cub);
int						close_win(t_cub *cub);
void					destroy_image_1(t_cub **cub);
void					destroy_image_2(t_cub **cub);
void					free_player(t_player **player);

void					draw_line(t_player *player, t_cub *cub, float start_x,
							int i);
void					draw_minimap(t_cub *cub);
void					draw_wall(int start_y, int end, int i, t_cub *cub);
void					draw_floor(int end, int i, t_cub *cub);
void					draw_ceiling(int start_y, int i, t_cub *cub);
int						draw_loop(t_cub *cub);
void					draw_door(t_cub *cub, float start_x, int i, int m);
int						get_color(t_img *img, int x, int y);
void					put_pixel(int x, int y, int color, t_cub *cub);

int						key_press(int keycode, t_cub *cub);
int						key_release(int keycode, t_player *player);

void					calc_door_height(t_cub *cub, float start_x,
							t_door_cal *d, int m);
void					door_open(t_cub *cub, t_pos pos, double frametime,
							int i);
void					update_doors(t_cub *cub, double frametime);
int						init_doors(t_cub *cub, t_para *para);
int						get_door_start_y(t_cub *cub, int start_y);
float					get_door_lvl(t_cub *cub, int x, int y);
void					open_door(t_cub *cub);
int						setup_door_render(t_cub *cub, t_door_cal *d, int m);
int						is_door(t_cub *cub, int dx, int dy);

void					calcul_dist_wall(float *ray_dist, float *wall_x,
							t_cub *cub);
void					init_dda_step(float start_x, t_dda *dda,
							t_player *player);
void					step_dda(t_dda *dda);

void					move_player(t_cub *cub, double frametime);
int						wall(t_cub *cub, float x, float y);
void					mouse(t_cub *cub);
int						mouse_handler(int x, int y, t_cub *cub);

#endif
