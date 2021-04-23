/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:01:29 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 15:07:50 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)n;
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static int	write_bmp_header(int fd, int file_size, t_game *g)
{
	int				i;
	int				ret;
	unsigned char	bmp_header[54];

	i = 0;
	while (i < 54)
		bmp_header[i++] = (unsigned char)(0);
	bmp_header[0] = (unsigned char)('B');
	bmp_header[1] = (unsigned char)('M');
	int_to_char(file_size, bmp_header + 2);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	int_to_char(g->config.screenwidth, bmp_header + 18);
	int_to_char(g->config.screenheight, bmp_header + 22);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	ret = write(fd, bmp_header, 54);
	return (ret);
}

static int	get_color(t_game *g, int x, int y)
{
	int		color;
	int		rgb;

	color = *(int*)(g->img.data + ((int)g->config.screenwidth *\
		((int)g->config.screenheight - 1 - y)) + x);
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int	write_bmp_data_pixel(int fd, int pad, t_game *g)
{
	int				i;
	int				j;
	int				color;
	unsigned char	zero[3];

	i = -1;
	while (++i < 3)
		zero[i] = (unsigned char)0;
	i = 0;
	while (i < (int)g->config.screenheight)
	{
		j = 0;
		while (j < (int)g->config.screenwidth)
		{
			color = get_color(g, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(fd, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			screenshot(t_game *g)
{
	int		pixel_bytes_per_row;
	int		fd;
	int		file_size;
	int		pad;

	draw_ceil_floor(g);
	calc_raycasting(g);
	calc_sprite(g);
	draw(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	pixel_bytes_per_row = g->config.screenwidth * 4;
	pad = (4 - (pixel_bytes_per_row % 4)) % 4;
	file_size = 54 + 3 * (g->config.screenwidth + pad)\
				* g->config.screenheight;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |\
									O_TRUNC | O_APPEND)) < 0)
		return (exit_error(g, EXIT_FAILURE, "bmp open Failure"));
	if (!(write_bmp_header(fd, file_size, g)) ||\
			!(write_bmp_data_pixel(fd, pad, g)))
		return (exit_error(g, EXIT_FAILURE, "bmp file write Error"));
	close(fd);
	return (1);
}
