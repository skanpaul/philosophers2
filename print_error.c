/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:53:42 by ski               #+#    #+#             */
/*   Updated: 2022/04/01 08:53:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	print_error(t_error type_error)
{
	if (type_error == TYPE_ERR_ARG)
		printf(MSG_ERR_ARG);
	else if (type_error == TYPE_ERR_CNT)
		printf(MSG_ERR_CNT);
	else if (type_error == TYPE_ERR_MALLOC_PHILO)
		printf(MSG_ERR_MALLOC_PHILO);
	else if (type_error == TYPE_ERR_MALLOC_THREAD)
		printf(MSG_ERR_MALLOC_THREAD);
	else if (type_error == TYPE_ERR_MALLOC_MUTEX)
		printf(MSG_ERR_MALLOC_MUTEX);
	else if (type_error == TYPE_ERR_MAX_PHILO)
		printf(MSG_ERR_MAX_PHILO);
	else if (type_error == TYPE_ERR_TIME_NEGATIVE)
		printf(MSG_ERR_TIME_NEGATIVE);
	else if (type_error == TYPE_ERR_MAX_EAT)
		printf(MSG_ERR_MAX_EAT);
	else if (type_error == TYPE_ERR_MTX_INIT)
		printf(MSG_ERR_MTX_INIT);
	else if (type_error == TYPE_ERR_THD_CREATE)
		printf(MSG_ERR_THD_CREATE);
	return (ERROR);
}

/* ************************************************************************** */
