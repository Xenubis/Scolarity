/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:26:30 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 11:24:56 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_time(void)
{
	struct timeval	tv;
	double			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec)) + ((tv.tv_usec) / 1000000.0);
	return (time);
}

void	finish_game(t_cub *cub)
{
	int	x;
	int	y;

	y = (int)((cub->player->y + sin(cub->player->angle) * 64) / 64);
	x = (int)((cub->player->x + cos(cub->player->angle) * 64) / 64);
	if (cub->para->map[y][x] == 'X')
	{
		if (cub->c_col >= cub->para->nb_collec)
			close_win(cub);
		else
			return ;
	}
}
