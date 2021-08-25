/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:08:19 by sohelee           #+#    #+#             */
/*   Updated: 2021/08/24 17:08:51 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft.h"

# define GET_STRLEN 0
# define MALLOC 1
# define GET_PID 0
# define GET_LEN 1
# define GET_STR 2
# define GET_PID_LAST 3
# define PRINT_FREE 4

typedef struct s_static
{
	char	*str;
	size_t	strlen;
	size_t	saved;
	int		client_pid;
	int		client_pid_last;
	int		step;
	int		index;
}				t_static;

void				*ft_malloc(size_t size);
void				get_strlen(int signal, t_static *static_var);
void				save_str(int signal, t_static *static_var);
void				print_and_free(t_static *static_var);
void				get_client_pid(int *step, \
					int *client_pid, int signal, int *index);

#endif