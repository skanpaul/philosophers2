/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:52:46 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:52:48 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int	check_end_part1(bool *all_finish_to_eat, t_data *d);
static int	check_end_part2(bool *all_finish_to_eat, t_data *d);

/* ************************************************************************** */
void	*check_end(void *arg)
{
	t_data	*d;
	bool	all_finish_to_eat;

	d = (t_data *)arg;
	while (1)
	{
		if (check_end_part1(&all_finish_to_eat, d) == SHOULD_RETURN)
			return (arg);
		if (check_end_part2(&all_finish_to_eat, d) == SHOULD_RETURN)
			return (arg);
		usleep(50);
	}
	return (arg);
}

/* ************************************************************************** */
static int	check_end_part1(bool *all_finish_to_eat, t_data *d)
{
	int		i;
	bool	eat_enough;
	t_philo	*p;

	i = 0;
	*all_finish_to_eat = true;
	while (i < d->max_philo)
	{
		p = &d->philo_list[i];
		if (is_this_philo_dead(p))
		{
			pthread_mutex_unlock(&d->mtx_finish_main);
			return (SHOULD_RETURN);
		}
		pthread_mutex_lock(&p->mtx_eat_enough);
		eat_enough = p->eat_enough;
		pthread_mutex_unlock(&p->mtx_eat_enough);
		if (eat_enough == false)
			*all_finish_to_eat = false;
		i++;
	}
	return (SHOULD_NOT_RETURN);
}

/* ************************************************************************** */
static int	check_end_part2(bool *all_finish_to_eat, t_data *d)
{
	if (*all_finish_to_eat == true)
	{
		print_max_meal(&d->philo_list[0]);
		pthread_mutex_unlock(&d->mtx_finish_main);
		return (SHOULD_RETURN);
	}
	return (SHOULD_NOT_RETURN);
}

/* ************************************************************************** */
// void	*check_end(void *arg)
// {
// 	t_data	*d;
// 	t_philo	*p;
// 	bool	all_finish_to_eat;
// 	bool	eat_enough;
// 	int		i;

// 	d = (t_data *)arg;
// 	while (1)
// 	{
// 		i = 0;
// 		all_finish_to_eat = true;
// 		while (i < d->max_philo)
// 		{
// 			p = &d->philo_list[i];
// 			if (is_this_philo_dead(p))
// 			{
// 				pthread_mutex_unlock(&d->mtx_finish_main);
// 				return (arg);
// 			}
// 			pthread_mutex_lock(&p->mtx_eat_enough);
// 			eat_enough = p->eat_enough;
// 			pthread_mutex_unlock(&p->mtx_eat_enough);
// 			if (eat_enough == false)
// 				all_finish_to_eat = false;
// 			i++;
// 		}
// 		if (all_finish_to_eat == true)
// 		{
// 			print_max_meal(p);
// 			pthread_mutex_unlock(&d->mtx_finish_main);
// 			return (arg);
// 		}
// 		usleep(50);
// 	}
// 	return (arg);
// }