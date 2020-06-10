#include "../includes/lem_in.h"

int 	start_actions(t_struct *all)
{
	t_ways *ways;

	ways = NULL;
	if (ways = record_ways(all))
	{
		ways_expressions(ways, all);
		ants_movement(ways, all);
	}
	return (0);

}