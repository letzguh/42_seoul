/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meet_flounder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:08:16 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 15:56:00 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			meet_flounder(t_game *g, t_player *p)
{
	t_sprite_y	tmp;

	if (g->config.map[(int)p->posx][(int)p->posy] == '3')
	{
		tmp = g->sprite[g->config.sprite_num - 1];
		g->sprite[g->config.sprite_num - 1] = g->sprite[0];
		g->sprite[0] = g->sprite[g->config.sprite_num - 1];
		g->config.sprite_num--;
		g->config.map[(int)p->posx][(int)p->posy] = '0';
	}
}

int				check_03(char c)
{
	if (c == '0' || c == '3')
		return (1);
	return (0);
}
