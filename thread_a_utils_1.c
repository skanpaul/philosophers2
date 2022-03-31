
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
		// set_1_timeval_mutex(&p->tv_fork, p);
		gettimeofday(&p->tv_fork, NULL);
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
		// set_1_timeval_mutex(&p->tv_fork, p);
		gettimeofday(&p->tv_fork, NULL);
		print_fork(p);
	}

	return (ALIVE);
}

/* ************************************************************************** */
int philo_start_to_eat(t_philo *p)
{
	int time_to_eat;

	set_all_timeval_mutex(p);	

	pthread_mutex_lock(&p->mtx_timeval);
	time_to_eat = p->d->time_eat;
	pthread_mutex_unlock(&p->mtx_timeval);	


	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_eat(p);
	
	ft_msleep(time_to_eat, 80);

	while(!is_activity_finished(&p->tv_sleep, p))
	{
		if (is_someone_dead_mutex(p->d))
		return (DEAD);

		ft_msleep(time_to_eat, 1);
	}

	return (ALIVE);
}

/* ************************************************************************** */
void philo_give_forks_back(t_philo *p)
{
	// ATTENTION: PEUT-ETRE INVERSER FOURCHETTE
	
	pthread_mutex_unlock(p->mtx_fork_r);
	pthread_mutex_unlock(p->mtx_fork_l);
}

/* ************************************************************************** */
int philo_start_to_sleep(t_philo *p)
{
	int time_to_sleep;

	pthread_mutex_lock(&p->mtx_timeval);
	time_to_sleep = p->d->time_sleep;
	pthread_mutex_unlock(&p->mtx_timeval);

	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_sleep(p);
	
	ft_msleep(time_to_sleep, 80);

	while(!is_activity_finished(&p->tv_think, p))
	{
		if (is_someone_dead_mutex(p->d))
		return (DEAD);

		ft_msleep(time_to_sleep, 1);
	}
	
	return (ALIVE);
}

/* ************************************************************************** */
int philo_start_to_think(t_philo *p)
{
	int time_to_think;
	
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_think (p);

	ft_msleep(p->d->time_think, 20);

	if (is_someone_dead_mutex(p->d))
		return (DEAD);

	return (ALIVE);
}

/* ************************************************************************** */