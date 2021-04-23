/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:50:47 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 21:17:47 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_option(t_options *options)
{
	options->minus = 0;
	options->zero = 0;
	options->precision = -1;
	options->width = 0;
	options->type = 0;
}

int				ft_treat_format(const char *format, va_list ap)
{
	int				i;
	t_options		options;

	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_init_option(&options);
			format++;
			format = ft_parse_options(format, &options, ap);
			i += ft_treat_type(options, ap);
		}
		else
			i += write(1, format++, 1);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				char_count;

	va_start(ap, format);
	char_count = 0;
	char_count += ft_treat_format(format, ap);
	va_end(ap);
	return (char_count);
}
