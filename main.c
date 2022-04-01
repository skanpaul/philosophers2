/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:53:34 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:53:36 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	main(int argc, char **argv)
{
	t_data	d;

	init_basic_data(&d);
	if (argc - 1 < 4 || argc - 1 > 5)
		return (print_error(TYPE_ERR_ARG));
	if (save_game_data(argc, argv, &d) == ERROR)
		return (print_error(TYPE_ERR_CNT));
	if (check_game_data(&d, argc) == ERROR)
		return (ERROR);
	if (malloc_philos_and_forks_and_thread(&d) == ERROR)
		return (ERROR + free_all_malloc(&d));
	init_philo_struct(d.philo_list, &d);
	if (init_all_mutex(&d) == ERROR)
		return (ERROR + clean_game(&d));
	pthread_mutex_lock(&d.mtx_finish_main);
	if (start_thread(&d) == ERROR)
		return (ERROR + clean_game(&d));
	pthread_mutex_lock(&d.mtx_finish_main);
	clean_game(&d);
	return (NO_ERROR);
}

/* ************************************************************************** */
