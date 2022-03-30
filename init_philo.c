
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int give_pos_fork_right(t_philo *p, int i);

/* ************************************************************************** */
void init_philo_struct(t_philo *philo_list, t_data *d)
{
	int i;
	t_philo *p;

	i = 0;
	while (i < d->max_philo)
	{
		p = &philo_list[i];
		//-----------------------------------------
		p->d = d;
		//-----------------------------------------
		p->pos = i;
		p->id = i + 1;
		p->th_id = 0;
		p->pos_f_l = i;							// init position fork LEFT
		p->pos_f_r = give_pos_fork_right(p, i);	// init position fork RIGHT
		p->mtx_fork_l = &p->d->mtx_fork_list[p->pos_f_l];
		p->mtx_fork_r = &p->d->mtx_fork_list[p->pos_f_r];
		p->philo_dead = false;
		//-----------------------------------------
		p->tv_fork = (t_timeval){0,0};
		p->tv_eat = (t_timeval){0,0};
		p->tv_sleep = (t_timeval){0,0};
		p->tv_think = (t_timeval){0,0};
		p->tv_died = (t_timeval){0,0};
		//-----------------------------------------
		i++;
	}
}

/* ************************************************************************** */
static int give_pos_fork_right(t_philo *p, int i)
{
	if (i == p->d->max_philo - 1)
		return (0);
	else
		return (i + 1);
}

/* ************************************************************************** */