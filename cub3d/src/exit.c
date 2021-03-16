/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:49:03 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/16 17:52:15 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_error(t_game *game, int code, char const *str)
{
	write(1, "Error\n", 6);
	if (str)
		write(1, str, ft_strlen(str));
	exit(code);
	if (game->config.rows)
		free_machine(game);
	return (0);
}

int		exit_error_line(char *line, int code, char const *str)
{
	write(1, "Error\n", 6);
	if (str)
		write(1, str, ft_strlen(str));
	free(line);
	exit(code);
	return (0);
}

int		exit_game(t_game *game)
{
	free_machine(game);
	exit(0);
	return (0);
}
