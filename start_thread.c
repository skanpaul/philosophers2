/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:57:01 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:57:03 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	start_thread(t_data *d)
{
	int			i;
	t_timeval	tv_start_game;
	int64_t		stamp_us_start_game;
	t_philo		*p;

	gettimeofday(&tv_start_game, NULL);
	stamp_us_start_game = conv_stamp_us_from_tv(&tv_start_game);
	i = 0;
	while (i < d->max_philo)
	{
		p = &d->philo_list[i];
		p->stamp_us_start = stamp_us_start_game;
		p->should_count_meal = d->should_count_meal;
		if (pthread_create(&p->th_id, NULL, &philo_activity, (void *)p) != 0)
			return (print_error(TYPE_ERR_THD_CREATE));
		usleep(100);
		i++;
	}
	if (pthread_create(&d->thd_check_life, NULL, &check_end, (void *)d) != 0)
		return (print_error(TYPE_ERR_THD_CREATE));
	return (NO_ERROR);
}

/* ************************************************************************** */
