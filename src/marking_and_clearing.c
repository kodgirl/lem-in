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

static void 	mark_used_edges(t_struct *all, t_way *way, t_way *w_read, t_edge *edge_read)
{
	t_room	*first_rm;
	t_room 	*next_rm;

	w_read = way;
	while (w_read && w_read->next)
	{
		first_rm = w_read->room;
		next_rm = w_read->next->room;
		edge_read = first_rm->edge;
		while (edge_read)
		{
			if (!ft_strcmp(edge_read->room->name, next_rm->name))
			{
				next_rm->in_way = 1;
				edge_read->cost = 1;
				next_rm->go_from = NULL;
				break;
			}
			edge_read = edge_read->next;
		}
		w_read = w_read->next;
	}
}

void	preparing_to_bfs(t_struct *all, t_way *way)
{
	annual_rooms_vars(all);
	mark_used_edges(all, way, NULL, NULL);
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