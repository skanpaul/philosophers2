
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void *philo_activity(void *arg)
{
	t_philo *p;

	p = (t_philo *)arg;	
	set_all_stamp_us_mutex(p);
	// print_born(p);

	// START-LOOP --------------------------------------------------------
	while (1)
	{
		// TAKE FORKS LEFT
		if (philo_take_forks_left(p) == DEAD)
			break;
		// TAKE FORKS RIGHT
		if (philo_take_forks_right(p) == DEAD)
			break;

		// EAT & WAIT: finis to eat
		if (philo_start_to_eat(p) == DEAD)
			break;

		// GIVE FORKS BACK
		philo_give_forks_back(p);

		// SLEEP & WAIT: finis to sleep
		if (philo_start_to_sleep(p) == DEAD)
			break;

		// THINK: when necessary TAKE FORK AND EAT
		if (philo_start_to_think(p) == DEAD)
			break;

	}
	// END-LOOP ---------------------------------------------------------


	return (arg);
}
/* ************************************************************************** */