/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:38:55 by hbray             #+#    #+#             */
/*   Updated: 2026/06/03 11:40:40 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_col(int i, int x, int y, t_col *col)
{
	int	j;

	j = 0;
	col[i].x = x;
	col[i].y = y;
	col[i].anim.current_frame = 0;
	col[i].anim.frame_count = 6;
	col[i].collect = 0;
	ft_memset(col[i].anim.frame, 0, sizeof(int) * 6);
	while (j < col[i].anim.frame_count)
	{
		col[i].anim.frame[j] = j;
		j++;
	}
	col[i].anim.last_frame = get_time();
	col[i].anim.time_b_frame = ANIM_SPEED_COL;
}

t_col	*create_col(t_cub *cub)
{
	t_col	*col;
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	col = malloc(sizeof(t_col) * cub->para->nb_collec);
	if (!col)
		error_pars("Error: malloc failed\n", cub->para);
	while (cub->para->map[y])
	{
		x = 0;
		while (cub->para->map[y][x])
		{
			if (cub->para->map[y][x] == 'R')
			{
				init_col(i, x, y, col);
				i++;
			}
			x++;
		}
		y++;
	}
	return (col);
}

void	init_hud(t_cub *cub)
{
	int	j;

	j = 0;
	cub->hud_anim.current_frame = 0;
	cub->hud_anim.frame_count = 6;
	ft_memset(cub->hud_anim.frame, 0, sizeof(int) * 6);
	while (j < cub->hud_anim.frame_count)
	{
		cub->hud_anim.frame[j] = j;
		j++;
	}
	cub->hud_anim.last_frame = get_time();
	cub->hud_anim.time_b_frame = ANIM_SPEED_HUD;
}

void	init_exit(t_cub *cub)
{
	int	j;

	j = 0;
	cub->exit_anim.current_frame = 0;
	cub->exit_anim.frame_count = 6;
	ft_memset(cub->exit_anim.frame, 0, sizeof(int) * 6);
	while (j < cub->exit_anim.frame_count)
	{
		cub->exit_anim.frame[j] = j;
		j++;
	}
	cub->exit_anim.last_frame = get_time();
	cub->exit_anim.time_b_frame = ANIM_SPEED_COL;
}
