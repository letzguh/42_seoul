/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:56:49 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 11:56:17 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_sprite(t_game *g)
{
	int	x;
	int	y;
	int	i;

	if (!(g->sprite = (t_sprite_y *)malloc(sizeof(t_sprite_y)
						* g->config.sprite_num)))
		exit_error(g, EXIT_FAILURE, "Sprite Malloc Error");
	i = 0;
	y = 0;
	while (y < g->config.rows)
	{
		x = 0;
		while (x < g->config.colums)
		{
			if (g->config.map[y][x] == '2')
			{
				g->sprite[i].x = 0.5f + y;
				g->sprite[i].y = 0.5f + x;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	set_ray_item(t_game *g, int x)
{
	g->ray.camera_x = 2 * x / (double)g->config.screenwidth - 1;
	g->ray.dir_x = g->player.dir_x + g->player.plane_x * g->ray.camera_x;
	g->ray.dir_y = g->player.dir_y + g->player.plane_y * g->ray.camera_x;
	g->ray.map_x = (int)g->player.posx;
	g->ray.map_y = (int)g->player.posy;
	g->ray.delta_dist_x = fabs(1 / g->ray.dir_x);
	g->ray.delta_dist_y = fabs(1 / g->ray.dir_y);
	g->ray.hit = 0;
}
