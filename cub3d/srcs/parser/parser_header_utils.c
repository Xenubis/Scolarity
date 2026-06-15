/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:00:15 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/05 13:31:57 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pars_texture_cut(char *line, char *tmp, int i, t_para *para)
{
	int	fd;

	while (line[i])
	{
		if (!ft_is_space(line[i]))
		{
			free(tmp);
			error_pars("Error: invalid content\n", para);
		}
		i++;
	}
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		free(tmp);
		error_pars("Error: invalid file\n", para);
	}
	close(fd);
}

int	count_comma(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	verif_color(char **tab, t_para *para)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		end_split_color(tab, para);
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '\0')
			end_split_color(tab, para);
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				end_split_color(tab, para);
			j++;
			if (j > 3)
				end_split_color(tab, para);
		}
		i++;
	}
}

void	pars_color_cut(char *line, char *tmp, int i, t_para *para)
{
	while (line[i])
	{
		if (!ft_is_space(line[i]))
		{
			free(tmp);
			error_pars("Error: invalid content\n", para);
		}
		i++;
	}
}

void	end_split_color(char **tab, t_para *para)
{
	free_tab(tab);
	error_pars("Error: wrong color format\n", para);
}
