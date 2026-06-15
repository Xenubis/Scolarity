/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:35:10 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/02 15:06:54 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_image_1(t_cub **cub)
{
	if ((*cub)->texture[0].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[0].img);
	if ((*cub)->texture[1].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[1].img);
	if ((*cub)->texture[2].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[2].img);
	if ((*cub)->texture[3].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[3].img);
	if ((*cub)->texture[4].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[4].img);
	if ((*cub)->col_texture[0].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->col_texture[0].img);
	if ((*cub)->col_texture[1].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->col_texture[1].img);
	if ((*cub)->col_texture[2].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->col_texture[2].img);
	if ((*cub)->col_texture[3].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->col_texture[3].img);
	if ((*cub)->col_texture[4].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->col_texture[4].img);
	if ((*cub)->col_texture[5].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->col_texture[5].img);
}

void	destroy_image_2(t_cub **cub)
{
	if ((*cub)->hud_texture[0].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->hud_texture[0].img);
	if ((*cub)->hud_texture[1].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->hud_texture[1].img);
	if ((*cub)->hud_texture[2].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->hud_texture[2].img);
	if ((*cub)->hud_texture[3].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->hud_texture[3].img);
	if ((*cub)->hud_texture[4].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->hud_texture[4].img);
	if ((*cub)->hud_texture[5].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->hud_texture[5].img);
	if ((*cub)->exit_texture[0].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->exit_texture[0].img);
	if ((*cub)->exit_texture[1].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->exit_texture[1].img);
	if ((*cub)->exit_texture[2].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->exit_texture[2].img);
	if ((*cub)->exit_texture[3].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->exit_texture[3].img);
	if ((*cub)->exit_texture[4].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->exit_texture[4].img);
	if ((*cub)->exit_texture[5].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->exit_texture[5].img);
}
