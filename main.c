
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int main(int argc, char **argv)
{
	t_data d;

	init_basic_data(&d);

	if (argc - 1 < 4 || argc - 1 > 5)
		return (print_error(TYPE_ERR_ARG));

	if(save_game_data(argc, argv, &d) == ERROR)
		return (print_error(TYPE_ERR_CNT));

	if (check_game_data(&d) == ERROR)
		return (ERROR);

	// add game data


	// start thread for philosopher

	// exit if someone dead

	// clean data (free)

	clean_game_data(&d);
	return (NO_ERROR);
}