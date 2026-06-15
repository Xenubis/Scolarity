/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:11:12 by hbray             #+#    #+#             */
/*   Updated: 2026/06/05 09:52:29 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	door_open(t_cub *cub, t_pos pos, double frametime, int i)
{
	(void)pos;
	if (cub->door[i].state == OPENING)
	{
		cub->door[i].open_lvl += (1.5 * frametime);
		if (cub->door[i].open_lvl >= 1.0)
		{
			cub->door[i].open_lvl = 1.0;
			cub->door[i].state = OPEN;
			cub->door[i].timer = 0.0;
		}
	}
	else if (cub->door[i].state == OPEN)
	{
		cub->door[i].timer += frametime;
		if (cub->door[i].timer > 3.0 && !is_door(cub, cub->door[i].x,
				cub->door[i].y))
			cub->door[i].state = CLOSING;
	}
}

void	calc_door_height(t_cub *cub, float start_x, t_door_cal *d, int m)
{
	t_dda	back_dda;

	back_dda = cub->dda;
	cub->dda = cub->ray_mem->dda[m];
	calcul_dist_wall(&d->door_dist, &d->door_wall_x, cub);
	cub->dda = back_dda;
	d->dist = d->door_dist * 64 * cos(start_x - cub->player->angle);
	if (d->dist < 0.1)
		d->dist = 0.1;
	d->door_height = (64 / d->dist) * (cub->screen.width / 2) / (tan(PI / 6));
	d->start_y = (cub->screen.height - d->door_height) / 2;
	d->end = d->start_y + d->door_height;
}

int	setup_door_render(t_cub *cub, t_door_cal *d, int m)
{
	int	offset;

	d->lvl = get_door_lvl(cub, cub->ray_mem->x[m], cub->ray_mem->y[m]);
	if (d->lvl == 1.0)
		return (1);
	offset = (int)(d->door_height * d->lvl);
	d->draw_start_y = d->start_y + offset;
	if (d->draw_start_y < 0)
		d->draw_start_y = 0;
	if (d->end > cub->screen.height)
		d->end = cub->screen.height;
	d->step = (float)cub->texture[DOOR].height / d->door_height;
	d->tex_pos = (d->draw_start_y - (d->start_y + offset)) * d->step;
	d->texture_x = (int)(d->door_wall_x * cub->texture[DOOR].width);
	return (0);
}

void	open_door(t_cub *cub)
{
	int	target_x;
	int	target_y;
	int	i;

	target_x = (cub->player->x + cos(cub->player->angle) * 64) / 64;
	target_y = (cub->player->y + sin(cub->player->angle) * 64) / 64;
	if (cub->para->map[target_y][target_x] == 'D')
	{
		i = 0;
		while (i < cub->para->nb_door)
		{
			if (cub->door[i].x == target_x && cub->door[i].y == target_y)
			{
				if (cub->door[i].state == CLOSE
					|| cub->door[i].state == CLOSING)
					cub->door[i].state = OPENING;
			}
			i++;
		}
	}
}
