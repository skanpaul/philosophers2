
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void print_born(t_philo *p)
{
	// print_mutex(p, &p->tv_eat, MSG_LIFE);
	print_mutex(p, p->stamp_us_born, MSG_LIFE);
}

/* ************************************************************************** */
void print_fork(t_philo *p)
{
	// print_mutex(p, &p->tv_fork, MSG_FORK);
	print_mutex(p, p->stamp_us_fork, MSG_FORK);
}

/* ************************************************************************** */
void print_eat(t_philo *p)
{
	// print_mutex(p, &p->tv_eat, MSG_EAT);
	print_mutex(p, p->stamp_us_eat, MSG_EAT);
}

/* ************************************************************************** */
void print_sleep(t_philo *p)
{
	// print_mutex(p, &p->tv_sleep, MSG_SLEEP);
	print_mutex(p, p->stamp_us_sleep, MSG_SLEEP);
}

/* ************************************************************************** */
void print_think(t_philo *p)
{
	// print_mutex(p, &p->tv_think, MSG_THINK);
	print_mutex(p, p->stamp_us_think, MSG_THINK);
}

/* ************************************************************************** */
void print_died(t_philo *p)
{
	// print_mutex(p, &p->tv_died, MSG_DIED);
	print_mutex(p, p->stamp_us_died, MSG_DIED);
}

/* ************************************************************************** */
// void print_mutex(t_philo *p, t_timeval *timeval, char *msg)
void print_mutex(t_philo *p, int64_t stamp_us, char *msg)
{
	int64_t stamp_ms;

	stamp_ms= (stamp_us - p->stamp_us_start) / 1000;

	// pthread_mutex_lock(&p->d->mtx_message);

	printf("op:%5d | %15lld[ms] %d %s", p->d->operation, stamp_ms, p->id, msg);
	p->d->operation++;
	// pthread_mutex_unlock(&p->d->mtx_message);
}
/* ************************************************************************** */














// /* ************************************************************************** */
// #include "main.h"

// /* ************************************************************************** */
// void print_born(t_philo *p)
// {
// 	print_mutex(p, &p->tv_eat, MSG_LIFE);
// }

// /* ************************************************************************** */
// void print_fork(t_philo *p)
// {
// 	print_mutex(p, &p->tv_fork, MSG_FORK);
// }

// /* ************************************************************************** */
// void print_eat(t_philo *p)
// {
// 	print_mutex(p, &p->tv_eat, MSG_EAT);
// }

// /* ************************************************************************** */
// void print_sleep(t_philo *p)
// {
// 	print_mutex(p, &p->tv_sleep, MSG_SLEEP);
// }

// /* ************************************************************************** */
// void print_think(t_philo *p)
// {
// 	print_mutex(p, &p->tv_think, MSG_THINK);
// }

// /* ************************************************************************** */
// void print_died(t_philo *p)
// {
// 	print_mutex(p, &p->tv_died, MSG_DIED);
// }

// /* ************************************************************************** */
// // void print_mutex(t_philo *p, t_timeval *timeval, char *msg)
// // {	
// // 	pthread_mutex_lock(&p->d->mtx_message);
// // 	printf("%16ld[ms] %d %s", timeval->tv_usec / 1000, p->id, msg);
// // 	pthread_mutex_unlock(&p->d->mtx_message);
// // }

// /* ************************************************************************** */
// void print_mutex(t_philo *p, t_timeval *timeval, char *msg)
// {
// 	long int stamp;
	
// 	// pthread_mutex_lock(&p->d->mtx_message);
// 	stamp = get_timestamp(timeval, p);
// 	printf("op:%10d | %10ld[ms] %d %s", p->d->operation, stamp, p->id, msg);
// 	p->d->operation++;
// 	// pthread_mutex_unlock(&p->d->mtx_message);
// }
// /* ************************************************************************** */