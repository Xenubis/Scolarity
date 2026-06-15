/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:53:28 by hbray             #+#    #+#             */
/*   Updated: 2026/06/04 13:42:47 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(t_pos pos, int size, int color, t_cub *cub)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < size)
	{
		a = 0;
		while (a < size)
		{
			put_pixel(pos.x + a, pos.y + i, color, cub);
			a++;
		}
		i++;
	}
}

void	draw_direction_ray(t_cub *cub)
{
	float	dir_x;
	float	dir_y;
	float	tmp_x;
	float	tmp_y;
	int		i;

	dir_x = cos(cub->player->angle);
	dir_y = sin(cub->player->angle);
	tmp_x = cub->player->x;
	tmp_y = cub->player->y;
	i = 0;
	while (i < LENGTH)
	{
		put_pixel(MINI_MAP_SIZE / 2 + (int)(tmp_x - cub->player->x) / (64
				/ MINI_MAP_CELL), MINI_MAP_SIZE / 2 + (int)(tmp_y
				- cub->player->y) / (64 / MINI_MAP_CELL), 0xFF0000, cub);
		tmp_x += dir_x;
		tmp_y += dir_y;
		i++;
	}
}

static int	choose_color(int map_x, int map_y, t_cub *cub)
{
	int	color;

	color = 0x0000FF;
	if (map_y < 0 || map_y >= count_line(cub->para->map) || map_x < 0
		|| map_x >= (int)ft_strlen(cub->para->map[map_y]))
		color = 0x0000FF;
	else
	{
		if (cub->para->map[map_y][map_x] == '1')
			color = 0x0000FF;
		if (cub->para->map[map_y][map_x] == '0')
			color = 0xFFFFFF;
		if (cub->para->map[map_y][map_x] == 'D')
			color = 0xFFFF00;
		if (cub->para->map[map_y][map_x] == 'R')
			color = 0x00FF00;
		if (cub->para->map[map_y][map_x] == 'X')
			color = 0xFF0000;
	}
	return (color);
}

void	draw_minimap(t_cub *cub)
{
	int	y;
	int	x;
	int	map_x;
	int	map_y;
	int	color;

	y = -1;
	while (++y < MINI_MAP_SIZE / MINI_MAP_CELL)
	{
		x = -1;
		while (++x < MINI_MAP_SIZE / MINI_MAP_CELL)
		{
			map_x = (cub->player->x / 64) - (MINI_MAP_SIZE / MINI_MAP_CELL / 2)
				+ x;
			map_y = (cub->player->y / 64) - (MINI_MAP_SIZE / MINI_MAP_CELL / 2)
				+ y;
			color = choose_color(map_x, map_y, cub);
			draw_square((t_pos){x * MINI_MAP_CELL, y * MINI_MAP_CELL},
				MINI_MAP_CELL, color, cub);
		}
	}
	draw_square((t_pos){(MINI_MAP_SIZE / 2) - (MINI_MAP_PLAYER / 2),
		(MINI_MAP_SIZE / 2) - (MINI_MAP_PLAYER / 2)}, MINI_MAP_PLAYER, 0xFF0000,
		cub);
	draw_direction_ray(cub);
}
