/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:44:43 by sohelee           #+#    #+#             */
/*   Updated: 2021/05/29 18:47:28 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int ac, char *av[])
{
	check_argument(ac, &av);
}

int	check_argument(int ac, char *av[])
{
	if (ac <= 1)
		return (error("Error\n"));
}
