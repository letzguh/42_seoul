/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:38:34 by sohelee           #+#    #+#             */
/*   Updated: 2021/01/20 17:26:30 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_total_width(t_options options, int integer, char **str)
{
	int		total_width;
	int		len;

	total_width = options.width;
	if (integer < 0)
		total_width--;
	if (integer < 0)
		integer *= -1;
	if (options.precision == 0 && integer == 0)
		*str = ft_strdup("");
	else
		*str = ft_itoa_base((size_t)(unsigned int)integer, 'd', 10);
	len = ft_strlen(*str);
	if (options.precision > len)
		total_width -= options.precision;
	else
		total_width -= len;
	return (total_width);
}

int			print_left(t_options options, int integer)
{
	int		ret;
	char	*str;
	int		len;

	ret = 0;
	if (integer < 0)
	{
		integer *= -1;
		ret += write(1, "-", 1);
	}
	if (options.precision == 0 && integer == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base((size_t)(unsigned int)integer, 'd', 10);
	len = ft_strlen(str);
	while ((options.precision-- - len) > 0)
		ret += write(1, "0", 1);
	ret += write(1, str, len);
	while ((options.width - ret) > 0)
		ret += write(1, " ", 1);
	free(str);
	return (ret);
}

int			print_right(t_options options, int integer)
{
	int		ret;
	char	*str;
	int		len;

	options.width = get_total_width(options, integer, &str);
	len = ft_strlen(str);
	ret = 0;
	if ((options.zero) && (integer < 0))
		ret += write(1, "-", 1);
	while (options.width-- > 0)
	{
		if (options.zero)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	if ((!options.zero) && (integer < 0))
		ret += write(1, "-", 1);
	while ((options.precision-- - len) > 0)
		ret += write(1, "0", 1);
	ret += write(1, str, len);
	free(str);
	return (ret);
}

int			ft_print_di(t_options options, va_list ap)
{
	int	integer;

	integer = va_arg(ap, int);
	if (options.minus)
		return (print_left(options, integer));
	else
		return (print_right(options, integer));
}
