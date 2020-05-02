#include "../includes/lem_in.h"

t_way    *invert_way(t_way *way)
{
    t_way   *curr;
    t_way   *next;
    t_way   *prev;
    curr = way;
    prev = NULL;
    next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    way = prev;
    return(way);
}

t_way   *FixVisitRooms(t_way *way)
{
    t_way   *tmpWay;
    t_edge  *tmpEdge;
    t_room  *room;

    tmpWay = way;
    while (tmpWay)
    {
        tmpEdge = tmpWay->room->edge;
        if (tmpWay->next)
        {
            while (tmpEdge)
            {
                if (ft_strcmp(tmpEdge->room->name, tmpWay->next->room->name) == 0)
                {
                    tmpEdge->cost = -1;
                }
                tmpEdge = tmpEdge->next;
            }
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
*/

t_way    *record_way(t_struct *all) {
    t_way *HeadWay;
    t_way *way;
    t_room *room;

    way = (t_way *)malloc(sizeof(t_way));

    HeadWay = way;
    room = all->end;
    while (room != NULL) {
        way->room = room;
        if (room == all->start) {
            way->next = NULL;
            break;
        }
        if (!(way->next = (t_way *)malloc(sizeof(t_way)))) {
            exit(-1);
        }
        way = way->next;
        room = room->go_from;
    }
    way = HeadWay;
    room = way->room;

    way = invert_way(way);
    way = FixVisitRooms(way);
    return (way);
}
