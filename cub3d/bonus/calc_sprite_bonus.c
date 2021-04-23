/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:43:32 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 16:19:27 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	sort_sprite(t_game *g)
{
	int			i;
	int			j;
	t_sprite_y	tmp;

	i = -1;
	while (++i < g->config.sprite_num)
	{
		g->sprite[i].distance = ((g->player.posx - g->sprite[i].x) * \
			(g->player.posx - g->sprite[i].x) + (g->player.posy - \
			g->sprite[i].y) * (g->player.posy - g->sprite[i].y));
	}
	i = -1;
	while (++i < g->config.sprite_num - 1)
	{
		j = -1;
		while (++j < g->config.sprite_num - 1 - i)
		{
			if (g->sprite[j].distance < g->sprite[j + 1].distance)
			{
				tmp = g->sprite[j];
				g->sprite[j] = g->sprite[j + 1];
				g->sprite[j + 1] = tmp;
			}
		}
	}
}

void	translate_sprite_pos(t_game *g, int i)
{
	g->ray_sprite.relative_dist_x = g->sprite[i].x - g->player.posx;
	g->ray_sprite.relative_dist_y = g->sprite[i].y - g->player.posy;
	g->ray_sprite.inverse_determinant = 1.0 / (g->player.dir_y * \
		g->player.plane_x - g->player.dir_x * g->player.plane_y);
	g->ray_sprite.trans_x = g->ray_sprite.inverse_determinant * \
		(g->player.dir_y * g->ray_sprite.relative_dist_x \
		- g->player.dir_x * g->ray_sprite.relative_dist_y);
	g->ray_sprite.trans_y = g->ray_sprite.inverse_determinant * \
		(-g->player.plane_y * g->ray_sprite.relative_dist_x + \
		g->player.plane_x * g->ray_sprite.relative_dist_y);
	g->ray_sprite.screen_x = (int)((g->config.screenwidth / 2) * \
		(1 + g->ray_sprite.trans_x / g->ray_sprite.trans_y));
}

void	calc_sprite_height_width(t_game *g)
{
	g->ray_sprite.height = abs((int)(g->config.screenheight \
					/ g->ray_sprite.trans_y));
	g->ray_sprite.draw_start_y = -g->ray_sprite.height / 2 \
					+ g->config.screenheight / 2 + g->config.eyelevel;
	if (g->ray_sprite.draw_start_y < 0)
		g->ray_sprite.draw_start_y = 0;
	g->ray_sprite.draw_end_y = g->ray_sprite.height / 2 \
					+ g->config.screenheight / 2 + g->config.eyelevel;
	if (g->ray_sprite.draw_end_y >= g->config.screenheight)
		g->ray_sprite.draw_end_y = g->config.screenheight - 1;
	g->ray_sprite.width = abs((int)(g->config.screenheight / \
					g->ray_sprite.trans_y));
	g->ray_sprite.draw_start_x = -g->ray_sprite.width / 2 \
					+ g->ray_sprite.screen_x;
	if (g->ray_sprite.draw_start_x < 0)
		g->ray_sprite.draw_start_x = 0;
	g->ray_sprite.draw_end_x = g->ray_sprite.width / 2 \
					+ g->ray_sprite.screen_x;
	if (g->ray_sprite.draw_end_x >= g->config.screenwidth)
		g->ray_sprite.draw_end_x = g->config.screenwidth - 1;
}

void	sprite_on_screen(t_game *g, int x, int height, t_tex tmp)
{
	int	draw;
	int	color;
	int	y;

	g->ray_sprite.tex_x = (int)((256 * (x - (-g->ray_sprite.width / 2 \
		+ g->ray_sprite.screen_x)) * g->config.tex[C_S].width \
			/ g->ray_sprite.width) / 256);
	if (g->ray_sprite.trans_y > 0 && x > 0 && \
		x < g->config.screenwidth && g->ray_sprite.trans_y < g->z_buf[x])
	{
		y = g->ray_sprite.draw_start_y;
		while (y < g->ray_sprite.draw_end_y)
		{
			draw = (y - g->config.eyelevel) * 256 - \
				(g->config.screenheight) * 128 + g->ray_sprite.height * 128;
			g->ray_sprite.tex_y = ((draw * height) / \
				g->ray_sprite.height) / 256;
			color = tmp.texture[(int)tmp.width * \
				g->ray_sprite.tex_y + g->ray_sprite.tex_x];
			if ((color & 0X00FFFFFF) != 0)
				g->buf[y][x] = color;
			y++;
		}
	}
}

void	calc_sprite(t_game *g)
{
	int		i;
	int		stripe;
	int		type;
	t_tex	tmp;

	sort_sprite(g);
	i = 0;
	while (i < g->config.sprite_num)
	{
		type = g->sprite[i].c_type;
		tmp = g->config.tex[type];
		translate_sprite_pos(g, i);
		calc_sprite_height_width(g);
		stripe = g->ray_sprite.draw_start_x;
		while (stripe < g->ray_sprite.draw_end_x)
		{
			sprite_on_screen(g, stripe, tmp.height, tmp);
			stripe++;
		}
		i++;
	}
}
