
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

	p->n_meal++;

	while(!is_action_finished(p->stamp_us_sleep))
	{
		if (is_someone_dead_mutex(p->d))
			return (DEAD);
	}

	return (ALIVE);
}

/* ************************************************************************** */
void philo_give_forks_back(t_philo *p)
{
	pthread_mutex_unlock(p->mtx_fork_r);
	pthread_mutex_unlock(p->mtx_fork_l);
}

/* ************************************************************************** */
int philo_count_meal(t_philo *p)
{
	if (p->should_count_meal && (p->n_meal >= p->max_meal))
	{
		pthread_mutex_lock(&p->mtx_eat_enough);
		p->eat_enough = true;
		pthread_mutex_unlock(&p->mtx_eat_enough);
		return(EAT_ENOUGH_TIME);
	}

	return (EAT_NOT_ENOUGH_TIME);
}

/* ************************************************************************** */
int philo_start_to_sleep(t_philo *p)
{
	if (is_someone_dead_mutex(p->d))
		return (DEAD);

	print_sleep(p);
	
	while(!is_action_finished(p->stamp_us_think))
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
