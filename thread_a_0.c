/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_a_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:54:06 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:54:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void *philo_activity(void *arg)
{
	t_philo *p;

	p = (t_philo *)arg;	
	set_all_stamp_us_mutex(p);

	// START-LOOP --------------------------------------------------------
	while (1)
	{
		// TAKE FORKS LEFT
		if (philo_take_forks_left(p) == DEAD)
			break;
		// TAKE FORKS RIGHT
		if (philo_take_forks_right(p) == DEAD)
			break;

		// EAT & WAIT: finis to eat
		if (philo_start_to_eat(p) == DEAD)
			break;

		// GIVE FORKS BACK
		philo_give_forks_back(p);

		// COUNT MEAL (if necessary)
		if (philo_count_meal(p) == EAT_ENOUGH_TIME)
			break;

		// SLEEP & WAIT: finis to sleep
		if (philo_start_to_sleep(p) == DEAD)
			break;

		// THINK: when necessary TAKE FORK AND EAT
		if (philo_start_to_think(p) == DEAD)
			break;

	}
	// END-LOOP ---------------------------------------------------------

	return (arg);
}
/* ************************************************************************** */
