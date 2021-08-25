/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:08:42 by sohelee           #+#    #+#             */
/*   Updated: 2021/08/24 17:08:44 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_pid(void)
{
	int		server_pid;
	char	*pid_str;
	int		strlen;

	server_pid = getpid();
	pid_str = ft_itoa(server_pid);
	strlen = ft_strlen(pid_str);
	write(1, "PID : ", 6);
	write(1, pid_str, strlen);
	write(1, "\n", 1);
	free(pid_str);
	pid_str = 0;
	return (1);
}

void	arrange_bit(t_static *static_var, int signal)
{
	if (static_var->step == GET_PID)
		get_client_pid(&static_var->step, \
		&static_var->client_pid, signal, &static_var->index);
	else if (static_var->step == GET_LEN)
		get_strlen(signal, static_var);
	else if (static_var->step == GET_STR)
		save_str(signal, static_var);
	else if (static_var->step == GET_PID_LAST)
		get_client_pid(&static_var->step, \
		&static_var->client_pid_last, signal, &static_var->index);
	if (static_var->step == PRINT_FREE)
		print_and_free(static_var);
}

void	use_bit(int sigusr)
{
	static t_static	static_var;
	int				signal;

	if (sigusr == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	arrange_bit(&static_var, signal);
}

int	main(void)
{
	print_pid();
	while (1)
	{
		signal(SIGUSR1, use_bit);
		signal(SIGUSR2, use_bit);
		pause();
	}
	return (0);
}
