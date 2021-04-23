/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:10:47 by sohelee           #+#    #+#             */
/*   Updated: 2020/10/09 14:41:01 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	while (!src && !dst)
		return (NULL);
	ret = dst;
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (ret);
}
