/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:51:09 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 18:42:20 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		play_music(char *str)
{
	str += 0;
	system("afplay -v 0.30 music/underthesea.mp3 &");
}

void		stop_music(void)
{
	system("killall afplay");
}

void		put_info(t_game *game)
{
	char	*msg;
	char	*num;

	num = ft_itoa(game->player.move_speed * 100);
	msg = ft_strjoin("Move Speed : ", num);
	mlx_string_put(game->mlx, game->win, game->config.screenwidth \
		- 150, game->config.screenheight - 50, 0xFFFFFF, msg);
	free(msg);
	free(num);
	num = ft_itoa(3 - (game->config.sprite_num - 1));
	msg = ft_strjoin("How many flounders have you met?", num);
	mlx_string_put(game->mlx, game->win, 20, \
		game->config.screenheight - 50, 0xFFFFFF, msg);
	free(num);
	free(msg);
}
