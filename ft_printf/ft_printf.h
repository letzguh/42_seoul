/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:28:31 by sohelee           #+#    #+#             */
/*   Updated: 2020/11/29 21:03:11 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_options
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			type;
}					t_options;

int					ft_printf(const char *format, ...);
int					ft_treat_type(t_options options, va_list ap);
int					ft_print_di(t_options options, va_list ap);
int					ft_print_c(t_options options, va_list ap);
int					ft_print_s(t_options options, va_list ap);
int					ft_print_xx(t_options options, va_list ap);
int					ft_print_p(t_options options, va_list ap);
int					ft_print_u(t_options options, va_list ap);
int					ft_print_percent(t_options options);
char				*ft_itoa_base(size_t n, char c, int base);
const char			*ft_parse_options(const char *format,
								t_options *options, va_list ap);

#endif
