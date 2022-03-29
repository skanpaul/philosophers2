


/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int print_error(int type_error)
{
	if (type_error == TYPE_ERR_ARG)         printf(MSG_ERR_ARG);
	else if (type_error == TYPE_ERR_CNT)    printf(MSG_ERR_CNT);	
	else if (type_error == TYPE_ERR_MALLOC_THREAD)    printf(MSG_ERR_MALLOC_THREAD);
	else if (type_error == TYPE_ERR_MALLOC_MUTEX)    printf(MSG_ERR_MALLOC_MUTEX);
	// ----------------------------------
	else if (type_error == TYPE_ERR_MAX_PHILO)	printf(MSG_ERR_MAX_PHILO);
	else if (type_error == TYPE_ERR_TIME_EAT_SLEEP)	printf(MSG_ERR_TIME_EAT_SLEEP);
	// ----------------------------------

	if (ERRORING == 1)
		return (ERROR);
	else
		return (NO_ERROR);
}

/* ************************************************************************** */