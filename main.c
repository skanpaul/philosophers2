
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int main(int argc, char **argv)
{
	t_data d;

	/* -------------------------------------------- */
	init_basic_data(&d);
	if (argc - 1 < 4 || argc - 1 > 5)
		return (print_error(TYPE_ERR_ARG));		
	if(save_game_data(argc, argv, &d) == ERROR)
		return (print_error(TYPE_ERR_CNT));
	if (check_game_data(&d, argc) == ERROR)
		return (ERROR);
	/* -------------------------------------------- */
	if (malloc_philos_and_forks_and_thread(&d) == ERROR)
		return (ERROR + free_all_malloc(&d));
	init_philo_struct(d.philo_list, &d);
	if (init_all_mutex(&d) == ERROR)
		return (ERROR + clean_game(&d));
	/* -------------------------------------------- */

	pthread_mutex_lock(&d.mtx_finish_main);

	if (start_thread(&d) == ERROR)
		return (ERROR + clean_game(&d));

	pthread_mutex_lock(&d.mtx_finish_main);

	/* -------------------------------------------- */
	clean_game(&d);
	return (NO_ERROR);
}

/* ************************************************************************** */
	// t_timeval new;
	// t_timeval old;
	// gettimeofday(&old, NULL);
	// while (1)
	// {
	// 	gettimeofday(&new, NULL);
	// 	printf("[%ld][%ld]\n", new.tv_sec, new.tv_usec);
	// 	printf("diff_ms: %d\n", get_ms_diff(&new, &old));
	// 	old = new;
	// }
/* ************************************************************************** */
	// t_timeval new;
	// int time_ms = 23051;

	// new.tv_sec = 12;
	// new.tv_usec = 950000;
	// add_ms_to_timeval(time_ms, &new);

/* ************************************************************************** */
	// printf("size of int: %lu byte\n", sizeof(int));
	// printf("size of long int: %lu byte\n", sizeof(long int));
	// printf("size of long long int: %lu byte\n", sizeof(long long int));
	// printf("size of int64_t: %lu byte\n", sizeof(int64_t));
/* ************************************************************************** */
