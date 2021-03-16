/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:25:54 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 20:06:33 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_total_width_u(t_options options, int integer, char **str)
{
	int		total_width;
	int		len;

	total_width = options.width;
	*str = ft_itoa_base((size_t)(unsigned int)integer, options.type, 10);
	if (options.precision == 0 && integer == 0)
		**str = '\0';
	len = ft_strlen(*str);
	if (options.precision > len)
		total_width -= options.precision;
	else
		total_width -= len;
	return (total_width);
}

int			print_left_u(t_options options, int integer)
{
	int		ret;
	char	*str;
	int		len;

	ret = 0;
	str = ft_itoa_base((size_t)(unsigned int)integer, options.type, 10);
	if (options.precision == 0 && integer == 0)
		*str = '\0';
	len = ft_strlen(str);
	while ((options.precision-- - len) > 0)
		ret += write(1, "0", 1);
	ret += write(1, str, len);
	options.width -= ret;
	while ((options.width--) > 0)
		ret += write(1, " ", 1);
	free(str);
	return (ret);
}

int			print_right_u(t_options options, int integer)
{
	int		ret;
	char	*str;
	int		len;

	options.width = get_total_width_u(options, integer, &str);
	len = ft_strlen(str);
	ret = 0;
	while (options.width-- > 0)
	{
		if (options.zero)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	while ((options.precision-- - len) > 0)
		ret += write(1, "0", 1);
	ret += write(1, str, len);
	free(str);
	return (ret);
}

int			ft_print_u(t_options options, va_list ap)
{
	if (options.minus)
		return (print_left_u(options, va_arg(ap, int)));
	else
		return (print_right_u(options, va_arg(ap, int)));
}
