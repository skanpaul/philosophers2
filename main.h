

/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# define INFO			1
# define ERRORING		1
# define CHECK_GAME		0
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define DEAD			0
# define ALIVE			1
/* ************************************************************************** */
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
/* -------------------- */
# include "message.h"
/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_philo t_philo;
typedef enum e_error t_error;
typedef struct timeval t_timeval;
/* ************************************************************************** */
typedef struct s_data
{
	int				max_philo;
	int				time_die;	 	// milli-seconde
	int				time_eat;	 	// milli-seconde
	int				time_sleep; 	// milli-seconde
	int				time_think; 	// milli-seconde
	int				max_eat;		// OPTIONAL
	// ------------------------------
	bool			should_count_meal;
	// ------------------------------
	int				time_us_die;	// micro-seconde
	int				time_us_eat;	// micro-seconde
	int				time_us_sleep; 	// micro-seconde
	int				time_us_think; 	// micro-seconde
	// ------------------------------
	pthread_mutex_t	mtx_someone_dead;
	bool			someone_dead;
	// ------------------------------
	t_philo			*philo_list;
	pthread_t		thd_check_life;
	pthread_mutex_t	*mtx_fork_list;
	// ------------------------------
	pthread_mutex_t	mtx_finish_main;
	pthread_mutex_t	mtx_message;
	int				operation;
	// ------------------------------

} t_data;
/* ************************************************************************** */
typedef struct s_philo
{
	int				id;
	pthread_t		th_id;
	int				pos_f_l; // positon fork left
	int				pos_f_r; // position fork right	
	pthread_mutex_t	*mtx_fork_l;
	pthread_mutex_t	*mtx_fork_r;
	// ------------------------------
	bool			should_count_meal;
	int				n_meal;
	int				max_meal;
	// ------------------------------
	int64_t			stamp_us_start;
	int64_t			stamp_us_fork;
	int64_t			stamp_us_eat;
	int64_t			stamp_us_sleep;
	int64_t			stamp_us_think;
	pthread_mutex_t	mtx_stamp_us_died;
	int64_t			stamp_us_died;
	// ------------------------------
	t_data			*d;
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
/* -------------------------------------------------------- */
int64_t	conv_stamp_us_from_tv(t_timeval *tv);
int64_t	get_stamp_us_now();
void	set_all_stamp_us_mutex(t_philo *p);
bool	is_action_finished(uint64_t stamp_us_next_activity);
/* -------------------------------------------------------- */
void	print_mutex(t_philo *p, int64_t stamp_us, char *msg);
void	print_fork(t_philo *p);
void	print_eat(t_philo *p);
void	print_sleep(t_philo *p);
void	print_think(t_philo *p);
void	print_died(t_philo *p);

/* ************************************************************************** */
/* *********************< THREAD: philo_activity >*************************** */
/* ************************************************************************** */
void	*philo_activity(void *arg);
/* -------------------------------------------------------- */
int		philo_take_forks_left(t_philo *p);
int		philo_take_forks_right(t_philo *p);
void	philo_give_forks_back(t_philo *p);
// ---------------------------------------
int		philo_start_to_eat(t_philo *p);
int 	philo_start_to_sleep(t_philo *p);
int		philo_start_to_think(t_philo *p);

/* ************************************************************************** */
/* ************************< THREAD: check_life >**************************** */
/* ************************************************************************** */
void	*check_life(void *arg);
/* -------------------------------------------------------- */
bool	is_this_philo_dead(t_philo *p);
bool	is_someone_dead_mutex(t_data *d);

/* ************************************************************************** */
#endif