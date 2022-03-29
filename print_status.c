
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void print_fork(t_philo *p)
{
	print_mutex(p, p->ts_fork, MSG_FORK);
}

/* ************************************************************************** */
void print_eat(t_philo *p)
{
	print_mutex(p, p->ts_eat, MSG_EAT);
}

/* ************************************************************************** */
void print_sleep(t_philo *p)
{
	print_mutex(p, p->ts_sleep, MSG_SLEEP);
}

/* ************************************************************************** */
void print_think(t_philo *p)
{
	print_mutex(p, p->ts_think, MSG_THINK);
}

/* ************************************************************************** */
void print_died(t_philo *p)
{
	print_mutex(p, p->ts_died, MSG_DIED);
}

/* ************************************************************************** */
void print_mutex(t_philo *p, int timestamp, char *msg)
{
	pthread_mutex_lock(&p->d->mtx_message);
	printf("%d %d %s", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->d->mtx_message);
}

/* ************************************************************************** */