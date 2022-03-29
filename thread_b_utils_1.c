
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
bool is_this_philo_dead(t_philo *p)
{
	t_timeval actual;
	bool	answer;

	answer = false;
	gettimeofday(&actual, NULL);

	// ------------------------------
	pthread_mutex_lock(&p->mtx_timestamp);
	// ------------------------------
	if (

		(
			(actual.tv_sec == p->ts_eat.tv_sec)
			&&
			((actual.tv_usec - p->ts_eat.tv_usec) / 1000 >= p->d->time_die)
		)

		||

		(
			(actual.tv_sec > p->ts_eat.tv_sec)
			&&
			(((1000000 - p->ts_eat.tv_usec) + actual.tv_usec) / 1000 >= p->d->time_die)
		)
		
		)
	{
		p->ts_died = actual;
		
		pthread_mutex_lock(&p->mtx_philo_dead);
		p->philo_dead = true;
		pthread_mutex_unlock(&p->mtx_philo_dead);
		answer = true;
		print_died(p);
	}
	// --------------------------------
	pthread_mutex_unlock(&p->mtx_timestamp);
	// --------------------------------

	return (answer);
}

/* ************************************************************************** */
	// if (actual.tv_sec == p->ts_eat.tv_sec)
	// {
	// 	if (actual.tv_usec - p->ts_eat.tv_usec >= p->d->time_die)
	// 	{
	// 		p->ts_died = actual;
	// 		return (true);
	// 	}
	// }
	// else // if (actual.tv_sec != p->ts_eat.tv_sec)
	// {
	// 	if ((1000000 - p->ts_eat.tv_usec) + actual.tv_usec >= p->d->time_die)
	// 	{
	// 		p->ts_died = actual;
	// 		return (true);
	// 	}
	// }
	// return (false);