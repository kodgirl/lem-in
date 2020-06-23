#include "../includes/lem_in.h"

/*
** Article about calculation than to launch new way;
** https://medium.com/@jamierobertdawson/lem-in-finding-all-the-paths-and-deciding-which-are-worth-it-2503dffb893
*/

static void 		ways_expressions(t_ways *ways, t_struct *all)
{
	int		curr_len;
	int		next_len;
	t_ways 	*curr;
	t_ways	*next_way;

	curr_len = 0;
	next_len = 0;
	curr = ways;
	next_way = ways->next;
	while (next_way)
	{
		curr = ways->next;
		curr_len = 0;
		next_len = 0;
		while (curr != next_way)
		{
			curr_len += curr->rm_qn;
			next_len += next_way->rm_qn;
			curr = curr->next;
		}
		next_way->calc = next_len - curr_len;
		next_way = next_way->next;
	}
}

int 	start_actions(t_struct *all)
{
	t_ways *ways;

	ways = NULL;
	if (ways = record_ways(all, NULL, NULL, NULL))
	{
		ways_expressions(ways, all);
		ants_movement(ways, all);
	}
	free_lem_in2(all, ways);
	return (0);

}