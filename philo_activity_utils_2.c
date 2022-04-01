/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:54:20 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:54:22 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	philo_count_meal(t_philo *p)
{
	if (p->should_count_meal && (p->n_meal >= p->max_meal))
	{
		pthread_mutex_lock(&p->mtx_eat_enough);
		p->eat_enough = true;
		pthread_mutex_unlock(&p->mtx_eat_enough);
		return (EAT_ENOUGH_TIME);
	}
	return (EAT_NOT_ENOUGH_TIME);
}

/* ************************************************************************** */
int	philo_start_to_sleep(t_philo *p)
{
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_sleep(p);
	while (!is_action_finished(p->stamp_us_think))
	{
		if (is_someone_dead_mutex(p->d))
			return (DEAD);
	}	
	return (ALIVE);
}

/* ************************************************************************** */
int	philo_start_to_think(t_philo *p)
{	
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_think (p);
	return (ALIVE);
}

/* ************************************************************************** */
