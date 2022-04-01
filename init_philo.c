/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:53:23 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:53:26 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int	give_pos_fork_right(t_philo *p, int i);
static void	init_part_1(t_philo *p, int i, t_data *d);
static void	init_part_2(t_philo *p);

/* ************************************************************************** */
void	init_philo_struct(t_philo *philo_list, t_data *d)
{
	int		i;
	t_philo	*p;

	i = 0;
	while (i < d->max_philo)
	{
		p = &philo_list[i];
		init_part_1(p, i, d);
		init_part_2(p);
		i++;
	}
}

/* ************************************************************************** */
static void	init_part_1(t_philo *p, int i, t_data *d)
{
	p->d = d;
	p->id = i + 1;
	p->th_id = 0;
	p->pos_f_l = i;
	p->pos_f_r = give_pos_fork_right(p, i);
	p->mtx_fork_l = &p->d->mtx_fork_list[p->pos_f_l];
	p->mtx_fork_r = &p->d->mtx_fork_list[p->pos_f_r];
	p->should_count_meal = false;
	p->n_meal = 0;
	p->max_meal = p->d->max_eat;
	p->eat_enough = false;
}

/* ************************************************************************** */
static void	init_part_2(t_philo *p)
{
	p->stamp_us_start = 0;
	p->stamp_us_fork = 0;
	p->stamp_us_eat = 0;
	p->stamp_us_sleep = 0;
	p->stamp_us_think = 0;
	p->stamp_us_died = 0;
}

/* ************************************************************************** */
static int	give_pos_fork_right(t_philo *p, int i)
{
	if (i == p->d->max_philo - 1)
		return (0);
	else
		return (i + 1);
}

/* ************************************************************************** */
