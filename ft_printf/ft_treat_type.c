/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:04:57 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 18:35:43 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_treat_type(t_options options, va_list ap)
{
	if (options.type == 'd' || options.type == 'i')
		return (ft_print_di(options, ap));
	else if (options.type == 'c')
		return (ft_print_c(options, ap));
	else if (options.type == 's')
		return (ft_print_s(options, ap));
	else if (options.type == 'u')
		return (ft_print_u(options, ap));
	else if (options.type == 'p')
		return (ft_print_p(options, ap));
	else if (options.type == 'x' || options.type == 'X')
		return (ft_print_xx(options, ap));
	else if (options.type == '%')
		return (ft_print_percent(options));
	else
		return (-1);
}
