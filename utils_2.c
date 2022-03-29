
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int malloc_philos_and_forks_and_thread(t_data *d)
{
	int i;

	// MALLOC philo struct
	if ((d->philo_list = malloc(d->max_philo * sizeof(t_philo))) == NULL)
		return(print_error(TYPE_ERR_MALLOC_PHILO));

	// MALLOC thread ID
	if ((d->thread_list = malloc(d->max_philo * sizeof(pthread_t))) == NULL)
		return (print_error(TYPE_ERR_MALLOC_THREAD));

	// MALLOC mutex FORK
	if ((d->mtx_fork_list = malloc(d->max_philo * sizeof(pthread_mutex_t))) == NULL)
		return (print_error(TYPE_ERR_MALLOC_MUTEX));

	return (NO_ERROR);
}
/* ************************************************************************** */
int init_all_mutex(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		if (pthread_mutex_init(&d->mtx_fork_list[i], NULL) != 0)
			return (print_error(TYPE_ERR_MTX_INIT));
		i++;
	}

	if (pthread_mutex_init(&d->mtx_one_is_dead, NULL) != 0)
		return (print_error(TYPE_ERR_MTX_INIT));

	return (NO_ERROR);
}

/* ************************************************************************** */
void destroy_all_mutex(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		pthread_mutex_destroy(&d->mtx_fork_list[i]);
		i++;
	}

	pthread_mutex_destroy(&d->mtx_one_is_dead);
}

/* ************************************************************************** */
int clean_game(t_data *d)
{
	destroy_all_mutex(d);
	free_all_malloc(d);
	return (NO_ERROR);
}

/* ************************************************************************** */
int free_all_malloc(t_data *d)
{
	if (d->philo_list != NULL)
		free(d->philo_list);
	d->philo_list = NULL;

	if (d->thread_list != NULL)
		free(d->thread_list);
	d->thread_list = NULL;

	if (d->mtx_fork_list != NULL)
		free(d->mtx_fork_list);
	d->mtx_fork_list = NULL;

	return (NO_ERROR);
}

/* ************************************************************************** */