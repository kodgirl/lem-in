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
	free(curr_edge);
}

static void 		free_rooms(t_room *room)
{
	t_room	*curr;
	t_room	*tmp;

	curr = room;
	while (curr)
	{
		tmp = curr;
		free(tmp->name);
		free_edges(tmp);
		curr = curr->next;
		free(tmp);
	}
}

static void 		free_way(t_way *way, t_room **room, int len)
{
	t_way		*tmp;

	while (way != NULL)
	{
		tmp = way;
		way = way->next;
		free(tmp);
	}
	while (len >= 0)
	{
		if (room[len])
			free(room[len]);
		len--;
	}
	free(room);
}

void		free_lem_in2(t_struct *all, t_ways *wayS)
{
	t_ways	*tmp;

	free_rooms(all->room);
	while (wayS != NULL)
	{
		free_way(wayS->way, wayS->way_in_arr, wayS->rm_qn - 1);
		tmp = wayS;
		wayS = wayS->next;
		free(tmp);
	}
}