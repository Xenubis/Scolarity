/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:45:50 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/03 12:48:04 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_hud_col_color(int *color, int collected)
{
	int	gray;

	gray = 0;
	if (collected == 1)
	{
		gray = (((*color >> 16) & 0xFF) + ((*color >> 8) & 0xFF)
				+ (*color & 0xFF)) / 3;
		*color = (gray << 16) | (gray << 8) | gray;
	}
}

static void	draw_hud_col(int index, int collected, t_cub *cub)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	color = 0;
	while (++y < HUD_SIZE)
	{
		x = 0;
		while (x < HUD_SIZE)
		{
			color = get_color(&cub->col_texture[0], x
					* cub->col_texture[0].width / HUD_SIZE, y
					* cub->col_texture[0].height / HUD_SIZE);
			if (color == -16777216 || color == 0)
			{
				x++;
				continue ;
			}
			draw_hud_col_color(&color, collected);
			put_pixel(cub->screen.width - HUD_MARGE - (index + 1) * (HUD_SIZE
					+ HUD_SPACING) + x, HUD_MARGE + y, color, cub);
			x++;
		}
	}
}

void	render_hud(t_cub *cub)
{
	float	start_x;
	float	start_y;
	int		color;
	int		y;
	int		x;

	start_x = cub->screen.width / 2 - cub->hud_texture->width / 2;
	start_y = cub->screen.height - cub->hud_texture->height;
	y = 0;
	while (y < cub->hud_texture->height)
	{
		x = 0;
		while (x < cub->hud_texture->width)
		{
			color = get_color(&cub->hud_texture[cub->hud_anim.current_frame], x,
					y);
			if (color != 0 && color != -16777216)
				put_pixel(start_x + x, start_y + y, color, cub);
			x++;
		}
		y++;
	}
	x = -1;
	while (++x < cub->para->nb_collec)
		draw_hud_col(x, cub->col[x].collect, cub);
}
