/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:03 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 11:09:21 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_cub	t_cub;
typedef struct s_player	t_player;

typedef struct s_para
{
	char				**stock;
	char				**map;
	char				*no_t;
	char				*so_t;
	char				*we_t;
	char				*ea_t;
	int					floor_c;
	int					ceiling_c;
	char				*path;
	int					header;
	int					i_map;
	int					nb_player;
	int					nb_collec;
	int					ff_collec;
	int					nb_exit;
	int					ff_exit;
	int					nb_door;
	t_cub				*cub;
}						t_para;

typedef enum e_head
{
	VOID,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}						t_head;

typedef enum e_type
{
	SPRITE,
	MAP,
}						t_type;

void					parsing(t_para *para);
void					do_gnl(t_para *para);
void					do_parsing(t_para *para);

int						is_only_map_char(int i, t_para *para);
int						is_header(int i, t_para *para);
int						is_header_complete(t_para *para);

void					pars_header(char *line, t_para *para);
void					pars_color(char *line, int *color, t_para *para);
void					pars_texture(char *line, char **path, t_para *para);
int						color_split(char *tmp, t_para *para);

void					map_validation(t_para *para);
void					flood_fill(t_para *para);
int						is_border(char **map, int y, int x);
int						count_line(char **map);

int						count_comma(char *str, char c);
void					verif_color(char **tab, t_para *para);
void					end_split_color(char **tab, t_para *para);
void					pars_texture_cut(char *line, char *tmp, int i,
							t_para *para);
void					pars_color_cut(char *line, char *tmp, int i,
							t_para *para);

void					add_line_map(char *line, t_para *para);
void					malloc_map(char **line, int i, t_para *para);

int						is_player(char c);
float					convert_angle(char c);

void					error_pars(char *msg, t_para *para);
int						is_line_space(char *str);

#endif