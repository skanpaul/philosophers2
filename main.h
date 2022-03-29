

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
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
/* -------------------- */
# include "message.h"
/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_philo t_philo;
typedef enum e_error t_error;
/* -------------------------------------------------------------------------- */
typedef struct s_data
{
	int				max_philo;
	int				time_die;	 	// milliseconde
	int				time_eat;	 	// milliseconde
	int				time_sleep; 	// milliseconde
	int				max_eat;		// OPTIONAL
	// ------------------------------
	t_philo			*philo_list;
	pthread_t		*thread_list;
	pthread_t		thd_check_life;
	pthread_mutex_t	*mtx_fork_list;
	pthread_mutex_t	mtx_one_is_dead;
	pthread_mutex_t	mtx_message;
	// ------------------------------

} t_data;
/* ************************************************************************** */
typedef struct s_philo
{
	int				pos;
	int				id;
	int				pos_f_l; // positon fork left
	int				pos_f_r; // position fork right	
	bool			dead;
	// ------------------------------
	int				ts_fork;
	int				ts_eat;
	int				ts_sleep;
	int				ts_think;
	int				ts_died;
	// ------------------------------
	t_data			*d;
	pthread_t		*th_id;
	// ------------------------------
} t_philo;
/* ************************************************************************** */
typedef enum e_error
{
	// ----------------------------------
	TYPE_ERR_ARG,
	TYPE_ERR_CNT,
	TYPE_ERR_MALLOC_PHILO,
	TYPE_ERR_MALLOC_THREAD,
	TYPE_ERR_MALLOC_MUTEX,
	// ----------------------------------
	TYPE_ERR_MAX_PHILO,
	TYPE_ERR_TIME_NEGATIVE,
	TYPE_ERR_TIME_EAT_SLEEP,
	TYPE_ERR_MAX_EAT,
	// ----------------------------------
	TYPE_ERR_MTX_INIT,
	// ----------------------------------
	TYPE_ERR_THD_CREATE
	// ----------------------------------
} t_error;
/* ************************************************************************** */
void	init_basic_data(t_data *d);
int		check_game_data(t_data *d, int argc);
int		save_game_data(int argc, char **argv, t_data *d);
/* -------------------------------------------------------- */
int		malloc_philos_and_forks_and_thread(t_data *d);
void	init_philo_struct(t_philo *p, t_data *d);
int		init_all_mutex(t_data *d);
/* -------------------------------------------------------- */
int		start_thread(t_data *d);
/* -------------------------------------------------------- */
int		clean_game(t_data *d);
void	destroy_all_mutex(t_data *d);
int		free_all_malloc(t_data *d);
/* -------------------------------------------------------- */
int		print_error(t_error type_error);
bool	is_countable(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_msleep(int millisecond);

/* ********************************< THREAD >******************************** */
void	*philo_activity(void *arg);
void	*check_life(void *arg);
/* -------------------------------------------------------- */
void	take_forks(t_philo *p);
void	give_forks_back(t_philo *p);
/* -------------------------------------------------------- */
void	print_mutex(t_philo *p, int timestamp, char *msg);
void	print_fork(t_philo *p);
void	print_eat(t_philo *p);
void	print_sleep(t_philo *p);
void	print_think(t_philo *p);
void	print_died(t_philo *p);

/* ************************************************************************** */
#endif