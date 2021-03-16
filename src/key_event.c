/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:16:45 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/16 14:22:02 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_bonus(int key_code, t_game *game)
{
	if (key_code == KEY_UP)
		game->player.eyelevel = 1;
	else if (key_code == KEY_DOWN)
		game->player.eyelevel = -1;
	else if (key_code == KEY_MINUS)
		game->player.move_speed > 0.02 ? game->player.move_speed -= 0.006 : 0;
	else if (key_code == KEY_PLUS)
		game->player.move_speed < 0.1 ? game->player.move_speed += 0.006 : 0;
	return (0);
}

int			key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
	{
		free_machine(game);
		exit(0);
	}
	else if (key_code == KEY_W)
		game->player.walk_forward = 1;
	else if (key_code == KEY_S)
		game->player.walk_forward = -1;
	else if (key_code == KEY_A)
		game->player.move_lr = 1;
	else if (key_code == KEY_D)
		game->player.move_lr = -1;
	else if (key_code == KEY_RIGHT)
		game->player.turndirection = 1;
	else if (key_code == KEY_LEFT)
		game->player.turndirection = -1;
	key_press_bonus(key_code, game);
	return (0);
}

/*
** static int	key_release_bonus(int key_code, t_game *game)
** {
** 	if (key_code == KEY_UP)
** 		game->player.eyelevel = 0;
** 	else if (key_code == KEY_DOWN)
** 		game->player.eyelevel = 0;
** 	return (0);
** }
*/

int			key_release(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->player.walk_forward = 0;
	else if (key_code == KEY_S)
		game->player.walk_forward = 0;
	else if (key_code == KEY_A)
		game->player.move_lr = 0;
	else if (key_code == KEY_D)
		game->player.move_lr = 0;
	else if (key_code == KEY_RIGHT)
		game->player.turndirection = 0;
	else if (key_code == KEY_LEFT)
		game->player.turndirection = 0;
	key_press_bonus(key_code, game);
	return (0);
}
