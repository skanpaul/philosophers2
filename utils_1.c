/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int	ft_isspace(int c);

/* ************************************************************************** */
int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		value;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	value = 0;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	value *= sign;
	return (value);
}

/* ************************************************************************** */
static int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
}

/* ************************************************************************** */
bool	is_countable(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	if (!ft_isdigit(str[i]))
		return (false);
	while ((str[i] != '\0') && (ft_isdigit(str[i])))
		i++;
	if (str[i] == '\0')
		return (true);
	if (!ft_isdigit(str[i]))
		return (false);
	return (true);
}

/* ************************************************************************** */
int	ft_isdigit(int c)
{
	if (('0' <= c) & (c <= '9'))
		return (1);
	return (0);
}
/* ************************************************************************** */
void ft_msleep(int millisecond)
{
	if (millisecond < 0)
		millisecond = 0;

	usleep(millisecond * 1000);
}
/* ************************************************************************** */

/* ************************************************************************** */