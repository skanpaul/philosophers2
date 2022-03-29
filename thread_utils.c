
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void take_forks(t_philo *p)
{
	pthread_mutex_t *fork_list;
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;

	fork_list = p->d->mtx_fork_list;

	fork_left = &fork_list[p->pos_f_l];
	fork_right = &fork_list[p->pos_f_r];

	pthread_mutex_lock(fork_left);
	//print has taken a fork
	pthread_mutex_lock(fork_right);
	//print has taken a fork
}

/* ************************************************************************** */
void give_forks_back(t_philo *p)
{
	pthread_mutex_t *fork_list;
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;

	fork_list = p->d->mtx_fork_list;

	fork_left = &fork_list[p->pos_f_l];
	fork_right = &fork_list[p->pos_f_r];

	pthread_mutex_unlock(fork_left);
	pthread_mutex_unlock(fork_right);
}

/* ************************************************************************** */
void eat(t_philo *p)
{
	// start to eat
	gettimeofday(&p->ts_eat, NULL);




	print_eat(p);

	// wait until finis to eat


}

/* ************************************************************************** */