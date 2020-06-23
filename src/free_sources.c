#include "../includes/lem_in.h"

static void 			free_edges(t_room *room)
{
	t_edge	*curr_edge;
	t_edge 	*tmp;

	curr_edge = room->edge;
	while (curr_edge)
	{
		tmp = curr_edge;
		curr_edge = curr_edge->next;
		free(tmp);
	}
}

static void 		free_rooms(t_room *room)
{
	t_room	*curr;
	t_room	*tmp;

	curr = room;
	while (curr)
	{
		free(curr->name);
		if (curr->go_from)
			free(curr->go_from);
		free_edges(curr);
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

// TODO Free 1.ways in lists and 2.arrays too. And 3.variable ways.

static void 		free_way(t_way *way, t_room **room, unsigned *quan)
{
	t_way	*tmp;
	int 	i;
	t_room *tmp_room;

	i = 0;
	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp);
	}
	free(way);
	while (i < *quan)
	{
		free(room[i]);
		i++;
	}
	free(room);
}

void		free_lem_in2(t_struct *all, t_ways *wayS)
{
	int 	i;
	t_ways	*tmp;

	i = 0;
	while (wayS != NULL)
	{
		free_way(wayS->way, wayS->way_in_arr, &wayS->rm_qn);
		tmp = wayS;
		wayS = wayS->next;
		free(tmp);
	}
	free_rooms(all->room);

}