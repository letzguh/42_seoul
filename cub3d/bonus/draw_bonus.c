/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:07:09 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 11:56:37 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_ceil_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->config.screenheight)
	{
		x = 0;
		while (x < game->config.screenwidth)
		{
			if (y > game->config.screenheight / 2 + game->config.eyelevel)
				game->buf[y][x] = game->config.floor_color;
			else
				game->buf[y][x] = game->config.ceiling_color;
			x++;
		}
		y++;
	}
}

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->config.screenheight)
	{
		x = 0;
		while (x < game->config.screenwidth)
		{
			game->img.data[y * game->config.screenwidth + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
}
