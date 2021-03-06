/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:52:22 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:52:27 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
bool	is_someone_dead_mutex(t_data *d)
{
	bool	answer;

	pthread_mutex_lock(&d->mtx_someone_dead);
	answer = d->someone_dead;
	pthread_mutex_unlock(&d->mtx_someone_dead);
	return (answer);
}

/* ************************************************************************** */
bool	is_this_philo_dead(t_philo *p)
{
	int64_t		stamp_us_now;
	int64_t		stamp_us_died;
	bool		answer;

	stamp_us_now = get_stamp_us_now();
	answer = false;
	pthread_mutex_lock(&p->mtx_stamp_us_died);
	stamp_us_died = p->stamp_us_died;
	pthread_mutex_unlock(&p->mtx_stamp_us_died);
	if (stamp_us_now >= stamp_us_died)
	{
		pthread_mutex_lock(&p->d->mtx_someone_dead);
		answer = true;
		p->d->someone_dead = true;
		print_died(p);
		pthread_mutex_unlock(&p->d->mtx_someone_dead);
	}
	return (answer);
}

/* ************************************************************************** */