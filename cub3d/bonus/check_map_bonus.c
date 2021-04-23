/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:16:45 by sohee             #+#    #+#             */
/*   Updated: 2021/03/18 15:42:58 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_values(t_game *game)
{
	int i;

	if (!game->config.screenwidth || !game->config.screenheight)
		return (exit_error(game, EXIT_FAILURE, "Need info on Screensize"));
	if (!game->config.rows || !game->config.colums || !game->config.tile)
		return (exit_error(game, EXIT_FAILURE, "Need info on map"));
	if ((game->config.floor_color < 0) || (game->config.ceiling_color < 0))
		return (exit_error(game, EXIT_FAILURE, "Color part error1"));
	i = -1;
	while (++i < TEXTURES - 3)
	{
		if (!game->config.tex[i].tex_path)
			return (exit_error(game, EXIT_FAILURE, "Tex_path error"));
	}
	if (game->config.istype[C_C] != 1 || game->config.istype[C_F] != 1)
		return (exit_error(game, EXIT_FAILURE, "Color part error2"));
	return (1);
}

void	set_player_direction(t_player *player, double radian)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->dir_x;
	player->dir_x = tmp_dir_x * cos(radian) - player->dir_y * sin(radian);
	player->dir_y = tmp_dir_x * sin(radian) + player->dir_y * cos(radian);
	tmp_plane_x = player->plane_x;
	player->plane_x = tmp_plane_x * cos(radian) - player->plane_y * sin(radian);
	player->plane_y = tmp_plane_x * sin(radian) + player->plane_y * cos(radian);
}

int		set_playerpos(t_game *g, int i, int j)
{
	char	c;
	double	tmp_angle;

	if (g->player.posx || g->player.posy)
		return (0);
	g->player.direction = g->config.map[i][j];
	c = g->player.direction;
	if (c == 'W')
		tmp_angle = 0;
	else if (c == 'S')
		tmp_angle = 90;
	else if (c == 'E')
		tmp_angle = 180;
	else
		tmp_angle = 270;
	set_player_direction(&g->player, tmp_angle * (M_PI / 180));
	g->player.posx = i + 0.5f;
	g->player.posy = j + 0.5f;
	g->config.map[(int)g->player.posx][(int)g->player.posy] = '0';
	return (1);
}

int		check_02(t_game *g, int i, int j)
{
	if (g->config.map[i][j] == '2')
		g->config.sprite_num++;
	if (g->config.map[i][j] == '3')
		g->config.sprite_num++;
	if (i <= 0 || i >= g->config.rows - 1 || \
		j <= 0 || j >= g->config.colums - 1)
		return (0);
	else if (g->config.map[i][j + 1] == ' '
	|| g->config.map[i][j + 1] == '\0' || g->config.map[i][j - 1] == ' ')
		return (0);
	else if ((int)ft_strlen(g->config.map[i - 1]) <= j
	|| g->config.map[i - 1][j] == ' ' || g->config.map[i - 1][j] == '\0')
		return (0);
	else if ((int)ft_strlen(g->config.map[i + 1]) <= j
	|| g->config.map[i + 1][j] == ' ' || g->config.map[i + 1][j] == '\0')
		return (0);
	return (1);
}

int		check_map_validation(t_game *g, t_config c)
{
	static int	i = -1;
	int			j;

	while (g->config.map[++i])
	{
		j = -1;
		while (g->config.map[i][++j])
		{
			if (ft_strchr("NSWE", g->config.map[i][j]))
			{
				if (!set_playerpos(g, i, j))
					return (0);
			}
			else if (check_03(c.map[i][j]) == 1 || c.map[i][j] == '2')
			{
				if (!check_02(g, i, j))
					return (0);
			}
			else if (ft_strchr("1 ", g->config.map[i][j]))
				continue;
			else
				return (0);
		}
	}
	return (1);
}
