/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:27:38 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/16 14:21:00 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = 0;
		i++;
	}
	free(str);
	str = 0;
}

void	free_machine(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->config.rows)
	{
		if (game->config.map[i])
			free(game->config.map[i]);
	}
	free(game->config.map);
	i = -1;
	while (++i < TEXTURES - 3)
	{
		if (game->config.tex[i].texture)
			free(game->config.tex[i].texture);
	}
}

void	free_one(void *s)
{
	free(s);
	s = 0;
}

void	all_free(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->sprite)
		free_one(game->sprite);
	if (game->buf)
		free_double((void *)game->buf);
	if (game->z_buf)
		free_one(game->z_buf);
	if (game->mlx && game->win)
		mlx_destroy_image(game->mlx, game->win);
	exit(0);
}
