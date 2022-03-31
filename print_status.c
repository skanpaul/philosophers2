
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
void print_max_meal(t_philo *p)
{
	int64_t stamp_us_now;
	int64_t stamp_us_max_meal;

	stamp_us_now = get_stamp_us_now();
	stamp_us_max_meal = (stamp_us_now - p->stamp_us_start) / 1000;
	
	pthread_mutex_lock(&p->d->mtx_message);
	printf("           %15lld[ms] EVERY ONE HAVE EATEN %d MEAL(S)\n",
						stamp_us_max_meal, p->max_meal);
	pthread_mutex_unlock(&p->d->mtx_message);
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