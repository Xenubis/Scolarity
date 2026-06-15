/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:18:00 by hbray             #+#    #+#             */
/*   Updated: 2026/06/05 09:19:00 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_handler(int x, int y, t_cub *cub)
{
	int	delta_x;
	int	center_x;
	int	center_y;

	if (cub->mouse_locked == 0)
		return (0);
	(void)y;
	center_x = cub->screen.width / 2;
	center_y = cub->screen.height / 2;
	if (x == center_x)
		return (0);
	delta_x = x - center_x;
	cub->player->angle += delta_x * 0.0002;
	mlx_mouse_move(cub->mlx, cub->win, center_x, center_y);
	return (0);
}

void	mouse(t_cub *cub)
{
	cub->mouse_locked = (cub->mouse_locked + 1) % 2;
	if (cub->mouse_locked == 0)
		mlx_mouse_show(cub->mlx, cub->win);
	if (cub->mouse_locked == 1)
	{
		mlx_mouse_hide(cub->mlx, cub->win);
		mlx_mouse_move(cub->mlx, cub->win, cub->screen.width / 2,
			cub->screen.height / 2);
	}
}
