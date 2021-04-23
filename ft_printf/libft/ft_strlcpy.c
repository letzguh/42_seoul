/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:43:38 by sohelee           #+#    #+#             */
/*   Updated: 2020/10/23 16:45:53 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t idx;
	size_t s_idx;

	if (!src && !dst)
		return (0);
	s_idx = 0;
	while (src[s_idx])
		s_idx++;
	if (dstsize == 0)
		return (s_idx);
	idx = 0;
	while (src[idx] && (idx + 1 < dstsize))
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (s_idx);
}
