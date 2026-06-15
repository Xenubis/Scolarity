/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:13:18 by hbray             #+#    #+#             */
/*   Updated: 2026/06/05 09:20:49 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_para(t_para **para)
{
	if (!para || !(*para))
		return ;
	free_tab((*para)->stock);
	(*para)->stock = NULL;
	free_tab((*para)->map);
	(*para)->map = NULL;
	free((*para)->no_t);
	(*para)->no_t = NULL;
	free((*para)->so_t);
	(*para)->so_t = NULL;
	free((*para)->we_t);
	(*para)->we_t = NULL;
	free((*para)->ea_t);
	(*para)->ea_t = NULL;
	free(*para);
}

void	free_player(t_player **player)
{
	if (!player || !(*player))
		return ;
	free(*player);
}

void	free_ray(t_ray **ray)
{
	if (!ray || !(*ray))
		return ;
	if ((*ray)->x)
		free((*ray)->x);
	if ((*ray)->y)
		free((*ray)->y);
	if ((*ray)->dda)
		free((*ray)->dda);
	free(*ray);
}

void	free_cub(t_cub **cub)
{
	if (!cub || !(*cub))
		return ;
	destroy_image_1(cub);
	destroy_image_2(cub);
	if ((*cub)->col)
		free((*cub)->col);
	if ((*cub)->player)
		free_player(&(*cub)->player);
	free((*cub)->door);
	if (((*cub)->ray_mem))
		free_ray(&(*cub)->ray_mem);
	free(*cub);
}

void	all_free(t_para **para, t_cub **cub)
{
	free_para(para);
	free_cub(cub);
}
