/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:05:57 by sohelee           #+#    #+#             */
/*   Updated: 2021/05/29 17:52:38 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
	return (-1);
}
