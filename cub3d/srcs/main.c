/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:58:29 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/05 10:01:43 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	setup(int ac, char **av, t_para *para)
{
	int	i;

	para->floor_c = -1;
	para->ceiling_c = -1;
	if (ac != 2)
		error_pars("Error: invalid arguments\n", para);
	para->path = av[1];
	i = ft_strlen(para->path);
	if (i < 5)
		error_pars("Usage: path/name_map.cub\n", para);
	if (ft_strncmp(para->path + i - 4, ".cub", 4) != 0)
		error_pars("Usage: path/name_map.cub\n", para);
	if (para->path[i - 5] == '/')
		error_pars("Usage: path/name_map.cub\n", para);
}

int	close_win(t_cub *cub)
{
	t_para	*para_tmp;
	void	*mlx_tmp;

	para_tmp = NULL;
	mlx_tmp = NULL;
	if (cub)
	{
		para_tmp = cub->para;
		mlx_tmp = cub->mlx;
	}
	if (cub && cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
	if (cub && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	all_free(&para_tmp, &cub);
	if (mlx_tmp)
	{
		mlx_destroy_display(mlx_tmp);
		free(mlx_tmp);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;
	t_para	*para;

	cub = create_cub();
	cub->time = get_time();
	para = create_para();
	if (!cub || !para)
		return (all_free(&para, &cub), 1);
	para->cub = cub;
	cub->para = para;
	setup(ac, av, para);
	parsing(para);
	if (init_doors(cub, para))
		return (all_free(&para, &cub), 1);
	open_win(cub);
	pixar(cub);
	mlx_hook(cub->win, 17, 0, (int (*)(void))(void *)close_win, cub);
	mlx_hook(cub->win, 2, 1L << 0, (int (*)(void))(void *)key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, (int (*)(void))(void *)key_release,
		cub->player);
	mlx_hook(cub->win, 6, 1L << 6, (int (*)(void))(void *)mouse_handler, cub);
	mlx_loop_hook(cub->mlx, (int (*)(void))(void *)draw_loop, cub);
	mlx_loop(cub->mlx);
	all_free(&para, &cub);
	return (0);
}
