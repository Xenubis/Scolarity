/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:30:20 by hbray             #+#    #+#             */
/*   Updated: 2026/06/04 13:27:45 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_player	*create_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}

t_para	*create_para(void)
{
	t_para	*para;

	para = malloc(sizeof(t_para));
	if (!para)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(para, 0, sizeof(t_para));
	return (para);
}

t_ray	*create_ray(void)
{
	t_ray	*ray_men;

	ray_men = malloc(sizeof(t_ray));
	if (!ray_men)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(ray_men, 0, sizeof(t_ray));
	return (ray_men);
}

t_cub	*create_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(cub, 0, sizeof(t_cub));
	cub->player = create_player();
	if (!cub->player)
		return (free(cub), NULL);
	cub->ray_mem = create_ray();
	if (!cub->ray_mem)
		return (free(cub->player), free(cub), NULL);
	return (cub);
}
