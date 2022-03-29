




/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int main(int argc, char **argv)
{
	t_data d;

	if (argc < 5 || argc > 6)
		return (print_error(TYPE_ERR_ARG));

	if(save_game_data(argc, argv, &d) == ERROR)
		return (print_error(TYPE_ERR_CNT));

	// create thread_id philosopert
	// create mutex forks
	// create mutex someone_dead


	// start thread for philosopher

	// exit if someone dead


	return (NO_ERROR);
}