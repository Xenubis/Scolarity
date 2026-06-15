/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:05:30 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 16:42:12 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pars_header(char *line, t_para *para)
{
	if (para->header == NO)
		pars_texture(line, &para->no_t, para);
	if (para->header == SO)
		pars_texture(line, &para->so_t, para);
	if (para->header == WE)
		pars_texture(line, &para->we_t, para);
	if (para->header == EA)
		pars_texture(line, &para->ea_t, para);
	if (para->header == F)
		pars_color(line, &para->floor_c, para);
	if (para->header == C)
		pars_color(line, &para->ceiling_c, para);
}

void	pars_texture(char *line, char **path, t_para *para)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (*path != NULL)
		error_pars("Error: duplicate identifier\n", para);
	while (line[i] && ft_is_space(line[i]))
		i++;
	i += 2;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == '\0')
		error_pars("Error: empty path\n", para);
	j = i;
	while (line[i] && !ft_is_space(line[i]))
		i++;
	tmp = ft_substr(line, j, i - j);
	if (!tmp)
		error_pars("Error: malloc fail\n", para);
	pars_texture_cut(line, tmp, i, para);
	*path = tmp;
}

int	color_split(char *tmp, t_para *para)
{
	char	**tab;
	int		r;
	int		g;
	int		b;

	tab = NULL;
	if (count_comma(tmp, ',') != 2 || tmp[0] == ',' || tmp[ft_strlen(tmp)
			- 1] == ',' || ft_strnstr(tmp, ",,", ft_strlen(tmp)) != NULL)
		error_pars("Error: wrong color format\n", para);
	tab = ft_split(tmp, ',');
	verif_color(tab, para);
	r = ft_atoi(tab[0]);
	if (r < 0 || r > 255)
		end_split_color(tab, para);
	g = ft_atoi(tab[1]);
	if (g < 0 || g > 255)
		end_split_color(tab, para);
	b = ft_atoi(tab[2]);
	if (b < 0 || b > 255)
		end_split_color(tab, para);
	free_tab(tab);
	return ((r << 16) | (g << 8) | b);
}

void	pars_color(char *line, int *color, t_para *para)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (*color != -1)
		error_pars("Error: duplicate color\n", para);
	while (line[i] && ft_is_space(line[i]))
		i++;
	i += 2;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == '\0')
		error_pars("Error: empty color\n", para);
	j = i;
	while (line[i] && !ft_is_space(line[i]))
		i++;
	tmp = ft_substr(line, j, i - j);
	if (!tmp)
		error_pars("Error: malloc fail\n", para);
	pars_color_cut(line, tmp, i, para);
	*color = color_split(tmp, para);
	free(tmp);
}
