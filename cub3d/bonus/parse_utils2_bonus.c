/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:09:49 by sohee             #+#    #+#             */
/*   Updated: 2021/03/18 16:08:45 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_rgb_range(char **rgb)
{
	int		i;
	int		tmp;
	char	*ctmp;

	i = 0;
	while (i < 3)
	{
		ctmp = ft_strtrim(rgb[i], " ");
		if (ft_strlen(ctmp) > 0 && ft_strlen(ctmp) < 4)
		{
			tmp = ft_atoi(ctmp);
			if (tmp < 0 || tmp > 255)
				return (0);
			i++;
		}
		else
			return (0);
		free(ctmp);
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
