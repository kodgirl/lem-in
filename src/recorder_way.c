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
    t_way   *fix;
    fix = way;
    while (fix) {
        fix->room->visit = -1;
        fix = fix->next;
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

t_way    *record_way(t_struct *all)
{
    t_way   *HeadWay;
    t_way   *way;
    t_room  *room;
    t_room  *tmp;

    way = (t_way *)malloc(sizeof(t_way));

    HeadWay = way;
    room = all->end;
    while(room != NULL)
    {
        way->room = room;
        if (room == all->start) {
            way->next = NULL;
            break;
        }
        way->next = malloc(sizeof(t_way));
        tmp = room;
        way = way->next;
        way->next->room = tmp;
        room = room->go_from;
    }
    way = HeadWay;
    room = way->room;

    way = invert_way(way);
    way = FixVisitRooms(way);
//    return (way);
    printf("\nRecorder way\n");
    while (way)
    {
        printf("%s--->", way->room->name);
        way = way->next;
    }
    printf("\n");
}
