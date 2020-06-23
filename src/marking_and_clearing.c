#include "../includes/lem_in.h"

void 	annual_rooms_vars(t_struct *all)
{
	t_room *rooms;

	rooms = all->room;
	while (rooms)
	{
		rooms->visit = 0;
		rooms = rooms->next;
	}
}

/*
 * Function gets new detected way and
 * laucnhing cycle. At fisrt gets pointers to first and next room of
 * this way. Next step is reading edges of first room and looking for
 * next room in edges of first room via comparing names.
 * If next room found in edges of first room - marking this edge like
 * used in variable cost of edges.
 * After it - taking next rooms of the way till a finish room.
 */

void 	mark_used_edges(t_struct *all, t_way *way)
{
	t_way *ways_runner;
	t_edge	*read_edges;
	t_room	*first_rm;
	t_room 	*next_rm;

	ways_runner = way;
	while (ways_runner && ways_runner->next)
	{
		first_rm = ways_runner->room;
		next_rm = ways_runner->next->room;
		read_edges = first_rm->edge;
		while (read_edges)
		{
			if (!ft_strcmp(read_edges->room->name, next_rm->name))
			{
				next_rm->in_way = 1;
				read_edges->cost = 1;
				next_rm->go_from = NULL;
				break;
			}
			read_edges = read_edges->next;
		}
		ways_runner = ways_runner->next;
	}
}

void	preparing_to_bfs(t_struct *all, t_way *way)
{
	annual_rooms_vars(all);
	mark_used_edges(all, way);
}

void free_order(t_order *clean_order)
{
	t_order *tmp;
	while (clean_order)
	{
		tmp = clean_order;
		clean_order = clean_order->next;
		free(tmp);
	}
}