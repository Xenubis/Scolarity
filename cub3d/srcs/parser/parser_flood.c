/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flood.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:02:33 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/05 15:09:10 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static char	**copy_map(char **map, t_para *para)
{
	char	**tmp_map;
	int		i;

	i = 0;
	tmp_map = ft_calloc((count_line(map) + 1), sizeof(char *));
	if (!tmp_map)
		error_pars("Error: malloc failed\n", para);
	while (map[i])
	{
		if (ft_strlen(map[i]) > 1000)
		{
			free_tab(tmp_map);
			error_pars("Error: map too big\n", para);
		}
		tmp_map[i] = ft_strdup(map[i]);
		if (!tmp_map[i])
		{
			free_tab(tmp_map);
			error_pars("Error: malloc failed\n", para);
		}
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

static void	flood_fill_exec(char **map_cpy, int x, int y, t_para *para)
{
	if (x < 0 || y < 0 || y >= count_line(map_cpy)
		|| (size_t)x >= ft_strlen(map_cpy[y]) || map_cpy[y][x] == ' ')
	{
		free_tab(map_cpy);
		error_pars("Error: invalid map\n", para);
	}
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'V')
		return ;
	if (map_cpy[y][x] == 'R')
		para->ff_collec++;
	if (map_cpy[y][x] == 'X')
	{
		para->ff_exit++;
		map_cpy[y][x] = 'V';
		return ;
	}
	map_cpy[y][x] = 'V';
	flood_fill_exec(map_cpy, x + 1, y, para);
	flood_fill_exec(map_cpy, x - 1, y, para);
	flood_fill_exec(map_cpy, x, y + 1, para);
	flood_fill_exec(map_cpy, x, y - 1, para);
}

void	flood_fill(t_para *para)
{
	char	**map_cpy;

	map_cpy = copy_map(para->map, para);
	if (!map_cpy)
		error_pars("Error: map copy failed\n", para);
	flood_fill_exec(map_cpy, para->cub->player->x, para->cub->player->y, para);
	free_tab(map_cpy);
	map_cpy = NULL;
	if (para->ff_collec != para->nb_collec)
	{
		free_tab(map_cpy);
		error_pars("Error: collectible unreachable\n", para);
	}
	if (para->ff_exit != para->nb_exit)
	{
		free_tab(map_cpy);
		error_pars("Error: exit unreachable\n", para);
	}
}
