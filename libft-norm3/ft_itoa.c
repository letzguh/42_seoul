/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohee <sohee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:23:24 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/22 18:10:22 by sohee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_len;
	size_t	i;

	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	n_len = get_len(n);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!(str))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i = 1;
	}
	str[n_len] = '\0';
	while (i < n_len)
	{
		str[n_len - 1] = (n % 10) + '0';
		n = n / 10;
		n_len--;
	}
	return (str);
}
