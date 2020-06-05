#include "../includes/lem_in.h"

/*
 * Разворачиваю лист с комнатами.
 */

t_way    *invert_way(t_way *way, t_way *curr, t_way *next, t_way *prev)
{
    curr = way;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    way = prev;
	way = mark_used_edges(way, NULL, NULL, NULL);
	return(way);
}

/*
 * Прохожусь по рёбрам и те рёбра, которые объединяют найденный путь - ставлю -1,
 * чтобы по ним больше не проходились.
 */

t_way   *mark_used_edges(t_way *way, t_way *tmpWay, t_edge *tmpEdge, t_room *room)
{
    tmpWay = way;
    while (tmpWay)
    {
        tmpEdge = tmpWay->room->edge;
        if (tmpWay->next)
            while (tmpEdge)
            {
                if (ft_strcmp(tmpEdge->room->name, tmpWay->next->room->name) == 0)
                    tmpEdge->cost = -1;
                tmpEdge = tmpEdge->next;
            }
        tmpWay = tmpWay->next;
    }
    return (way);
}

/*
** Allocating memory for save way;
** Via last room checking go_from
**and found way from end to start;
** Because found  way which end by start
** we're inverting way via invert_way;
** And after it marking all rooms of the way.
 *
*/

t_way    *record_way(t_struct *all, t_way *HeadWay, t_way *way, t_room *room)
{
    way = (t_way *)malloc(sizeof(t_way));
    HeadWay = way;
    room = all->end;
	t_way *tmp_way;

	while (room != NULL)
	{
		way->room = room;
		if (room == all->start) {
			way->next = NULL;
			break;
		}
		if (!(way->next = (t_way *)malloc(sizeof(t_way)))) {
			exit(-1);
		}
		room->in_way = 1;
		way = way->next;
		room = room->go_from;
	}
    way = HeadWay;
    room = way->room;
    way = invert_way(way, NULL, NULL, NULL);
    return (way);
}
