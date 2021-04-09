/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohee <sohee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:44:40 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/22 17:39:41 by sohee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;
	unsigned char	src;
	size_t			i;

	ret = b;
	src = c;
	i = 0;
	while (i++ < len)
		*ret++ = src;
	return (b);
}
