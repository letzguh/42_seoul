#include "minitalk.h"

int     print_pid(void)
{
    int     server_pid;
    char    *pid_str;

    server_pid = getpid();
    pid_str = ft_itoa(server_pid);
    write(1, "PID : ", 6);
    write(1, pid_str, ft_strlen(pid_str));
    write(1, "\n", 1);
    free(pid_str);
    pid_str = 0;
    return (1);
}

void    get_client_pid(int *step, int *client_pid, int signal, int *index)
{
    if (*index <32)
    {
        *client_pid <<=1;
        *client_pid |= signal;
        (*index)++;
    }
    if (*index == 32)
    {
        *index = 0;
        (*step)++;
    }
}