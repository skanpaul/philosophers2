/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:19:03 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 13:19:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void set_all_timeval_mutex(t_philo *p)
{
	t_timeval now;
	gettimeofday(&now, NULL);

	pthread_mutex_lock(&p->mtx_timeval);
	p->tv_eat = now;
	p->tv_sleep = now;
	p->tv_think = now;
	add_ms_to_timeval(p->d->time_eat, &p->tv_sleep);
	add_ms_to_timeval(p->d->time_eat + p->d->time_sleep, &p->tv_think);
	add_ms_to_timeval(p->d->time_die, &p->tv_died);
	pthread_mutex_unlock(&p->mtx_timeval);
}

/* ************************************************************************** */
void set_1_timeval_mutex(t_timeval *timestamp, t_philo *p)
{
	pthread_mutex_lock(&p->mtx_timeval);
	gettimeofday(timestamp, NULL);
	pthread_mutex_unlock(&p->mtx_timeval);
}

/* ************************************************************************** */
int get_ms_diff(t_timeval *now, t_timeval *tv)
{
	int diff_s;
	int diff_us;
	int diff_ms;

	diff_s = 0;
	diff_ms = 0;
	diff_us = 0;

	if (now->tv_sec == tv->tv_sec)
	{
		diff_us = now->tv_usec - tv->tv_usec;
		diff_ms = diff_us / 1000;
	}
	else
	{
		diff_s = now->tv_sec - tv->tv_sec;
		diff_us = (1000000 - tv->tv_usec) + now->tv_usec;
		diff_ms = diff_s * 1000 + diff_us / 1000;
	}
	return (diff_ms);
}

/* ************************************************************************** */
void add_ms_to_timeval(int add_ms, t_timeval *tv)
{
	int add_s;
	int add_us;
	int buff_us;

	add_s = add_ms / 1000;
	add_us = (add_ms % 1000) * 1000;
	tv->tv_sec += add_s;

	buff_us = tv->tv_usec + add_us;

	add_s = buff_us / 1000000;
	add_us = buff_us % 1000000;

	tv->tv_sec += add_s;
	tv->tv_usec = add_us;
}

/* ************************************************************************** */
bool is_timeval_greater_or_equal_to(t_timeval *tv_a, t_timeval *tv_b)
{
	if (tv_a->tv_sec < tv_b->tv_sec)
		return (false);

	if (tv_a->tv_sec > tv_b->tv_sec)
		return (true);

	if (tv_a->tv_sec == tv_b->tv_sec && tv_a->tv_usec > tv_b->tv_usec )
		return (true);

	return (false);
}

/* ************************************************************************** */
bool is_activity_finished(t_timeval *tv_end, t_philo *p)
{
	bool answer;
	t_timeval now;

	answer = false;
	pthread_mutex_lock(&p->mtx_timeval);
	gettimeofday(&now, NULL);

	if (is_timeval_greater_or_equal_to(&now, &p->tv_sleep))
		answer = true;

	pthread_mutex_unlock(&p->mtx_timeval);

	return (answer);
}

/* ************************************************************************** */