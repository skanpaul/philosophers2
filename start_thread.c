
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int start_thread(t_data *d)
{
	int i;
	t_timeval tv_start_game;
	t_philo *p_list;
	t_philo *p;

	gettimeofday(&tv_start_game, NULL);
	p_list = d->philo_list;

	i = 0;
	while (i < d->max_philo)
	{
		p = &p_list[i];
		p->tv_start = tv_start_game;
		// ------------------------------------------------------------------
		if (pthread_create(&p->th_id, NULL, &philo_activity, (void *)p) != 0)
			return (print_error(TYPE_ERR_THD_CREATE));
		// ------------------------------------------------------------------
		usleep(2000);
		// ------------------------------------------------------------------
		// DETACH THREAD IF NECESSARY
		// ------------------------------------------------------------------
		i++;
	}

	if (pthread_create(&d->thd_check_life, NULL, &check_life, (void *)d) != 0)
		return (print_error(TYPE_ERR_THD_CREATE));

	return (NO_ERROR);
}

/* ************************************************************************** */