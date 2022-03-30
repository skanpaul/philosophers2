
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int give_pos_fork_right(t_philo *p, int i);

/* ************************************************************************** */
void init_philo_struct(t_philo *p, t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		p[i].d = d;
		//-----------------------------------------
		p[i].pos = i;
		p[i].id = i + 1;
		p[i].th_id = 0;
		p[i].pos_f_l = i;							// init position fork LEFT
		p[i].pos_f_r = give_pos_fork_right(p, i);	// init position fork RIGHT
		p[i].philo_dead = false;
		//-----------------------------------------
		p[i].tv_fork = (t_timeval){0,0};
		p[i].tv_eat = (t_timeval){0,0};
		p[i].tv_sleep = (t_timeval){0,0};
		p[i].tv_think = (t_timeval){0,0};
		p[i].tv_died = (t_timeval){0,0};
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

// /* ************************************************************************** */
// void	give_fork_pos(t_philo *p)
// {
// 	int i;

// 	i = 0;
// 	while (i < d->max_philo)
// 	{
// 		p[i].fork_left = &f[i];

// 		if (i == d->max_philo - 1)
// 			p[i].fork_right = &f[0];
// 		else
// 			p[i].fork_right = &f[i + 1];
// 		i++;
// 	}

// 	return ;
// }
/* ************************************************************************** */