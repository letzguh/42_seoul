#include "minitalk.h"

void	arrange_bit(t_static *static_var, int signal)
{
	if (static_var->step == GET_PID)
		get_client_pid(&static_var->step,\
		&static_var->client_pid, signal, &static_var->index);
	


	
}

void	use_bit(int sigusr)
{
	static t_static static_var;
	int				signal;

	if (sigusr == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	arrange_bit(&static_var, signal);
}

int main(void)
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