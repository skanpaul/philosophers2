/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:54:06 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:54:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	*philo_activity(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set_all_stamp_us_mutex(p);
	while (1)
	{
		if (philo_take_forks_left(p) == DEAD)
			break ;
		if (philo_take_forks_right(p) == DEAD)
			break ;
		if (philo_start_to_eat(p) == DEAD)
			break ;
		philo_give_forks_back(p);
		if (philo_count_meal(p) == EAT_ENOUGH_TIME)
			break ;
		if (philo_start_to_sleep(p) == DEAD)
			break ;
		if (philo_start_to_think(p) == DEAD)
			break ;
	}
	return (arg);
}
/* ************************************************************************** */
