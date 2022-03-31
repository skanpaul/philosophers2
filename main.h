

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
# define DEAD			0
# define ALIVE			1
/* ************************************************************************** */
# define TIME_USLEEP	50
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
	int				time_die;	 	// milliseconde
	int				time_eat;	 	// milliseconde
	int				time_sleep; 	// milliseconde
	int				time_think; 	// milliseconde
	int				max_eat;		// OPTIONAL
	int				operation;
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
	// ------------------------------

} t_data;
/* ************************************************************************** */
typedef struct s_philo
{
	int				pos;
	int				id;
	pthread_t		th_id;
	int				pos_f_l; // positon fork left
	int				pos_f_r; // position fork right	
	pthread_mutex_t	*mtx_fork_l;
	pthread_mutex_t	*mtx_fork_r;
	// ------------------------------
	pthread_mutex_t	mtx_timeval;
	// ------------------------------
	t_timeval		tv_start;
	t_timeval		tv_born;
	t_timeval		tv_fork;
	t_timeval		tv_eat;
	t_timeval		tv_sleep;
	t_timeval		tv_think;
	t_timeval		tv_died;
	// ------------------------------
	long int		stamp_start;
	long int		stamp_born;
	long int		stamp_fork;
	long int		stamp_eat;
	long int		stamp_sleep;
	long int		stamp_think;
	long int		stamp_died;
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
void	ft_msleep(int millisecond, int percent);
/* ************************************************************************** */
void	set_1_timeval_mutex(t_timeval *timestamp, t_philo *p);
void	set_all_timeval_mutex(t_philo *p);
int		get_ms_diff(t_timeval *now, t_timeval *ts);
void	add_ms_to_timeval(int add_ms, t_timeval *ts);
bool	is_timeval_greater_or_equal_to(t_timeval *tv_a, t_timeval *tv_b);
bool	is_activity_finished(t_timeval *tv_end, t_philo *p);
/* -------------------------------------------------------- */
long int get_timestamp(t_timeval *tv, t_philo *p);

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

/* -------------------------------------------------------- */
void	print_mutex(t_philo *p, t_timeval *timeval, char *msg);
void	print_born(t_philo *p);
void	print_fork(t_philo *p);
void	print_eat(t_philo *p);
void	print_sleep(t_philo *p);
void	print_think(t_philo *p);
void	print_died(t_philo *p);

/* ************************************************************************** */
/* ************************< THREAD: check_life >**************************** */
/* ************************************************************************** */
void	*check_life(void *arg);
/* -------------------------------------------------------- */
bool	is_this_philo_dead(t_philo *p);
bool	is_someone_dead_mutex(t_data *d);

/* ************************************************************************** */
#endif