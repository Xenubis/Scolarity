/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:08:53 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/01 16:22:16 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixar(t_cub *cub)
{
	t_col	*col;

	col = create_col(cub);
	init_hud(cub);
	init_exit(cub);
	cub->col = col;
}

void	anim_maj(t_anim *anim, double time)
{
	if ((time - anim->last_frame) < anim->time_b_frame)
		return ;
	else
	{
		anim->last_frame = time;
		if (anim->current_frame == anim->frame_count - 1)
			anim->current_frame = 0;
		else
			anim->current_frame++;
	}
}
