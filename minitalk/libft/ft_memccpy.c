/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohee <sohee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:41:48 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/22 17:38:59 by sohee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	unsigned char	find;
	size_t			i;

	n_dest = dest;
	n_src = (unsigned char *)src;
	find = c;
	i = 0;
	while (i < n)
	{
		n_dest[i] = n_src[i];
		if (n_src[i] == find)
			return (dest + (i + 1));
		i++;
	}
	return (NULL);
}
