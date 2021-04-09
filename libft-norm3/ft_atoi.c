/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohee <sohee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:21:55 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/22 17:16:45 by sohee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	neg;
	long	num;
	int		idx;

	idx = 0;
	neg = 1;
	num = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg *= -1;
		idx++;
	}
	while (str[idx] && (str[idx] >= 48 && str[idx] <= 57))
	{
		num = num * 10 + (str[idx] - 48) * neg;
		if (num > 2147483647 && neg == 1)
			return (-1);
		if (num > 2147483648 && neg == -1)
			return (0);
		idx++;
	}
	return (num);
}
