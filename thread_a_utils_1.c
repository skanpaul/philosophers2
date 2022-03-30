
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int philo_take_forks_left(t_philo *p)
{	
	pthread_mutex_lock(p->mtx_fork_l);	

	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	else
	{
		set_1_timeval_mutex(&p->tv_fork, p);
		print_fork(p);
	}

	return (ALIVE);
}

/* ************************************************************************** */
int philo_take_forks_right(t_philo *p)
{
	pthread_mutex_lock(p->mtx_fork_r);	

	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	else
	{
		set_1_timeval_mutex(&p->tv_fork, p);
		print_fork(p);
	}

	return (ALIVE);
}

/* ************************************************************************** */
void philo_eat(t_philo *p)
{
	// start to eat
	set_all_timeval_mutex(p);	




	print_eat(p);

	// wait until finis to eat


}

/* ************************************************************************** */
void philo_give_forks_back(t_philo *p)
{
	// ATTENTION: PEUT-ETRE INVERSER FOURCHETTE
	
	pthread_mutex_unlock(p->mtx_fork_r);
	pthread_mutex_unlock(p->mtx_fork_l);
}

/* ************************************************************************** */