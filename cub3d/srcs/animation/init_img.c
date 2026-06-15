/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:07:40 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 11:25:09 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_img_5(t_cub *cub)
{
	cub->exit_texture[4].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/exit_texture_frame_5.xpm", &cub->exit_texture[4].width,
			&cub->exit_texture[4].height);
	cub->exit_texture[4].data = mlx_get_data_addr(cub->exit_texture[4].img,
			&cub->exit_texture[4].bpp, &cub->exit_texture[4].size_line,
			&cub->exit_texture[4].endian);
	cub->exit_texture[5].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/exit_texture_frame_6.xpm", &cub->exit_texture[5].width,
			&cub->exit_texture[5].height);
	cub->exit_texture[5].data = mlx_get_data_addr(cub->exit_texture[5].img,
			&cub->exit_texture[5].bpp, &cub->exit_texture[5].size_line,
			&cub->exit_texture[5].endian);
}

static void	init_img_4(t_cub *cub)
{
	cub->exit_texture[0].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/exit_texture_frame_1.xpm", &cub->exit_texture[0].width,
			&cub->exit_texture[0].height);
	cub->exit_texture[0].data = mlx_get_data_addr(cub->exit_texture[0].img,
			&cub->exit_texture[0].bpp, &cub->exit_texture[0].size_line,
			&cub->exit_texture[0].endian);
	cub->exit_texture[1].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/exit_texture_frame_2.xpm", &cub->exit_texture[1].width,
			&cub->exit_texture[1].height);
	cub->exit_texture[1].data = mlx_get_data_addr(cub->exit_texture[1].img,
			&cub->exit_texture[1].bpp, &cub->exit_texture[1].size_line,
			&cub->exit_texture[1].endian);
	cub->exit_texture[2].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/exit_texture_frame_3.xpm", &cub->exit_texture[2].width,
			&cub->exit_texture[2].height);
	cub->exit_texture[2].data = mlx_get_data_addr(cub->exit_texture[2].img,
			&cub->exit_texture[2].bpp, &cub->exit_texture[2].size_line,
			&cub->exit_texture[2].endian);
	cub->exit_texture[3].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/exit_texture_frame_4.xpm", &cub->exit_texture[3].width,
			&cub->exit_texture[3].height);
	cub->exit_texture[3].data = mlx_get_data_addr(cub->exit_texture[3].img,
			&cub->exit_texture[3].bpp, &cub->exit_texture[3].size_line,
			&cub->exit_texture[3].endian);
	init_img_5(cub);
}

static void	init_img_3(t_cub *cub)
{
	cub->hud_texture[2].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/character_frame_3.xpm", &cub->hud_texture[2].width,
			&cub->hud_texture[2].height);
	cub->hud_texture[2].data = mlx_get_data_addr(cub->hud_texture[2].img,
			&cub->hud_texture[2].bpp, &cub->hud_texture[2].size_line,
			&cub->hud_texture[2].endian);
	cub->hud_texture[3].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/character_frame_4.xpm", &cub->hud_texture[3].width,
			&cub->hud_texture[3].height);
	cub->hud_texture[3].data = mlx_get_data_addr(cub->hud_texture[3].img,
			&cub->hud_texture[3].bpp, &cub->hud_texture[3].size_line,
			&cub->hud_texture[3].endian);
	cub->hud_texture[4].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/character_frame_5.xpm", &cub->hud_texture[4].width,
			&cub->hud_texture[4].height);
	cub->hud_texture[4].data = mlx_get_data_addr(cub->hud_texture[4].img,
			&cub->hud_texture[4].bpp, &cub->hud_texture[4].size_line,
			&cub->hud_texture[4].endian);
	cub->hud_texture[5].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/character_frame_6.xpm", &cub->hud_texture[5].width,
			&cub->hud_texture[5].height);
	cub->hud_texture[5].data = mlx_get_data_addr(cub->hud_texture[5].img,
			&cub->hud_texture[5].bpp, &cub->hud_texture[5].size_line,
			&cub->hud_texture[5].endian);
	init_img_4(cub);
}

static void	init_img_2(t_cub *cub)
{
	cub->col_texture[4].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_5.xpm", &cub->col_texture[4].width,
			&cub->col_texture[4].height);
	cub->col_texture[4].data = mlx_get_data_addr(cub->col_texture[4].img,
			&cub->col_texture[4].bpp, &cub->col_texture[4].size_line,
			&cub->col_texture[4].endian);
	cub->col_texture[5].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_6.xpm", &cub->col_texture[5].width,
			&cub->col_texture[5].height);
	cub->col_texture[5].data = mlx_get_data_addr(cub->col_texture[5].img,
			&cub->col_texture[5].bpp, &cub->col_texture[5].size_line,
			&cub->col_texture[5].endian);
	cub->hud_texture[0].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/character_frame_1.xpm", &cub->hud_texture[0].width,
			&cub->hud_texture[0].height);
	cub->hud_texture[0].data = mlx_get_data_addr(cub->hud_texture[0].img,
			&cub->hud_texture[0].bpp, &cub->hud_texture[0].size_line,
			&cub->hud_texture[0].endian);
	cub->hud_texture[1].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/character_frame_2.xpm", &cub->hud_texture[1].width,
			&cub->hud_texture[1].height);
	cub->hud_texture[1].data = mlx_get_data_addr(cub->hud_texture[1].img,
			&cub->hud_texture[1].bpp, &cub->hud_texture[1].size_line,
			&cub->hud_texture[1].endian);
	init_img_3(cub);
}

void	init_img_1(t_cub *cub)
{
	cub->col_texture[0].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_1.xpm", &cub->col_texture[0].width,
			&cub->col_texture[0].height);
	cub->col_texture[0].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[0].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[0].endian);
	cub->col_texture[1].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_2.xpm", &cub->col_texture[1].width,
			&cub->col_texture[1].height);
	cub->col_texture[1].data = mlx_get_data_addr(cub->col_texture[1].img,
			&cub->col_texture[1].bpp, &cub->col_texture[1].size_line,
			&cub->col_texture[1].endian);
	cub->col_texture[2].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_3.xpm", &cub->col_texture[2].width,
			&cub->col_texture[2].height);
	cub->col_texture[2].data = mlx_get_data_addr(cub->col_texture[2].img,
			&cub->col_texture[2].bpp, &cub->col_texture[2].size_line,
			&cub->col_texture[2].endian);
	cub->col_texture[3].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_4.xpm", &cub->col_texture[3].width,
			&cub->col_texture[3].height);
	cub->col_texture[3].data = mlx_get_data_addr(cub->col_texture[3].img,
			&cub->col_texture[3].bpp, &cub->col_texture[3].size_line,
			&cub->col_texture[3].endian);
	init_img_2(cub);
}
