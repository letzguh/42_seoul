/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:09:17 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 15:10:18 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		move_forward(t_player *p, char **map, int key)
{
	if (key == 1)
	{
		if (check_03(map[(int)(p->posx + p->dir_x * p->move_speed)]\
					[(int)(p->posy)]))
			p->posx += (p->dir_x) * p->move_speed;
		if (check_03(map[(int)(p->posx)][(int)(p->posy +  \
					p->dir_y * p->move_speed)]))
			p->posy += (p->dir_y) * p->move_speed;
	}
	if (key == -1)
	{
		if (check_03(map[(int)(p->posx - p->dir_x * p->move_speed)]\
					[(int)(p->posy)]))
			p->posx -= (p->dir_x) * p->move_speed;
		if (check_03(map[(int)(p->posx)][(int)(p->posy - \
					p->dir_y * p->move_speed)]))
			p->posy -= (p->dir_y) * p->move_speed;
	}
}

void		move_leftright(t_player *p, char **map, int key)
{
	if (key == 1)
	{
		if (check_03(map[(int)(p->posx)][(int)(p->posy \
				+ p->dir_x * p->move_speed)]))
			p->posy += p->dir_x * p->move_speed;
		if (check_03(map[(int)(p->posx - p->dir_y * \
			p->move_speed)][(int)p->posy]))
			p->posx -= p->dir_y * p->move_speed;
	}
	if (key == -1)
	{
		if (check_03(map[(int)p->posx][(int)(p->posy - \
			p->dir_x * p->move_speed)]))
			p->posy -= p->dir_x * p->move_speed;
		if (check_03(map[(int)(p->posx + p->dir_y * \
			p->move_speed)][(int)p->posy]))
			p->posx += p->dir_y * p->move_speed;
	}
}

void		rotate_right(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cos(-g->player.rot_speed) - \
		g->player.dir_y * sin(-g->player.rot_speed);
	g->player.dir_y = old_dir_x * sin(-g->player.rot_speed) + \
		g->player.dir_y * cos(-g->player.rot_speed);
	g->player.plane_x = g->player.plane_x * cos(-g->player.rot_speed) - \
		g->player.plane_y * sin(-g->player.rot_speed);
	g->player.plane_y = old_plane_x * sin(-g->player.rot_speed) + \
		g->player.plane_y * cos(-g->player.rot_speed);
}

void		rotate_left(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cos(g->player.rot_speed) - \
			g->player.dir_y * sin(g->player.rot_speed);
	g->player.dir_y = old_dir_x * sin(g->player.rot_speed) + \
			g->player.dir_y * cos(g->player.rot_speed);
	g->player.plane_x = g->player.plane_x * cos(g->player.rot_speed) - \
			g->player.plane_y * sin(g->player.rot_speed);
	g->player.plane_y = old_plane_x * sin(g->player.rot_speed) + \
			g->player.plane_y * cos(g->player.rot_speed);
}

void		move_player(t_game *game, t_player *p)
{
	double	newlevel;

	newlevel = game->config.eyelevel + p->eyelevel * 30;
	if (newlevel < game->config.screenheight / 4
			&& newlevel > -game->config.screenheight / 4)
		game->config.eyelevel = newlevel;
	if (p->walk_forward == 1)
		move_forward(&game->player, game->config.map, p->walk_forward);
	if (p->walk_forward == -1)
		move_forward(&game->player, game->config.map, p->walk_forward);
	if (p->move_lr == 1)
		move_leftright(&game->player, game->config.map, p->move_lr);
	if (p->move_lr == -1)
		move_leftright(&game->player, game->config.map, p->move_lr);
	if (p->turndirection == 1)
		rotate_right(game);
	if (p->turndirection == -1)
		rotate_left(game);
	meet_flounder(game, p);
}
