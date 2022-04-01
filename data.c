/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:53:01 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:53:12 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static void	print_info(t_data *d);
static void	init_time_us(t_data *d);

/* ************************************************************************** */
void	init_basic_data(t_data *d)
{
	d->max_philo = 0;
	d->time_die = 0;
	d->time_eat = 0;
	d->time_sleep = 0;
	d->time_think = 0;
	d->max_eat = 0;
	d->operation = 0;
	d->someone_dead = false;
	d->philo_list = NULL;
	d->mtx_fork_list = NULL;
}

/* ************************************************************************** */
int	save_game_data(int argc, char **argv, t_data *d)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_countable(argv[i]))
			return (ERROR);
		i++;
	}
	d->max_philo = ft_atoi(argv[1]);
	d->time_die = ft_atoi(argv[2]);
	d->time_eat = ft_atoi(argv[3]);
	d->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		d->max_eat = ft_atoi(argv[5]);
		d->should_count_meal = true;
	}
	init_time_us(d);
	print_info(d);
	return (NO_ERROR);
}

/* ************************************************************************** */
int	check_game_data(t_data *d, int argc)
{
	if (d->max_philo <= 0)
		return (print_error(TYPE_ERR_MAX_PHILO));
	if (d->time_die < 0 || d->time_eat < 0 || d->time_sleep < 0)
		return (print_error(TYPE_ERR_TIME_NEGATIVE));
	if (argc == 6 && d->max_eat < 1)
		return (print_error(TYPE_ERR_MAX_EAT));
	return (NO_ERROR);
}

/* ************************************************************************** */
static void	init_time_us(t_data *d)
{
	d->time_us_die = d->time_die * 1000;
	d->time_us_eat = d->time_eat * 1000;
	d->time_us_sleep = d->time_sleep * 1000;
	d->time_think = d->time_die - d->time_eat - d->time_sleep;
	if (d->time_think <= 0)
		d->time_think = 0;
	d->time_us_think = d->time_think * 1000;
}

/* ************************************************************************** */
static void	print_info(t_data *d)
{
	if (INFO)
	{
		printf("max_philo: \t%d\n", d->max_philo);
		printf("time_die: \t%d\t[ms]\n", d->time_die);
		printf("time_eat: \t%d\t[ms]\n", d->time_eat);
		printf("time_sleep: \t%d\t[ms]\n", d->time_sleep);
		printf("max_eat: \t%d\n", d->max_eat);
		printf("\n");
	}
}

/* ************************************************************************** */