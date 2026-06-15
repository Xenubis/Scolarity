/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dispatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:35:25 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 11:00:20 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	build_map(int i, t_para *para)
{
	if (is_line_space(para->stock[i]))
		error_pars("Error: empty line in map\n", para);
	else if (is_only_map_char(i, para))
		add_line_map(para->stock[i], para);
	else
		error_pars("Error: wrong character\n", para);
}

static int	dispatch_sprite(int i, int *mode, t_para *para)
{
	if (is_line_space(para->stock[i]))
		return (1);
	else if (is_header(i, para) > 0)
	{
		pars_header(para->stock[i], para);
		return (1);
	}
	else if (is_only_map_char(i, para))
	{
		if (is_header_complete(para))
		{
			malloc_map(para->stock, i, para);
			*mode = MAP;
		}
		else
			error_pars("Error: missing header\n", para);
	}
	else
		error_pars("Error: invalid line\n", para);
	return (0);
}

void	do_parsing(t_para *para)
{
	int	i;
	int	mode;

	mode = SPRITE;
	i = 0;
	while (para->stock[i])
	{
		if (mode == SPRITE)
		{
			if (dispatch_sprite(i, &mode, para))
			{
				i++;
				continue ;
			}
		}
		if (mode == MAP)
			build_map(i, para);
		i++;
	}
	if (mode != MAP)
		error_pars("Error: no map\n", para);
}
