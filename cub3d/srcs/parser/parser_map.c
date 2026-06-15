/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:18:44 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 11:16:00 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	malloc_map(char **line, int i, t_para *para)
{
	int	n;

	n = 0;
	while (line[i + n])
		n++;
	para->map = ft_calloc(n + 1, sizeof(char *));
	if (!para->map)
		error_pars("Error: malloc failed\n", para);
}

void	add_line_map(char *line, t_para *para)
{
	para->map[para->i_map] = ft_strdup(line);
	if (!para->map[para->i_map])
		error_pars("Error: malloc failed\n", para);
	para->i_map++;
}
