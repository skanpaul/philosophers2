
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void print_fork(t_philo *p)
{
	print_mutex(p, p->stamp_us_fork, MSG_FORK);
}

/* ************************************************************************** */
void print_eat(t_philo *p)
{
	print_mutex(p, p->stamp_us_eat, MSG_EAT);
}

/* ************************************************************************** */
void print_sleep(t_philo *p)
{
	print_mutex(p, p->stamp_us_sleep, MSG_SLEEP);
}

/* ************************************************************************** */
void print_think(t_philo *p)
{
	print_mutex(p, p->stamp_us_think, MSG_THINK);
}

/* ************************************************************************** */
void print_died(t_philo *p)
{
	print_mutex(p, p->stamp_us_died, MSG_DIED);
}

/* ************************************************************************** */
void print_mutex(t_philo *p, int64_t stamp_us, char *msg)
{
	int64_t stamp_ms;

	stamp_ms= (stamp_us - p->stamp_us_start) / 1000;
	pthread_mutex_lock(&p->d->mtx_message);
	printf("op:%5d | %15lld[ms] %d %s", p->d->operation, stamp_ms, p->id, msg);
	p->d->operation++;
	pthread_mutex_unlock(&p->d->mtx_message);
}
/* ************************************************************************** */