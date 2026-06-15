/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:21 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 11:14:58 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_line_fd(char *path, t_para *para)
{
	int		fd;
	char	*line;
	int		n_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_pars("Error: cannot open file\n", para);
	n_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		n_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (n_line == 0)
		error_pars("Error: empty file\n", para);
	return (n_line);
}

void	do_gnl(t_para *para)
{
	int		fd;
	char	*line;
	int		i;
	int		len;

	i = 0;
	para->stock = malloc(sizeof(char *) * (count_line_fd(para->path, para)
				+ 1));
	if (!para->stock)
		error_pars("Error: malloc fail\n", para);
	fd = open(para->path, O_RDONLY);
	if (fd < 0)
		error_pars("Error: cannot open file\n", para);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		para->stock[i] = line;
		line = get_next_line(fd);
		i++;
	}
	para->stock[i] = NULL;
	close(fd);
}

void	parsing(t_para *para)
{
	do_gnl(para);
	do_parsing(para);
	map_validation(para);
}
