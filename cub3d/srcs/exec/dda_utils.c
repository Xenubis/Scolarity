/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:00:58 by hbray             #+#    #+#             */
/*   Updated: 2026/06/02 15:06:31 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dda_step(float start_x, t_dda *dda, t_player *player)
{
	ft_memset(dda, 0, sizeof(t_dda));
	dda->angle_x = cos(start_x);
	dda->angle_y = sin(start_x);
	dda->pos_x = player->x / 64;
	dda->pos_y = player->y / 64;
	dda->map_x = (int)dda->pos_x;
	dda->map_y = (int)dda->pos_y;
	dda->delta_dist_x = fabs(1 / dda->angle_x);
	dda->delta_dist_y = fabs(1 / dda->angle_y);
	if (dda->angle_x < 0)
		dda->step_x = -1;
	else
		dda->step_x = 1;
	if (dda->angle_y < 0)
		dda->step_y = -1;
	else
		dda->step_y = 1;
	if (dda->angle_x < 0)
		dda->side_dist_x = (dda->pos_x - dda->map_x) * dda->delta_dist_x;
	else
		dda->side_dist_x = (dda->map_x + 1.0 - dda->pos_x) * dda->delta_dist_x;
	if (dda->angle_y < 0)
		dda->side_dist_y = (dda->pos_y - dda->map_y) * dda->delta_dist_y;
	else
		dda->side_dist_y = (dda->map_y + 1.0 - dda->pos_y) * dda->delta_dist_y;
}

void	step_dda(t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->map_x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->map_y += dda->step_y;
		dda->side = 1;
	}
}

void	calcul_dist_wall(float *ray_dist, float *wall_x, t_cub *cub)
{
	if (cub->dda.side == 0)
	{
		*ray_dist = cub->dda.side_dist_x - cub->dda.delta_dist_x;
		*wall_x = cub->dda.pos_y + *ray_dist * cub->dda.angle_y;
		if (cub->dda.texture != DOOR && cub->dda.texture != EXIT)
		{
			if (cub->dda.step_x > 0)
				cub->dda.texture = WEST;
			else
				cub->dda.texture = EAST;
		}
	}
	else
	{
		*ray_dist = cub->dda.side_dist_y - cub->dda.delta_dist_y;
		*wall_x = cub->dda.pos_x + *ray_dist * cub->dda.angle_x;
		if (cub->dda.texture != DOOR && cub->dda.texture != EXIT)
		{
			if (cub->dda.step_y > 0)
				cub->dda.texture = NORTH;
			else
				cub->dda.texture = SOUTH;
		}
	}
	*wall_x -= floor(*wall_x);
}
