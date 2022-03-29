
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void *philo_activity(void *arg)
{
	t_philo *p;

	p = (t_philo *)arg;


	// START-LOOP --------------------------------------------------------

		take_forks(p);
		// is he dead while taking the forks ???

		// EAT & WAIT: finis to eat

		// GIVE FORKS BACK

		// SLEEP & WAIT: finis to sleep

		// THINK: when necessary TAKE FORK AND EAT

	// END-LOOP ---------------------------------------------------------


	// struct philo
	// id_philo
	// id_thread
	// mutex mtx_time_stamp

	return (arg);
}

/* ************************************************************************** */
void *check_life(void *arg)
{

	return (arg);
}
/* ************************************************************************** */