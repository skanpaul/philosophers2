
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int64_t convert_stamp_us(t_timeval *tv)
{
	int64_t stamp_us;

	stamp_us = tv->tv_sec * 1000000 + tv->tv_usec;
	return (stamp_us);
}

/* ************************************************************************** */
int64_t get_stamp_us_now()
{
	t_timeval	now;
	int64_t		stamp_us_now;

	gettimeofday(&now, NULL);
	stamp_us_now = convert_stamp_us(&now);
	return (stamp_us_now);
}

/* ************************************************************************** */
void set_all_stamp_us_mutex(t_philo *p)
{
	int64_t		stamp_us_now;

	stamp_us_now = get_stamp_us_now();
	// --------------------------------------------------------
	pthread_mutex_lock(&p->mtx_timeval);
	p->stamp_us_eat = stamp_us_now;
	p->stamp_us_sleep = p->stamp_us_eat + p->d->time_us_eat;
	p->stamp_us_think = p->stamp_us_sleep + p->d->time_us_sleep;
	p->stamp_us_died = p->stamp_us_eat + p->d->time_us_die;
	pthread_mutex_unlock(&p->mtx_timeval);
	// --------------------------------------------------------
}

/* ************************************************************************** */