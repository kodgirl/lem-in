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
		free(curr->name);
		free_edges(curr);
		tmp = curr;
		curr = curr->next;
	}
}

static void 		free_way(t_way *way, t_room **room, unsigned quan)
{
	t_way	*tmp;
	int 	i;

	i = 0;
	while (way != NULL)
	{
		tmp = way;
		way = way->next;
		free(tmp);
	}
	while (i <= quan)
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
	free_rooms(all->room);
	while (wayS != NULL)
	{
		free_way(wayS->way, wayS->way_in_arr, wayS->rm_qn - 1);
		tmp = wayS;
		wayS = wayS->next;
		free(tmp);
	}
}