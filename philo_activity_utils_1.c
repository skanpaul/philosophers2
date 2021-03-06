/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:54:20 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:54:22 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	philo_take_forks_left(t_philo *p)
{	
	pthread_mutex_lock(p->mtx_fork_l);
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	else
	{
		p->stamp_us_fork = get_stamp_us_now();
		print_fork(p);
	}
	return (ALIVE);
}

/* ************************************************************************** */
int	philo_take_forks_right(t_philo *p)
{
	pthread_mutex_lock(p->mtx_fork_r);
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	else
	{
		p->stamp_us_fork = get_stamp_us_now();
		print_fork(p);
	}
	return (ALIVE);
}

/* ************************************************************************** */
int	philo_start_to_eat(t_philo *p)
{
	set_all_stamp_us_mutex(p);
	if (is_someone_dead_mutex(p->d))
		return (DEAD);
	print_eat(p);
	p->n_meal++;
	while (!is_action_finished(p->stamp_us_sleep))
	{
		if (is_someone_dead_mutex(p->d))
			return (DEAD);
	}
	return (ALIVE);
}

/* ************************************************************************** */
void	philo_give_forks_back(t_philo *p)
{
	pthread_mutex_unlock(p->mtx_fork_r);
	pthread_mutex_unlock(p->mtx_fork_l);
}

/* ************************************************************************** */