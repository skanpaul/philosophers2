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
void gettimeofday_mutex(t_timeval *tv, t_philo *p)
{
	pthread_mutex_lock(&p->mtx_timestamp);
	gettimeofday(tv, NULL);
	pthread_mutex_unlock(&p->mtx_timestamp);
}

/* ************************************************************************** */
int get_ms_diff(t_timeval *now, t_timeval *ts)
{
	int diff_s;
	int diff_us;
	int diff_ms;

	diff_s = 0;
	diff_ms = 0;
	diff_us = 0;

	if (now->tv_sec == ts->tv_sec)
	{
		diff_us = now->tv_usec - ts->tv_usec;
		diff_ms = diff_us / 1000;
	}
	else
	{
		diff_s = now->tv_sec - ts->tv_sec;
		diff_us = (1000000 - ts->tv_usec) + now->tv_usec;
		diff_ms = diff_s * 1000 + diff_us / 1000;
	}
	return (diff_ms);
}

/* ************************************************************************** */
void add_ms_to_timeval(int add_ms, t_timeval *ts)
{
	int add_s;
	int add_us;
	int buff_us;

	add_s = add_ms / 1000;
	add_us = (add_ms % 1000) * 1000;
	ts->tv_sec += add_s;

	buff_us = ts->tv_usec + add_us;

	add_s = buff_us / 1000000;
	add_us = buff_us % 1000000;

	ts->tv_sec += add_s;
	ts->tv_usec = add_us;
}

/* ************************************************************************** */
// void set_all_timestamp_from_start_eating(t_philo *p)
// {
// 	int timestamp;

// 	timestamp = get_timestamp();
// 	p->stp_eat = timestamp;
// 	p->stp_sleep = p->stp_eat + p->d->time_eat;
// 	p->stp_think = p->stp_sleep + p->d->time_sleep;
// 	p->stp_died = p->stp_eat + p->d->time_die;
// }

/* ************************************************************************** */