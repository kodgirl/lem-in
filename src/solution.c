#include "../includes/lem_in.h"
#include <limits.h>

/*
 * Думаю о том, как добавить новый лист в начало списка.
 *
 */

t_way 	*add_room(t_way *way, t_room *room, t_room *end)
{
	t_way *new_list_of_way;
	t_room *tmp;

	if (room == end)
	{
		if (!(new_list_of_way = (t_way *)ft_memalloc(sizeof(t_way))))
			return (NULL);
		new_list_of_way->room = room;
		new_list_of_way->next = NULL;
	}
	else
	{
		if (!(new_list_of_way = (t_way *)ft_memalloc(sizeof(t_way))))
			return (NULL);
		new_list_of_way->room = room;
		new_list_of_way->next = way;
	}
	return (new_list_of_way);
}
/*
 * Почему не добавляет новую комнату в список?
 * Хочу добавить комнату в список, он присваивает, но не добавляет.
 */
t_way	*record(t_struct *all)
{
	t_room 	*room;
	t_way 	*new_way;

	room = all->end;
	while (room)
	{
		new_way = add_room(new_way, room, all->end);
		if (room == all->start)
			break;
		room = room->go_from;
	}
	if (!new_way)
		return (NULL);
	return (new_way);
}

/*
 * bfs работает один раз.
 */

void 	*solution(t_struct *all)
{
	t_ways	*wayS;
	t_ways	*head_wayS;
	int 	i;

	i = all->rm_count;
	wayS = (t_ways *)malloc(sizeof(t_ways));
	while (bfs(all))
	{
		wayS->way = record(all);
		if (!(wayS->next = (t_ways *)ft_memalloc(sizeof(t_ways))))
			return (NULL);
		wayS = wayS->next;
		i--;
	}
}