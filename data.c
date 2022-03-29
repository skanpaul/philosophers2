
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
	d->philo_list = NULL;
	// d->thread_check_life
    d->mtx_fork_list = NULL;
	// d->mtx_one_is_dead
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
int check_game_data(t_data *d, int argc)
{
	if (INFO == 0)
		return (NO_ERROR);

	if (d->max_philo <= 0)
        return (print_error(TYPE_ERR_MAX_PHILO));

	if (d->time_die < 0 || d->time_eat < 0 || d->time_sleep < 0)
		return (print_error(TYPE_ERR_TIME_NEGATIVE));

	if (d->time_eat + d->time_sleep > d->time_die)
        return (print_error(TYPE_ERR_TIME_EAT_SLEEP));

	if (argc == 6 && d->max_eat < 1)
		return (print_error(TYPE_ERR_MAX_EAT));


	return (NO_ERROR);
}


/* ************************************************************************** */