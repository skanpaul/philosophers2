
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int start_thread(t_data *d)
{
	int i;
	t_timeval start;
	t_philo *p_list;
	t_philo *p;

	gettimeofday(&start, NULL);
	p_list = d->philo_list;

	i = 0;
	while (i < d->max_philo)
	{
		p = &p_list[i];
		p[i].tv_start = start;
		// ------------------------------------------------------------------
		if (pthread_create(&p->th_id, NULL, &philo_activity, (void *)p) != 0)
			return (print_error(TYPE_ERR_THD_CREATE));
		// ------------------------------------------------------------------
		ft_msleep(1);	
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