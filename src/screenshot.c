/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:01:29 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/16 18:09:25 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			screenshot(t_game *g)
{
	int		pixel_bytes_per_row;

	draw_ceil_floor(g);
	calc_raycasting(g);
	calc_sprite(g);
	draw(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	pixel_bytes_per_row = g->config.screenwidth * 3;
	return (1);
}
