

/* ************************************************************************** */
#ifndef MSG_ERR_H
# define MSG_ERR_H
/* ************************************************************************** */
# define MSG_ERR_ARG	"ERROR: number of argument\n"
# define MSG_ERR_CNT	"ERROR: argument NOT COUNTABLE\n"
# define MSG_ERR_MALLOC_PHILO	"ERROR: malloc PHILO\n"
# define MSG_ERR_MALLOC_THREAD	"ERROR: malloc THREAD\n"
# define MSG_ERR_MALLOC_MUTEX	"ERROR: malloc MUTEX\n"
// ----------------------------------
# define MSG_ERR_MAX_PHILO "ERROR: NOT ENOUGH philospher(s)\n"
# define MSG_ERR_TIME_EAT_SLEEP "ERROR: time_to_die TOO SHORT VS. (time_to_eat + time_to_sleep)\n"
# define MSG_ERR_TIME_NEGATIVE "ERROR: time_to* NEGATIVE\n"
# define MSG_ERR_MAX_EAT "ERROR: meal number SMALLER THAN 1\n"
// ----------------------------------
# define MSG_ERR_MTX_INIT "ERROR: initialization MUTEX\n"
// ----------------------------------
# define MSG_ERR_THD_CREATE "ERROR: creating THREAD\n"
/* ************************************************************************** */
# define MSG_FORK       " has taken a fork\n"
# define MSG_EAT        " is eating\n"
# define MSG_SLEEP      " is sleeping\n"
# define MSG_THINK      " is thinking\n"
# define MSG_DIED       " died\n"

/* ************************************************************************** */
#endif