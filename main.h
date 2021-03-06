/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:55:56 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:55:58 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# define INFO			0
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define DEAD			0
# define ALIVE			1
/* ************************************************************************** */
# define EAT_NOT_ENOUGH_TIME	0
# define EAT_ENOUGH_TIME		1
/* ************************************************************************** */
# define SHOULD_NOT_RETURN	0
# define SHOULD_RETURN		1
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
typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef enum e_error	t_error;
typedef struct timeval	t_timeval;
/* ************************************************************************** */
typedef struct s_data
{
	int				max_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				max_eat;
	bool			should_count_meal;
	int				time_us_die;
	int				time_us_eat;
	int				time_us_sleep;
	int				time_us_think;
	pthread_mutex_t	mtx_someone_dead;
	bool			someone_dead;
	t_philo			*philo_list;
	pthread_t		thd_check_life;
	pthread_mutex_t	*mtx_fork_list;
	pthread_mutex_t	mtx_finish_main;
	pthread_mutex_t	mtx_message;
	int				operation;

}	t_data;
/* ************************************************************************** */
typedef struct s_philo
{
	int				id;
	pthread_t		th_id;
	int				pos_f_l;
	int				pos_f_r;
	pthread_mutex_t	*mtx_fork_l;
	pthread_mutex_t	*mtx_fork_r;
	bool			should_count_meal;
	int				n_meal;
	int				max_meal;
	pthread_mutex_t	mtx_eat_enough;
	bool			eat_enough;
	int64_t			stamp_us_start;
	int64_t			stamp_us_fork;
	int64_t			stamp_us_eat;
	int64_t			stamp_us_sleep;
	int64_t			stamp_us_think;
	pthread_mutex_t	mtx_stamp_us_died;
	int64_t			stamp_us_died;
	t_data			*d;
}	t_philo;
/* ************************************************************************** */
typedef enum e_error
{
	TYPE_ERR_ARG,
	TYPE_ERR_CNT,
	TYPE_ERR_MALLOC_PHILO,
	TYPE_ERR_MALLOC_THREAD,
	TYPE_ERR_MALLOC_MUTEX,
	TYPE_ERR_MAX_PHILO,
	TYPE_ERR_TIME_NEGATIVE,
	TYPE_ERR_MAX_EAT,
	TYPE_ERR_MTX_INIT,
	TYPE_ERR_THD_CREATE
}	t_error;
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
int64_t	get_stamp_us_now(void);
void	set_all_stamp_us_mutex(t_philo *p);
bool	is_action_finished(uint64_t stamp_us_next_activity);
/* -------------------------------------------------------- */
void	print_mutex(t_philo *p, int64_t stamp_us, char *msg);
void	print_fork(t_philo *p);
void	print_eat(t_philo *p);
void	print_sleep(t_philo *p);
void	print_think(t_philo *p);
void	print_died(t_philo *p);
/* ------------------------------- */
void	print_max_meal(t_philo *p);

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
int		philo_start_to_sleep(t_philo *p);
int		philo_start_to_think(t_philo *p);
// ---------------------------------------
int		philo_count_meal(t_philo *p);
/* ************************************************************************** */
/* **************************< THREAD: check_end >*************************** */
/* ************************************************************************** */
void	*check_end(void *arg);
/* -------------------------------------------------------- */
bool	is_this_philo_dead(t_philo *p);
bool	is_someone_dead_mutex(t_data *d);

/* ************************************************************************** */
#endif
