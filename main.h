

/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# define INFO			1
# define ERRORING		1
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define TYPE_ERR_ARG				0
# define TYPE_ERR_CNT				1
# define TYPE_ERR_MALLOC_THREAD		2
# define TYPE_ERR_MALLOC_MUTEX		3
// ----------------------------------
# define TYPE_ERR_MAX_PHILO			4
# define TYPE_ERR_TIME_EAT_SLEEP	5
/* -------------------------------------------------------- */
# define MSG_ERR_ARG	"ERROR: number of argument\n"
# define MSG_ERR_CNT	"ERROR: argument NOT COUNTABLE\n"
# define MSG_ERR_MALLOC_THREAD	"ERROR: malloc THREAD\n"
# define MSG_ERR_MALLOC_MUTEX	"ERROR: malloc MUTEX\n"
// ----------------------------------
# define MSG_ERR_MAX_PHILO "ERROR: philosopers number (NOT ENOUGH)\n"
# define MSG_ERR_TIME_EAT_SLEEP "ERROR: time_to_die TOO SHORT VS. (time_to_eat + time_to_sleep)\n"
/* ************************************************************************** */
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_philo t_philo;
/* -------------------------------------------------------------------------- */
typedef struct s_data
{
	int				max_philo;
	int				time_die;	 	// milliseconde
	int				time_eat;	 	// milliseconde
	int				time_sleep; 	// milliseconde
	int				max_eat;		// OPTIONAL
	// ------------------------------
	pthread_t		*thr_id_list;
	pthread_mutex_t	*mtx_fork_list;
	pthread_mutex_t	someone_is_dead;

	// ------------------------------
} t_data;
/* -------------------------------------------------------------------------- */
typedef struct s_philo
{

} t_philo;
/* ************************************************************************** */
void	init_basic_data(t_data *d);
int		check_game_data(t_data *d);
int		save_game_data(int argc, char **argv, t_data *d);

int		clean_game_data(t_data *d);
/* -------------------------------------------------------- */
int		print_error(int type_error);
bool	is_countable(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_msleep(int millisecond);
/* -------------------------------------------------------- */

/* ************************************************************************** */
#endif