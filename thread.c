
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void *philo_activity(void *arg)
{
	t_philo *p;

	p = (t_philo *)arg;	
	gettimeofday_mutex(&p->ts_eat, p);
	print_life(p);

	// START-LOOP --------------------------------------------------------
	while (1)
	{
		// TAKE FORKS LEFT
		if (take_forks_left(p) == DEAD)
			break;
		// TAKE FORKS RIGHT
		if (take_forks_right(p) == DEAD)
			break;

		// EAT & WAIT: finis to eat

		// GIVE FORKS BACK

		// SLEEP & WAIT: finis to sleep

		// THINK: when necessary TAKE FORK AND EAT
	}
	// END-LOOP ---------------------------------------------------------


	return (arg);
}

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
				// pthread_mutex_lock(d.mt)
				
				
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