#include "../includes/lem_in.h"

/*
** Article about calculation than to launch new way;
** https://medium.com/@jamierobertdawson/lem-in-finding-all-the-paths-and-deciding-which-are-worth-it-2503dffb893
** At this function taking for expression two ways length - current and next ways;
** Calculating length of next way with current way.
** cWay is current way and nWay is next way.
*/

static void 		calc_ways(t_ways *ways, t_struct *all, int cLen, int nLen)
{
	t_ways 	*cWay;
	t_ways	*nWay;

	cWay = ways;
	nWay = ways->next;
	while (nWay)
	{
		cWay = ways->next;
		cLen = 0;
		nLen = 0;
		while (cWay != nWay)
		{
			cLen += cWay->rm_qn;
			nLen += nWay->rm_qn;
			cWay = cWay->next;
		}
		nWay->calc = nLen - cLen;
		nWay = nWay->next;
	}
}

int 	start_actions(t_struct *all)
{
	t_ways *ways;

	ways = NULL;
	if (ways = record_ways(all, NULL, NULL, NULL))
	{
		calc_ways(ways, all, 0, 0);
		ants_movement(ways, all);
	}
	free_lem_in2(all, ways);
	return (0);

}