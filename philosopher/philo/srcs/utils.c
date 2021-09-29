#include "philo.h"

int	ret_timestamp(t_philo *philo)
{
	struct timeval	get_time;
	int				timestamp;

	gettimeofday(&get_time, NULL);
	if (philo->variable->first_meal_time.tv_sec == 0)
		return (0);
	timestamp = get_time.tv_usec - philo->variable->first_meal_time.tv_usec + \
		(get_time.tv_sec - philo->variable->first_meal_time.tv_sec) * 1000000;
	return (timestamp);
}

int	print_status(t_philo *philo, char *str, int status, int philo_num)
{
	int	timestamp;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	if (status != STATUS_END && philo->variable->philo_alive == FALSE)
		return (RET_DEAD);
	timestamp = ret_timestamp(philo);
	printf("%d philo_%d %s\n", timestamp / 1000, philo_num, str);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	if (status == STATUS_EAT)
	{
		philo->last_meal_time = timestamp;
		ft_usleep(philo, philo->variable->time_to_eat, timestamp);
	}
	if (status == STATUS_SLEEP)
		ft_usleep(philo, philo->variable->time_to_sleep, timestamp);
	return (RET_OK);
}

int	ft_usleep(t_philo *philo, int time, int timestamp)
{
	int	time_taken;

	time_taken = 0;
	while (time_taken <= timestamp + time * 1000)
	{
		time_taken = ret_timestamp(philo);
		usleep(time);
	}
	return (RET_OK);
}

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	neg;
	long	num;
	int		idx;

	idx = 0;
	neg = 1;
	num = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg *= -1;
		idx++;
	}
	while (str[idx] && (str[idx] >= 48 && str[idx] <= 57))
	{
		num = num * 10 + (str[idx] - 48) * neg;
		if (num > 2147483647 && neg == 1)
			return (-1);
		if (num > 2147483648 && neg == -1)
			return (0);
		idx++;
	}
	return (num);
}
