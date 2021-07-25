#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include "libft.h"

# define GET_STRLEN 0
# define MALLOC 1
# define GET_PID 0
# define GET_LEN 1
# define GET_STR 2
# define GET_PID_LAST 3
# define PRINT_FREE 4

typedef struct s_static
{
    char    *str;
    size_t  strlen;
    size_t  saved;
    int		client_pid;
	int		client_pid_last;
	int		step;
	int		index;
}               t_static;

int				print_pid(void);

#endif