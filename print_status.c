
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void print_life(t_philo *p)
{
	print_mutex(p, &p->tv_eat, MSG_LIFE);
}

/* ************************************************************************** */
void print_fork(t_philo *p)
{
	print_mutex(p, &p->tv_fork, MSG_FORK);
}

/* ************************************************************************** */
void print_eat(t_philo *p)
{
	print_mutex(p, &p->tv_eat, MSG_EAT);
}

/* ************************************************************************** */
void print_sleep(t_philo *p)
{
	print_mutex(p, &p->tv_sleep, MSG_SLEEP);
}

/* ************************************************************************** */
void print_think(t_philo *p)
{
	print_mutex(p, &p->tv_think, MSG_THINK);
}

/* ************************************************************************** */
void print_died(t_philo *p)
{
	print_mutex(p, &p->tv_died, MSG_DIED);
}

/* ************************************************************************** */
void print_mutex(t_philo *p, t_timeval *timeval, char *msg)
{
	pthread_mutex_lock(&p->d->mtx_message);
	printf("%16ld[ms] %d %s", timeval->tv_usec / 1000, p->id, msg);
	pthread_mutex_unlock(&p->d->mtx_message);
}

/* ************************************************************************** */