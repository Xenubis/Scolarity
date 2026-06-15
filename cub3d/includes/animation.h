/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:55:10 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/04 14:52:10 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# define SPRITE_SCALE 4
# define SPRITE_HEIGHT 200
# define BOB_SPEED 2.0
# define BOB_AMPLITUDE 30.0
# define ANIM_SPEED_COL 0.08
# define ANIM_SPEED_HUD 0.2
# define HUD_SIZE 64
# define HUD_SPACING 5
# define HUD_MARGE 10

typedef enum e_state
{
	CLOSE,
	OPENING,
	OPEN,
	CLOSING,
}						t_state;

typedef struct s_cub	t_cub;
typedef struct s_anim
{
	int					frame[6];
	int					frame_count;
	int					current_frame;
	double				last_frame;
	double				time_b_frame;
}						t_anim;

typedef struct s_col
{
	int					x;
	int					y;
	int					collect;
	int					sprite_screen_x;
	int					sprite_screen_y;
	float				dist;
	int					sprite_height;
	float				bob;
	t_anim				anim;
}						t_col;

void					pixar(t_cub *cub);
void					anim_maj(t_anim *anim, double time);

void					draw_collectible(t_cub *cub, t_col *col);
void					check_collectibles(t_cub *cub);
void					render_hud(t_cub *cub);

t_col					*create_col(t_cub *cub);
void					init_hud(t_cub *cub);
void					init_exit(t_cub *cub);
void					init_img_1(t_cub *cub);

void					finish_game(t_cub *cub);
double					get_time(void);

#endif