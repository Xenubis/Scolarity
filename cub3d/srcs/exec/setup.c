/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:38:28 by hbray             #+#    #+#             */
/*   Updated: 2026/06/04 10:23:22 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_win2(t_cub *cub)
{
	cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx, cub->para->ea_t,
			&cub->texture[3].width, &cub->texture[3].height);
	cub->texture[3].data = mlx_get_data_addr(cub->texture[3].img,
			&cub->texture[3].bpp, &cub->texture[3].size_line,
			&cub->texture[3].endian);
	cub->texture[4].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/door_texture.xpm", &cub->texture[4].width,
			&cub->texture[4].height);
	cub->texture[4].data = mlx_get_data_addr(cub->texture[4].img,
			&cub->texture[4].bpp, &cub->texture[4].size_line,
			&cub->texture[4].endian);
}

void	init_win(t_cub *cub)
{
	cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx, cub->para->no_t,
			&cub->texture[0].width, &cub->texture[0].height);
	cub->texture[0].data = mlx_get_data_addr(cub->texture[0].img,
			&cub->texture[0].bpp, &cub->texture[0].size_line,
			&cub->texture[0].endian);
	cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx, cub->para->so_t,
			&cub->texture[1].width, &cub->texture[1].height);
	cub->texture[1].data = mlx_get_data_addr(cub->texture[1].img,
			&cub->texture[1].bpp, &cub->texture[1].size_line,
			&cub->texture[1].endian);
	cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx, cub->para->we_t,
			&cub->texture[2].width, &cub->texture[2].height);
	cub->texture[2].data = mlx_get_data_addr(cub->texture[2].img,
			&cub->texture[2].bpp, &cub->texture[2].size_line,
			&cub->texture[2].endian);
	init_win2(cub);
}

void	open_win(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		write(2, "Error: MLX initialization failed\n", 34);
		close_win(cub);
	}
	init_win(cub);
	init_img_1(cub);
	mlx_get_screen_size(cub->mlx, &cub->screen.width, &cub->screen.height);
	cub->win = mlx_new_window(cub->mlx, cub->screen.width, cub->screen.height,
			"Cub3d");
	if (!cub->win)
	{
		write(2, "Error: Window creation failed\n", 31);
		close_win(cub);
	}
	cub->screen.img = mlx_new_image(cub->mlx, cub->screen.width,
			cub->screen.height);
	if (!cub->screen.img)
	{
		write(2, "Error: Image creation failed\n", 30);
		close_win(cub);
	}
	cub->screen.data = mlx_get_data_addr(cub->screen.img, &cub->screen.bpp,
			&cub->screen.size_line, &cub->screen.endian);
}

int	init_ray_mem(t_cub *cub, t_para *para)
{
	cub->ray_mem->x = malloc(sizeof(int) * para->nb_door);
	cub->ray_mem->y = malloc(sizeof(int) * para->nb_door);
	cub->ray_mem->dda = malloc(sizeof(t_dda) * para->nb_door);
	if (!cub->ray_mem->x || !cub->ray_mem->y || !cub->ray_mem->dda)
		return (1);
	return (0);
}

int	init_doors(t_cub *cub, t_para *para)
{
	int	i;
	int	j;
	int	k;

	cub->door = malloc(sizeof(t_door) * para->nb_door);
	if (!cub->door || init_ray_mem(cub, para) == 1)
		return (1);
	ft_memset(cub->door, 0, sizeof(t_door) * para->nb_door);
	i = -1;
	k = 0;
	while (para->map[++i])
	{
		j = -1;
		while (para->map[i][++j])
		{
			if (para->map[i][j] == 'D')
			{
				cub->door[k].x = j;
				cub->door[k].y = i;
				k++;
			}
		}
	}
	return (0);
}
