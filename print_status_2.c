/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:53:52 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:53:54 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	print_max_meal(t_philo *p)
{
	int64_t	stamp_us_now;
	int64_t	stamp_us_max_meal;

	stamp_us_now = get_stamp_us_now();
	stamp_us_max_meal = (stamp_us_now - p->stamp_us_start) / 1000;
	pthread_mutex_lock(&p->d->mtx_message);
	if (INFO == 1)
	{
		printf("           %15lld[ms] EVERY ONE HAVE EATEN %d MEAL(S)\n",
			stamp_us_max_meal, p->max_meal);
	}
	else
	{
		printf("%15lld[ms] EVERY ONE HAVE EATEN %d MEAL(S)\n",
			stamp_us_max_meal, p->max_meal);
	}
	pthread_mutex_unlock(&p->d->mtx_message);
}

/* ************************************************************************** */
void	print_mutex(t_philo *p, int64_t stamp_us, char *msg)
{
	int64_t	stamp_ms;

	stamp_ms = (stamp_us - p->stamp_us_start) / 1000;
	pthread_mutex_lock(&p->d->mtx_message);
	if (INFO == 1)
	{
		printf("op:%5d | %15lld[ms] %d %s",
			p->d->operation, stamp_ms, p->id, msg);
	}
	else
	{
		printf("%15lld[ms] %d %s",
			stamp_ms, p->id, msg);
	}
	p->d->operation++;
	pthread_mutex_unlock(&p->d->mtx_message);
}

/* ************************************************************************** */