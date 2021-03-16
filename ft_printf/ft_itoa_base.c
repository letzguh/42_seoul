/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:47:04 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/23 23:34:20 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *g_hexa = "0123456789abcdef";
char *g_bighexa = "0123456789ABCDEF";

static size_t		get_len(size_t n, int base)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(size_t n, char c, int base)
{
	char	*str;
	size_t	n_len;
	size_t	i;

	n_len = get_len(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (n_len + 1))))
		return (NULL);
	i = 0;
	str[n_len] = '\0';
	while (i < n_len)
	{
		if (c == 'X')
			str[n_len - 1] = g_bighexa[n % base];
		else
			str[n_len - 1] = g_hexa[n % base];
		n = n / base;
		n_len--;
	}
	return (str);
}
