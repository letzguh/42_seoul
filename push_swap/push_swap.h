/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:45:13 by sohelee           #+#    #+#             */
/*   Updated: 2021/05/29 18:47:42 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct		s_node
{
	int				num;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*head;				
	t_node			*tail;
}					t_stack;

# include <unistd.h> //read, write
# include <stdlib.h> //malloc, free, exit
# include "libft.h"

#endif
