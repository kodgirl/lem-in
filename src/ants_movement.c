#include "../includes/lem_in.h"

/*
 * Goal of function is to implement expression of the decision
 * put next ant to new memory or no.
 * Therefore program expressing values to every way.
 * If count of ants > than (count of the way - count of the last room)
 * program add new ant to new way. Else spend all ants via one way.
 * https://medium.com/@jamierobertdawson/lem-in-finding-all-the-paths-and-deciding-which-are-worth-it-2503dffb893
 * Up link is about expression in details.
 */

void 		ways_expressions(t_ways *ways, t_struct *all)
{
	int 	k;
	int		i;
	t_ways	*read_ways;

	read_ways = ways;
	k = 0;
	i = 0;
	while (read_ways)
	{
		if (!read_ways->next)
			break;
		k += read_ways->rm_qn;
		if (i != 0)
			read_ways->next->expression = (read_ways->next->rm_qn * 2) - k;
		else
			read_ways->next->expression = read_ways->next->rm_qn - k;
		read_ways = read_ways->next;
		i++;
	}
}

void		ants_movement(t_ways *ways, t_struct *all)
{
	ways_expressions(ways, all);

}
