/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:57:55 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 22:05:42 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_p(t_options options, va_list ap)
{
	char	*pointer;
	int		ret;
	int		len;

	pointer = ft_itoa_base(va_arg(ap, size_t), 'p', 16);
	ret = 0;
	if (options.precision == 0 && *pointer == '0')
		*pointer = '\0';
	len = ft_strlen(pointer);
	if (options.minus)
	{
		ret += write(1, "0x", 2);
		ret += write(1, pointer, len);
	}
	while ((options.width-- - len - 2) > 0)
		ret += write(1, " ", 1);
	if (!options.minus)
	{
		ret += write(1, "0x", 2);
		ret += write(1, pointer, len);
	}
	free(pointer);
	return (ret);
}
