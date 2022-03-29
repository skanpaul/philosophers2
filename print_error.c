


/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int print_error(int type_error)
{
	if (type_error == TYPE_ERR_ARG)         printf(MSG_ERR_ARG);

	else if (type_error == TYPE_ERR_CNT)    printf(MSG_ERR_CNT);
	
	return (ERROR);
}

/* ************************************************************************** */