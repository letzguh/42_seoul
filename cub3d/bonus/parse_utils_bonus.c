/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:41:36 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/18 15:06:57 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		is_endwith(char const *path, char const *str)
{
	int	ret;
	int	len;

	ret = 1;
	len = ft_strlen(path);
	if (len >= 4)
		ft_strncmp(path + len - 4, str, 4);
	return (ret == 1 ? 1 : 0);
}

int		is_space(int x)
{
	if (((x >= 9) && (x <= 13)) || x == 32)
		return (1);
	return (0);
}

int		count_element(char **str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		count++;
	return (count);
}

int		check_digit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		is_upper(int x)
{
	if (x >= 65 && x <= 90)
		return (1);
	return (0);
}
