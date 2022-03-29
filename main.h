

/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define TYPE_ERR_ARG	0
# define TYPE_ERR_CNT	1
/* -------------------------------------------------------- */
# define MSG_ERR_ARG	"ERROR: number of argument\n"
# define MSG_ERR_CNT	"ERROR: argument NOT COUNTABLE\n"
/* ************************************************************************** */
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
/* ************************************************************************** */
typedef struct s_data
{
	int max_philo;
	int time_die;	 	// milliseconde
	int time_eat;	 	// milliseconde
	int time_sleep; 	// milliseconde
	int max_eat;		// OPTIONAL
	// ------------------------------
} t_data;
/* ************************************************************************** */
int		save_game_data(int argc, char **argv, t_data *d);
/* -------------------------------------------------------- */

int		print_error(int type_error);
bool	is_countable(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
/* -------------------------------------------------------- */

/* ************************************************************************** */
#endif