/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   journal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:43:17 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 12:43:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
void print_has_taken_a_fork(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_printf);
	printf("%d %d has take a fork\n", p->stp_fork, p->id);
	pthread_mutex_unlock(&p->d->mtx_printf);
}

/* ************************************************************************** */
void print_is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_printf);
	printf("%d %d is eating\n", p->stp_eat, p->id);
	pthread_mutex_unlock(&p->d->mtx_printf);
}

/* ************************************************************************** */
void print_is_sleeping(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_printf);
	printf("%d %d is sleeping\n", p->stp_sleep, p->id);
	pthread_mutex_unlock(&p->d->mtx_printf);
}

/* ************************************************************************** */
void print_is_thinking(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_printf);
	printf("%d %d is thinking\n", p->stp_think, p->id);
	pthread_mutex_unlock(&p->d->mtx_printf);
}

/* ************************************************************************** */
void print_is_died(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_printf);
	printf("%d %d died\n", p->stp_died, p->id);
	pthread_mutex_unlock(&p->d->mtx_printf);
}
/* ************************************************************************** */

/* 
• Tout changement d’état d’un philosophe doit être formatté comme suit :

◦ timestamp_in_ms X has taken a fork 

◦ timestamp_in_ms X is eating

◦ timestamp_in_ms X is sleeping

◦ timestamp_in_ms X is thinking

◦ timestamp_in_ms X died 

*/
