
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int philo_take_forks_left(t_philo *p)
{	
	// pthread_mutex_t *fork_list;
	// pthread_mutex_t *fork_left;

	// fork_list = p->d->mtx_fork_list;
	// fork_left = &fork_list[p->pos_f_l];
	// pthread_mutex_lock(fork_left);	

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
	// pthread_mutex_t *fork_list;
	// pthread_mutex_t *fork_right;

	// fork_list = p->d->mtx_fork_list;
	// fork_right = &fork_list[p->pos_f_r];
	// pthread_mutex_lock(fork_right);	

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
	// pthread_mutex_t *fork_list;
	// pthread_mutex_t *fork_left;
	// pthread_mutex_t *fork_right;

	// fork_list = p->d->mtx_fork_list;

	// fork_left = &fork_list[p->pos_f_l];
	// fork_right = &fork_list[p->pos_f_r];

	pthread_mutex_unlock(p->mtx_fork_r);
	pthread_mutex_unlock(p->mtx_fork_l);
	// pthread_mutex_unlock(fork_left);
	// pthread_mutex_unlock(fork_right);
}

/* ************************************************************************** */