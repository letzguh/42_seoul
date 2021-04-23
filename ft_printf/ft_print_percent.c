/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:38:09 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 20:53:15 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_percent(t_options options)
{
	int		ret;

	ret = 0;
	if (options.minus)
		ret += write(1, "%", 1);
	while ((options.width-- - 1) > 0)
	{
		if (options.zero)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	if (!options.minus)
		ret += write(1, "%", 1);
	return (ret);
}
