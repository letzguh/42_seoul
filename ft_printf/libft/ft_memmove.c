/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:02:17 by sohelee           #+#    #+#             */
/*   Updated: 2020/10/19 18:20:56 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*new_dst;
	char		*new_src;

	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		new_dst = (char *)dst + (len - 1);
		new_src = (char *)src + (len - 1);
		while (len--)
			*new_dst-- = *new_src--;
	}
	else
	{
		new_dst = (char *)dst;
		new_src = (char *)src;
		while (len--)
			*new_dst++ = *new_src++;
	}
	return (dst);
}
