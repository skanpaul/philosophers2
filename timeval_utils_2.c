
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
// ATTENTION
// ATTENTION
// ATTENTION		FAIT BUGUER LE PROGRAMME
// ATTENTION		AUCUN THREAD NE MEURT
// ATTENTION		LE PROGRAMME NE SARRETE JAMAIS
// ATTENTION
/* ************************************************************************** */
int64_t get_timestamp(t_timeval *tv, t_philo *p)
{
	int64_t tv_ms;
	int64_t start_ms;
	int64_t result_ms;

	tv_ms = (tv->tv_sec * 1000) + (tv->tv_usec / 1000);
	start_ms = (p->tv_start.tv_sec * 1000) + (p->tv_start.tv_usec / 1000);

	result_ms = tv_ms - start_ms;

	return ((int64_t)result_ms);
}


/* ************************************************************************** */