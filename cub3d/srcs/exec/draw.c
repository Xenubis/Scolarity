/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:54:39 by hbray             #+#    #+#             */
/*   Updated: 2026/06/05 12:06:14 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(int start_y, int i, t_cub *cub)
{
	int	y;

	y = 0;
	while (y < start_y)
	{
		put_pixel(i, y, cub->para->ceiling_c, cub);
		y++;
	}
}

void	draw_floor(int end, int i, t_cub *cub)
{
	int	y;

	y = end;
	while (y < cub->screen.height)
	{
		put_pixel(i, y, cub->para->floor_c, cub);
		y++;
	}
}

void	draw_door(t_cub *cub, float start_x, int i, int m)
{
	t_door_cal	d;
	int			y;
	int			tex_y;
	int			color;

	calc_door_height(cub, start_x, &d, m);
	if (setup_door_render(cub, &d, m))
		return ;
	if (d.door_dist < cub->door_dist_screen[i])
	{
		cub->door_dist_screen[i] = d.door_dist;
		cub->door_solid_top[i] = d.draw_start_y;
	}
	y = d.draw_start_y - 1;
	while (++y < d.end)
	{
		tex_y = (int)d.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= cub->texture[DOOR].height)
			tex_y = cub->texture[DOOR].height - 1;
		d.tex_pos += d.step;
		color = get_color(&cub->texture[DOOR], d.texture_x, tex_y);
		put_pixel(i, y, color, cub);
	}
}

void	init_wall_texture(t_cub *cub, float *step, int *start_y, float *tex_pos)
{
	if (cub->dda.texture == EXIT)
		cub->tex_w_e = &cub->exit_texture[cub->exit_anim.current_frame];
	else
		cub->tex_w_e = &cub->texture[cub->dda.texture];
	*step = (float)cub->tex_w_e->height / cub->dda.wall_height;
	if (cub->dda.texture == DOOR)
		*start_y = get_door_start_y(cub, *start_y);
	if (*start_y < 0)
		*start_y = 0;
	*tex_pos = (*start_y - cub->screen.height / 2 + cub->dda.wall_height / 2)
		* (*step);
}

void	draw_wall(int start_y, int end, int i, t_cub *cub)
{
	int		y;
	int		tex_y;
	float	step;
	float	tex_pos;
	int		color;

	init_wall_texture(cub, &step, &start_y, &tex_pos);
	y = start_y;
	while (y < end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= cub->tex_w_e->height)
			tex_y = cub->tex_w_e->height - 1;
		tex_pos += step;
		color = get_color(cub->tex_w_e, cub->dda.texture_x,
				tex_y);
		if (color != 0 && color != -16777216)
			put_pixel(i, y, color, cub);
		y++;
	}
}
