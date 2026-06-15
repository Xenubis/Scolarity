/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:21:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/05 14:24:03 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	player_info(int i, int j, t_para *para)
{
	para->cub->player->y = i;
	para->cub->player->x = j;
	para->cub->player->angle = convert_angle(para->map[i][j]);
	para->map[i][j] = '0';
	para->nb_player++;
}

static void	find_info_error(t_para *para)
{
	if (para->nb_player != 1)
		error_pars("Error: wrong number of player\n", para);
	if (para->nb_exit > 1)
		error_pars("Error: too many exit\n", para);
}

static void	find_info_exit(int i, int j, t_para *para)
{
	if (!is_border(para->map, i, j))
		error_pars("Error: exit must be on border\n", para);
	para->nb_exit++;
	para->cub->is_exit = 1;
}

static void	find_info(t_para *para)
{
	int	i;
	int	j;

	i = 0;
	while (para->map[i])
	{
		j = 0;
		while (para->map[i][j])
		{
			if (is_player(para->map[i][j]))
				player_info(i, j, para);
			else if (para->map[i][j] == 'R')
				para->nb_collec++;
			else if (para->map[i][j] == 'D')
				para->nb_door++;
			else if (para->map[i][j] == 'X')
				find_info_exit(i, j, para);
			j++;
		}
		i++;
	}
	find_info_error(para);
}

void	map_validation(t_para *para)
{
	find_info(para);
	flood_fill(para);
	para->cub->player->x = (para->cub->player->x * 64) + 32;
	para->cub->player->y = (para->cub->player->y * 64) + 32;
}
