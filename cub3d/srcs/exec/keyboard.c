/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:58:27 by hbray             #+#    #+#             */
/*   Updated: 2026/06/03 10:34:20 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	t_player	*player;

	player = cub->player;
	if (keycode == ESC)
		close_win(cub);
	if (keycode == SPACE)
		open_door(cub);
	if (keycode == C)
		mouse(cub);
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->rotate_left = true;
	if (keycode == RIGHT)
		player->rotate_right = true;
	if (keycode == SPACE)
		finish_game(cub);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->rotate_left = false;
	if (keycode == RIGHT)
		player->rotate_right = false;
	return (0);
}
