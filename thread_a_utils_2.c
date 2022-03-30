
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
bool is_someone_dead_mutex(t_data *d)
{
	bool answer;

	pthread_mutex_lock(&d->mtx_someone_dead);
	answer = d->someone_dead;
	pthread_mutex_unlock(&d->mtx_someone_dead);
	return (answer);
}
/* ************************************************************************** */