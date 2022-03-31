
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
		p->stamp_us_fork = get_stamp_us_now();
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
		p->stamp_us_fork = get_stamp_us_now();
		print_fork(p);
	}

	return (ALIVE);
}

/* ************************************************************************** */
int philo_start_to_eat(t_philo *p)
{
	set_all_stamp_us_mutex(p);
	
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_eat(p);

	while(!is_action_finished(p->stamp_us_sleep, p))
	{
		if (is_someone_dead_mutex(p->d))
			return (DEAD);
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
	if (is_someone_dead_mutex(p->d))
		return (DEAD);

	print_sleep(p);
	
	while(!is_action_finished(p->stamp_us_think, p))
	{
		if (is_someone_dead_mutex(p->d))
			return (DEAD);
	}
	
	return (ALIVE);
}

/* ************************************************************************** */
int philo_start_to_think(t_philo *p)
{	
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_think (p);

	return (ALIVE);
}

/* ************************************************************************** */




















// /* ************************************************************************** */
// int philo_take_forks_left(t_philo *p)
// {	
// 	pthread_mutex_lock(p->mtx_fork_l);	

// 	if (is_someone_dead_mutex(p->d))
// 		return (DEAD);
// 	else
// 	{
// 		set_1_timeval_mutex(&p->tv_fork, p);
// 		print_fork(p);
// 	}

// 	return (ALIVE);
// }

// /* ************************************************************************** */
// int philo_take_forks_right(t_philo *p)
// {
// 	pthread_mutex_lock(p->mtx_fork_r);	

// 	if (is_someone_dead_mutex(p->d))
// 		return (DEAD);
// 	else
// 	{
// 		set_1_timeval_mutex(&p->tv_fork, p);
// 		print_fork(p);
// 	}

// 	return (ALIVE);
// }

// /* ************************************************************************** */
// int philo_start_to_eat(t_philo *p)
// {
// 	set_all_timeval_mutex(p);
	
// 	if (is_someone_dead_mutex(p->d))
// 		return (DEAD);
// 	print_eat(p);

// 	while(!is_activity_finished(&p->tv_sleep, p))
// 	{
// 		if (is_someone_dead_mutex(p->d))
// 			return (DEAD);
// 	}

// 	return (ALIVE);
// }

// /* ************************************************************************** */
// void philo_give_forks_back(t_philo *p)
// {
// 	// ATTENTION: PEUT-ETRE INVERSER FOURCHETTE
	
// 	pthread_mutex_unlock(p->mtx_fork_r);
// 	pthread_mutex_unlock(p->mtx_fork_l);
// }

// /* ************************************************************************** */
// int philo_start_to_sleep(t_philo *p)
// {
// 	if (is_someone_dead_mutex(p->d))
// 		return (DEAD);

// 	print_sleep(p);
	
// 	while(!is_activity_finished(&p->tv_think, p))
// 	{
// 		if (is_someone_dead_mutex(p->d))
// 			return (DEAD);
// 	}
	
// 	return (ALIVE);
// }

// /* ************************************************************************** */
// int philo_start_to_think(t_philo *p)
// {	
// 	if (is_someone_dead_mutex(p->d))
// 		return (DEAD);
// 	print_think (p);

// 	return (ALIVE);
// }

// /* ************************************************************************** */