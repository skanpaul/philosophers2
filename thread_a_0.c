
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