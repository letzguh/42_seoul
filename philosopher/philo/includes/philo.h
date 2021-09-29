#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

# define RET_ERROR -1
# define RET_OK 0
# define RET_DEAD 3
# define FINISHED_MEAL 2
# define TRUE 1
# define FALSE 0
# define LEFT 1
# define RIGHT 0
# define ODD 1
# define EVEN 0
# define STATUS_EAT 0
# define STATUS_THINK 1
# define STATUS_SLEEP 2
# define STATUS_FORK 3
# define STATUS_END 4

typedef struct s_mutex
{
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
}	t_mutex;

typedef struct s_variable
{
	struct timeval	first_meal_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				num_of_philos;
	int				finished_meal;
	int				philo_alive;
}	t_variable;

typedef struct s_philo
{
	int			fork_num[2];
	int			last_meal_time;
	int			philo_num;
	int			have_meal;
	pthread_t	philo_tid;
	t_mutex		*mutex;
	t_variable	*variable;
}	t_philo;

/*
** check_error.c
*/
int		check_error(int ac, char **av);

/*
** free_all.c
*/
void	free_all(t_philo *philo, t_mutex *mutex, t_variable *variable);

/*
** init.c
*/
int		init_variable(int ac, char **av, t_variable *variable);
int		init_mutex(t_mutex *mutex, t_variable *variable);
t_philo	*init_philos(t_variable *variable, t_mutex *mutex);

/*
** thread_philo.c
*/
void	*thread_philo(void *start_routine);

/*
** utils.c
*/
int		ret_timestamp(t_philo *philo);
int		print_status(t_philo *philo, char *str, int status, int philo_num);
int		ft_usleep(t_philo *philo, int time, int timestamp);
int		ft_isdigit(int num);
int		ft_atoi(const char *str);

#endif
