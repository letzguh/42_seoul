/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:09:49 by sohee             #+#    #+#             */
/*   Updated: 2021/03/16 18:01:14 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_rgb_range(char **rgb)
{
	int i;
	int tmp;

	i = 0;
	while (i < 3)
	{
		if (ft_strlen(rgb[i]) > 0 && ft_strlen(rgb[i]) < 4)
		{
			tmp = ft_atoi(rgb[i]);
			if (tmp < 0 || tmp > 255)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*add_str(char *tmp, char *line)
{
	char *tmp2;
	char *tmp3;

	tmp2 = ft_strjoin(line, "\n");
	tmp3 = ft_strjoin(tmp, tmp2);
	if (*tmp && tmp)
	{
		free(tmp);
		tmp = 0;
	}
	free(tmp2);
	return (tmp3);
}
