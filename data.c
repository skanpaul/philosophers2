
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void init_basic_data(t_data *d)
{
    d->max_philo = 0;
	d->time_die = 0;
	d->time_eat = 0;
	d->time_sleep = 0;
	d->max_eat = 0;
    // ------------------------   
    d->thr_id_list = NULL;
    d->mtx_fork_list = NULL;
    //d->mtx_one_is_dead = NULL;
}

/* ************************************************************************** */
int save_game_data(int argc, char **argv, t_data *d)
{
	int i;

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
		d->max_eat = ft_atoi(argv[5]);

	if (INFO)
	{
		printf("max_philo: \t%d\n", d->max_philo);
		printf("time_die: \t%d\t[ms]\n", d->time_die);
		printf("time_eat: \t%d\t[ms]\n", d->time_eat);
		printf("time_sleep: \t%d\t[ms]\n", d->time_sleep);
		printf("max_eat: \t%d\n", d->max_eat);
		printf("\n");
	}
	return (NO_ERROR);
}

/* ************************************************************************** */
int check_game_data(t_data *d)
{
	if (INFO == 0)
		return (NO_ERROR);

	if (d->max_philo <= 0)
        return (print_error(TYPE_ERR_MAX_PHILO));

	if (d->time_eat + d->time_sleep > d->time_die)
        return (print_error(TYPE_ERR_TIME_EAT_SLEEP));


	return (NO_ERROR);
}

/* ************************************************************************** */
int add_game_data(t_data *d)
{
	int i;

	if ((d->thr_id_list = malloc(d->max_philo * sizeof(pthread_t))) == NULL)
		return (print_error(TYPE_ERR_MALLOC_THREAD));

	if ((d->mtx_fork_list = malloc(d->max_philo * sizeof(pthread_mutex_t))) == NULL)
		return (print_error(TYPE_ERR_MALLOC_MUTEX));

	// mutex: someone_is_dead already create in d

	return (NO_ERROR);
}

/* ************************************************************************** */
int clean_game_data(t_data *d)
{
	if (d->thr_id_list != NULL)
		free(d->thr_id_list);
	d->thr_id_list = NULL;

	if (d->mtx_fork_list != NULL)
		free(d->mtx_fork_list);
	d->mtx_fork_list = NULL;
	
	return (NO_ERROR);
}
/* ************************************************************************** */