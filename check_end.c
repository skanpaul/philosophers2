
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void *check_end(void *arg)
{
	t_data *d;
	t_philo *p;
	bool all_finish_to_eat;
	bool eat_enough;

	int i;

	d = (t_data *)arg;
	
	while (1)
	{
	// --------------------------------------------------	
		i = 0;
		all_finish_to_eat = true;
		while (i < d->max_philo)
		{
			p = &d->philo_list[i];			
			if(is_this_philo_dead(p))
			{
				pthread_mutex_unlock(&d->mtx_finish_main);
				return (arg);
			}
			pthread_mutex_lock(&p->mtx_eat_enough);
			eat_enough = p->eat_enough;
			pthread_mutex_unlock(&p->mtx_eat_enough);
			if (eat_enough == false)
				all_finish_to_eat = false;
			i++;
		}
		if (all_finish_to_eat == true)
		{
			print_max_meal(p);
			pthread_mutex_unlock(&d->mtx_finish_main);
			return (arg);
		}
	// --------------------------------------------------
		usleep(50);
	// --------------------------------------------------
	}
	return (arg);
}

/* ************************************************************************** */