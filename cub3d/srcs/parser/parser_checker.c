/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:08:39 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 13:43:37 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_only_map_char(int i, t_para *para)
{
	int	j;

	j = 0;
	while (para->stock[i][j])
	{
		if (ft_strchr("01NSWE DRX\t", para->stock[i][j]))
			j++;
		else
			return (0);
	}
	return (1);
}

int	is_header(int i, t_para *para)
{
	int	j;

	j = 0;
	while (para->stock[i][j] && ft_is_space(para->stock[i][j]))
		j++;
	if (para->stock[i][j] == 'N' && para->stock[i][j + 1] == 'O'
		&& para->stock[i][j + 2] == ' ')
		return (para->header = NO);
	else if (para->stock[i][j] == 'S' && para->stock[i][j + 1] == 'O'
		&& para->stock[i][j + 2] == ' ')
		return (para->header = SO);
	else if (para->stock[i][j] == 'W' && para->stock[i][j + 1] == 'E'
		&& para->stock[i][j + 2] == ' ')
		return (para->header = WE);
	else if (para->stock[i][j] == 'E' && para->stock[i][j + 1] == 'A'
		&& para->stock[i][j + 2] == ' ')
		return (para->header = EA);
	else if (para->stock[i][j] == 'F' && para->stock[i][j + 1] == ' ')
		return (para->header = F);
	else if (para->stock[i][j] == 'C' && para->stock[i][j + 1] == ' ')
		return (para->header = C);
	return (0);
}

int	is_header_complete(t_para *para)
{
	if (para->no_t == NULL)
		return (0);
	else if (para->so_t == NULL)
		return (0);
	else if (para->we_t == NULL)
		return (0);
	else if (para->ea_t == NULL)
		return (0);
	else if (para->floor_c == -1)
		return (0);
	else if (para->ceiling_c == -1)
		return (0);
	else
		return (1);
}
