/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:27:53 by hbray             #+#    #+#             */
/*   Updated: 2026/06/03 10:53:10 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(t_img *img, int x, int y)
{
	char	*src;

	if (x > 0 && y > 0 && img->width > x && img->height > y)
	{
		src = img->data + (y * img->size_line + x * img->bpp / 8);
		return (*(int *)src);
	}
	return (0);
}

void	put_pixel(int x, int y, int color, t_cub *cub)
{
	char	*dst;

	if (x > 0 && y > 0 && cub->screen.width > x && cub->screen.height > y)
	{
		dst = cub->screen.data + (y * cub->screen.size_line + x
				* (cub->screen.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_door_start_y(t_cub *cub, int start_y)
{
	float	lvl;
	int		offset;

	lvl = get_door_lvl(cub, cub->dda.map_x, cub->dda.map_y);
	offset = (int)(cub->dda.wall_height * lvl);
	start_y += offset;
	return (start_y);
}
