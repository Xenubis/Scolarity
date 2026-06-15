/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:44:52 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 11:14:56 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

float	convert_angle(char c)
{
	float	i;

	i = 0;
	if (c == 'N')
		i = 3 * PI / 2;
	if (c == 'S')
		i = PI / 2;
	if (c == 'W')
		i = PI;
	if (c == 'E')
		i = PI * 2;
	return (i);
}

int	is_border(char **map, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (y == count_line(map) - 1)
		return (1);
	if ((size_t)(x + 1) >= ft_strlen(map[y]) || (size_t)x >= ft_strlen(map[y
			- 1]) || (size_t)x >= ft_strlen(map[y + 1]))
		return (1);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x - 1] == ' '
		|| map[y][x + 1] == ' ')
		return (1);
	return (0);
}
