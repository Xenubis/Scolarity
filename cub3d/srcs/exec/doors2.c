/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:29:15 by hbray             #+#    #+#             */
/*   Updated: 2026/06/05 09:13:53 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_door_lvl(t_cub *cub, int x, int y)
{
	int	i;

	i = 0;
	while (i < cub->para->nb_door)
	{
		if (cub->door[i].x == x && cub->door[i].y == y)
			return (cub->door[i].open_lvl);
		i++;
	}
	return (0);
}

void	close_door(t_cub *cub, int i, double frametime)
{
	cub->door[i].open_lvl -= (1.5 * frametime);
	if (cub->door[i].open_lvl <= CLOSE)
	{
		cub->door[i].open_lvl = CLOSE;
		cub->door[i].state = 0;
	}
}

void	update_doors(t_cub *cub, double frametime)
{
	int	i;
	int	p_x;
	int	p_y;

	i = -1;
	p_x = (int)(cub->player->x / 64);
	p_y = (int)(cub->player->y / 64);
	while (++i < cub->para->nb_door)
	{
		if (cub->door[i].state == OPEN || cub->door[i].state == OPENING)
			door_open(cub, (t_pos){p_x, p_y}, frametime, i);
		if (cub->door[i].state == OPEN)
		{
			cub->door[i].timer += frametime;
			if (cub->door[i].timer > 3.0 && !is_door(cub, cub->door[i].x,
					cub->door[i].y))
				cub->door[i].state = CLOSING;
		}
		else if (cub->door[i].state == CLOSING)
			close_door(cub, i, frametime);
	}
}

int	is_door(t_cub *cub, int dx, int dy)
{
	float	px;
	float	py;
	int		marge;

	marge = 16;
	px = cub->player->x;
	py = cub->player->y;
	if ((int)(px - marge / 2) / 64 == dx && (int)(py - marge / 2) / 64 == dy)
		return (1);
	if ((int)(px + marge / 2) / 64 == dx && (int)(py - marge / 2) / 64 == dy)
		return (1);
	if ((int)(px - marge / 2) / 64 == dx && (int)(py + marge / 2) / 64 == dy)
		return (1);
	if ((int)(px + marge / 2) / 64 == dx && (int)(py + marge / 2) / 64 == dy)
		return (1);
	return (0);
}
