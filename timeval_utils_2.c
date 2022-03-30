
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int get_timestamp(t_timeval *tv, t_philo *p)
{
	int64_t tv_ms;
	int64_t start_ms;
	int64_t result_ms;

	pthread_mutex_lock(&p->mtx_timeval);
	tv_ms = (tv->tv_sec * 1000) + (tv->tv_usec / 1000);
	start_ms = (p->tv_start.tv_sec * 1000) + (p->tv_start.tv_usec / 1000);
	pthread_mutex_unlock(&p->mtx_timeval);

	result_ms = tv_ms - start_ms;

	return ((int)result_ms);
}

/* ************************************************************************** */