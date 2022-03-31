
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int start_thread(t_data *d)
{
	int			i;
	t_timeval 	tv_start_game;
	int64_t		stamp_us_start_game;
	t_philo		*p;

	gettimeofday(&tv_start_game, NULL);
	stamp_us_start_game = conv_stamp_us_from_tv(&tv_start_game);

	i = 0;
	while (i < d->max_philo)
	{
		p = &d->philo_list[i];
		p->tv_start = tv_start_game;
		p->stamp_us_start = stamp_us_start_game;
		// ------------------------------------------------------------------
		if (pthread_create(&p->th_id, NULL, &philo_activity, (void *)p) != 0)
			return (print_error(TYPE_ERR_THD_CREATE));
		// ------------------------------------------------------------------
		usleep(100);
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