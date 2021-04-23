/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raycasting_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:35:17 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 11:56:04 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		calc_step_direction(t_game *g)
{
	if (g->ray.dir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.side_dist_x = (g->player.posx - \
				g->ray.map_x) * g->ray.delta_dist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.side_dist_x = (g->ray.map_x + 1.0 \
				- g->player.posx) * g->ray.delta_dist_x;
	}
	if (g->ray.dir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.side_dist_y = (g->player.posy - \
				g->ray.map_y) * g->ray.delta_dist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.side_dist_y = (g->ray.map_y + 1.0 \
				- g->player.posy) * g->ray.delta_dist_y;
	}
}

void		perform_dda(t_game *g)
{
	while (g->ray.hit == 0)
	{
		if (g->ray.side_dist_x < g->ray.side_dist_y)
		{
			g->ray.side_dist_x += g->ray.delta_dist_x;
			g->ray.map_x += g->ray.step_x;
			if (g->ray.step_x == -1)
				g->ray.side = C_NO;
			else
				g->ray.side = C_SO;
		}
		else
		{
			g->ray.side_dist_y += g->ray.delta_dist_y;
			g->ray.map_y += g->ray.step_y;
			if (g->ray.step_y == -1)
				g->ray.side = C_WE;
			else
				g->ray.side = C_EA;
		}
		if (g->config.map[g->ray.map_x][g->ray.map_y] == '1')
			g->ray.hit = 1;
	}
}

void		calc_wall(t_game *g)
{
	if (g->ray.side <= 1)
		g->ray.perp_wall_dist = (g->ray.map_x - \
				g->player.posx + (1 - g->ray.step_x) / 2) / g->ray.dir_x;
	else
		g->ray.perp_wall_dist = (g->ray.map_y - \
				g->player.posy + (1 - g->ray.step_y) / 2) / g->ray.dir_y;
	g->ray.line_height = (int)(g->config.screenheight / g->ray.perp_wall_dist);
	g->ray.draw_start = -g->ray.line_height / 2 + g->config.screenheight / 2 \
					+ g->config.eyelevel;
	if (g->ray.draw_start < 0)
		g->ray.draw_start = 0;
	g->ray.draw_end = g->ray.line_height / 2 + \
				g->config.screenheight / 2 + g->config.eyelevel;
	if (g->ray.draw_end >= g->config.screenheight)
		g->ray.draw_end = g->config.screenheight - 1;
}

void		calc_texture(t_game *g, int x, int side, int y)
{
	int		color;
	double	height;

	if (g->ray.side <= 1)
		g->ray.wall_x = g->player.posy + \
					g->ray.perp_wall_dist * g->ray.dir_y;
	else
		g->ray.wall_x = g->player.posx + \
					g->ray.perp_wall_dist * g->ray.dir_x;
	g->ray.wall_x -= floor(g->ray.wall_x);
	g->ray.tex_x = (int)(g->ray.wall_x * g->config.tex[side].width);
	if (side == 1 || side == 2)
		g->ray.tex_x = (g->config.tex[side].width) - g->ray.tex_x - 1;
	height = g->config.tex[side].height;
	g->ray.step = 1.0 * g->config.tex[side].height / g->ray.line_height;
	g->ray.tex_pos = (g->ray.draw_start - g->config.screenheight / 2 + \
			g->ray.line_height / 2 - g->config.eyelevel) * g->ray.step;
	while (++y < g->ray.draw_end)
	{
		g->ray.tex_y = (int)g->ray.tex_pos & ((int)height - 1);
		g->ray.tex_pos += g->ray.step;
		color = g->config.tex[side].texture[(int)height \
			* g->ray.tex_y + g->ray.tex_x];
		g->buf[y][x] = color;
	}
}

void		calc_raycasting(t_game *g)
{
	int		x;

	x = 0;
	while (x < g->config.screenwidth)
	{
		set_ray_item(g, x);
		calc_step_direction(g);
		perform_dda(g);
		calc_wall(g);
		calc_texture(g, x, g->ray.side, g->ray.draw_start - 1);
		g->z_buf[x] = g->ray.perp_wall_dist;
		x++;
	}
}
