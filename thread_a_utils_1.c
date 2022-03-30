
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int take_forks_left(t_philo *p)
{
	int life_status;	
	pthread_mutex_t *fork_list;
	pthread_mutex_t *fork_left;

	life_status = ALIVE;
	fork_list = p->d->mtx_fork_list;
	fork_left = &fork_list[p->pos_f_l];

	pthread_mutex_lock(fork_left);	

	pthread_mutex_lock(&p->d->mtx_someone_dead);
	if (p->philo_dead = true)
		life_status = DEAD;
	else
		print_fork(p);
	pthread_mutex_unlock(&p->d->mtx_someone_dead);

	return (life_status);
}

/* ************************************************************************** */
int take_forks_right(t_philo *p)
{
	int life_status;
	pthread_mutex_t *fork_list;
	pthread_mutex_t *fork_right;

	fork_list = p->d->mtx_fork_list;
	fork_right = &fork_list[p->pos_f_r];

	pthread_mutex_lock(fork_right);	

	pthread_mutex_lock(&p->d->mtx_someone_dead);
	if (p->philo_dead = true)
		life_status = DEAD;
	else
		print_fork(p);
	pthread_mutex_unlock(&p->d->mtx_someone_dead);

	return (ALIVE);
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
	

	gettimeofday_mutex(&p->ts_eat, p);	




	print_eat(p);

	// wait until finis to eat


}

/* ************************************************************************** */