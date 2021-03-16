/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:43:23 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 21:47:46 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*parsing_flag(const char *format, t_options *options)
{
	while (*format != '\0')
	{
		if (*format == '0')
			options->zero++;
		else if (*format == '-')
			options->minus++;
		else
			return (format);
		format++;
	}
	return (format);
}

const char	*parsing_width(const char *format, t_options *options, va_list ap)
{
	if (ft_isdigit(*format))
	{
		options->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else if (*format == '*')
	{
		if ((options->width = va_arg(ap, int)) < 0)
		{
			options->minus++;
			options->width *= -1;
		}
		format++;
	}
	return (format);
}

const char	*parsing_precision(const char *format,
			t_options *options, va_list ap)
{
	if (*format == '.')
	{
		format++;
		options->precision = 0;
		if (ft_isdigit(*format))
		{
			options->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if (*format == '*')
		{
			options->precision = va_arg(ap, int);
			format++;
		}
	}
	return (format);
}

const char	*ft_parse_options(const char *format,
						t_options *options, va_list ap)
{
	format = parsing_flag(format, options);
	format = parsing_width(format, options, ap);
	format = parsing_precision(format, options, ap);
	if (*format != '\0')
		options->type = *format++;
	if (options->type == '%')
		options->precision = -1;
	if (options->minus)
		options->zero = 0;
	if (options->precision >= 0)
		options->zero = 0;
	return (format);
}
