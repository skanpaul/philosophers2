
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int64_t conv_stamp_us_from_tv(t_timeval *tv)
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
	stamp_us_now = conv_stamp_us_from_tv(&now);
	return (stamp_us_now);
}

/* ************************************************************************** */
void set_all_stamp_us_mutex(t_philo *p)
{
	int64_t		stamp_us_now;

	stamp_us_now = get_stamp_us_now();
	// --------------------------------------------------------
	pthread_mutex_lock(&p->mtx_stamp_us_died);
	p->stamp_us_died = stamp_us_now + p->d->time_us_die;
	pthread_mutex_unlock(&p->mtx_stamp_us_died);
	// --------------------------------------------------------
	p->stamp_us_eat = stamp_us_now;
	p->stamp_us_sleep = p->stamp_us_eat + p->d->time_us_eat;
	p->stamp_us_think = p->stamp_us_sleep + p->d->time_us_sleep;
}

/* ************************************************************************** */
bool is_action_finished(uint64_t stamp_us_next_activity, t_philo *p)
{
	uint64_t stamp_us_now;

	stamp_us_now = get_stamp_us_now();

	if(stamp_us_now >= stamp_us_next_activity)
		return (true);

	return (false);
}

/* ************************************************************************** */

