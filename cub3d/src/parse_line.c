/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:02:11 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 18:55:09 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_screensize(t_config *c, char *line)
{
	int		i;
	char	**screen;

	i = 0;
	if (c->screenheight || c->screenwidth)
		return (0);
	if (!(screen = ft_split(line, ' ')))
		return (0);
	if (!(count_element(screen) == 3))
		return (0);
	if (!check_digit(screen[1]) || !check_digit(screen[2]))
		return (0);
	c->screenwidth = ft_atoi(screen[1]);
	c->screenheight = ft_atoi(screen[2]);
	free_double(screen);
	screen = 0;
	if (c->screenwidth > 2560)
		c->screenwidth = 2560;
	if (c->screenheight > 1440)
		c->screenheight = 1440;
	if (!c->screenheight || !c->screenwidth)
		return (0);
	return (1);
}

static int	get_path(t_config *c, char *line, int type)
{
	int		i;
	char	*tmp;

	if (c->tex[type].tex_path)
		return (exit_error_line(line, EXIT_FAILURE, "Path Error"));
	i = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	tmp = ft_strdup(line + i);
	c->tex[type].tex_path = tmp;
	return (1);
}

static int	get_color(t_config *c, char *line, int type)
{
	char	**rgb;
	int		color;

	if (!(rgb = ft_split(line + 2, ',')))
		return (0);
	if (!(count_element(rgb) == 3))
		return (0);
	if (!check_rgb_range(rgb))
		return (0);
	color = ((ft_atoi(rgb[0]) * 256) + ft_atoi(rgb[1])) * 256 + ft_atoi(rgb[2]);
	free_double(rgb);
	rgb = 0;
	if (type == C_F)
		c->floor_color = color;
	else if (type == C_C)
		c->ceiling_color = color;
	c->istype[type]++;
	return (1);
}

static int	get_map(t_config *c, char *tmp)
{
	int		i;
	int		j;

	if (!(c->map = ft_split(tmp, '\n')))
		return (0);
	c->istype[C_MAP] = 1;
	free(tmp);
	i = -1;
	j = 0;
	while (c->map[++i])
		j = j < (int)ft_strlen(c->map[i]) ? (int)ft_strlen(c->map[i]) : j;
	c->rows = i;
	c->colums = j;
	c->tile = c->screenwidth / c->colums;
	return (1);
}

int			parse_line(int ret, t_config *c, int type, char *line)
{
	static char *tmp = "";

	if (type == C_R)
	{
		if (!get_screensize(c, line))
			return (exit_error_line(line, EXIT_FAILURE, "Screensize Error"));
	}
	else if (type >= C_NO && type <= C_S)
		get_path(c, line, type);
	else if (type == C_F || type == C_C)
	{
		if (!get_color(c, line, type))
			return (exit_error_line(line, EXIT_FAILURE, "Color Error"));
	}
	else
	{
		tmp = add_str(tmp, line);
		c->istype[C_MAP] = 1;
	}
	if (ret == 0 && !get_map(c, tmp))
		return (exit_error_line(line, EXIT_FAILURE, "Wrong Map Parsing"));
	free(line);
	return (1);
}
