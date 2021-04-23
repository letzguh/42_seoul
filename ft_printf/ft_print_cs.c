/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:38:33 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 18:59:36 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_c(t_options options, va_list ap)
{
	int		ret;
	char	c;

	ret = 0;
	c = va_arg(ap, int);
	if (options.minus)
		ret += write(1, &c, 1);
	while ((options.width-- - 1) > 0)
		ret += write(1, " ", 1);
	if (!options.minus)
		ret += write(1, &c, 1);
	return (ret);
}

int					ft_print_s(t_options options, va_list ap)
{
	char	*va_str;
	char	*str;
	int		ret;
	int		len;

	ret = 0;
	if (!(va_str = va_arg(ap, char *)))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(va_str);
	len = ft_strlen(str);
	if ((options.precision >= 0) && options.precision < len)
	{
		str[options.precision] = '\0';
		len = options.precision;
	}
	if (options.minus)
		ret += write(1, str, len);
	while ((options.width-- - len) > 0)
		ret += write(1, " ", 1);
	if (!options.minus)
		ret += write(1, str, len);
	free(str);
	return (ret);
}
