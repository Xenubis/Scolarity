/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:13:26 by hbray             #+#    #+#             */
/*   Updated: 2026/06/05 08:55:00 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_collision(t_cub *cub, float x, float y)
{
	int		map_x;
	int		map_y;
	char	c;

	map_x = (int)(x / 64);
	map_y = (int)(y / 64);
	c = cub->para->map[map_y][map_x];
	if (c == '1' || c == 'X')
		return (1);
	if (c == 'D' && get_door_lvl(cub, map_x, map_y) < 1.0)
		return (1);
	return (0);
}

int	wall(t_cub *cub, float x, float y)
{
	int	marge;

	marge = 16;
	if (check_collision(cub, x - (marge / 2), y - (marge / 2)))
		return (1);
	if (check_collision(cub, x - (marge / 2), y + (marge / 2)))
		return (1);
	if (check_collision(cub, x + (marge / 2), y - (marge / 2)))
		return (1);
	if (check_collision(cub, x + (marge / 2), y + (marge / 2)))
		return (1);
	return (0);
}
