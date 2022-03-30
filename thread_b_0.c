
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void *check_life(void *arg)
{
	t_data *d;
	int i;

	d = (t_data *)arg;
	
	while (1)
	{
	// --------------------------------------------------	
		i = 0;
		while (i < d->max_philo)
		{
			if(is_this_philo_dead(&d->philo_list[i]))
			{
				pthread_mutex_unlock(&d->mtx_finish_main);
				return (arg);
			}
			i++;
		}
	// --------------------------------------------------
	}
	return (arg);
}

/* ************************************************************************** */
bool is_this_philo_dead(t_philo *p)
{
	t_timeval now;
	int diff_ms;
	bool	answer;

	answer = false;
	gettimeofday(&now, NULL);

	// ------------------------------
	pthread_mutex_lock(&p->mtx_timestamp);
	// ------------------------------
	diff_ms = get_ms_diff(&now, &p->ts_eat);

	if (diff_ms >= p->d->time_die)
	{
		p->ts_died = p->ts_eat;
		add_ms_to_timeval(p->d->time_die, &p->ts_died);
		
		pthread_mutex_lock(&p->d->mtx_someone_dead);
		p->philo_dead = true;
		p->d->someone_dead = true;
		answer = true;
		print_died(p);
		pthread_mutex_unlock(&p->d->mtx_someone_dead);
	}
	// --------------------------------
	pthread_mutex_unlock(&p->mtx_timestamp);
	// --------------------------------

	return (answer);
}

/* ************************************************************************** */


	// if (now.tv_sec == p->ts_eat.tv_sec)
	// 	diff.tv_usec = now.tv_usec - p->ts_eat.tv_usec;
	// else // if (now.tv_sec > p->ts_eat.tv_sec)
	// 	diff.tv_usec = (1000000 - p->ts_eat.tv_usec) + now.tv_usec;

	// if (diff.tv_usec / 1000 >= p->d->time_die)




	// if (

	// 	(
	// 		(now.tv_sec == p->ts_eat.tv_sec)
	// 		&&
	// 		((now.tv_usec - p->ts_eat.tv_usec) / 1000 >= p->d->time_die)
	// 	)

	// 	||

	// 	(
	// 		(now.tv_sec > p->ts_eat.tv_sec)
	// 		&&
	// 		(((1000000 - p->ts_eat.tv_usec) + now.tv_usec) / 1000 >= p->d->time_die)
	// 	)
		
	// 	)