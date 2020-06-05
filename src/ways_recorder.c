#include "../includes/lem_in.h"

void 	mark_used_rooms(t_struct *all, t_way *way)
{

}

void 	mark_used_edges(t_struct *all, t_way *way)
{
	t_way *ways_runner;
	t_edge	*edges_runner;

	ways_runner = way;
	while (ways_runner)
	{
		edges_runner = ways_runner->room->edge;
	}
}

void	preparing_to_bfs(t_struct *all, t_way *way)
{
	annual_rooms_vars(all);
	mark_used_edges(all, way);
	mark_used_rooms(all, way);
}

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

int 	calc_rooms_in_way(t_way *way)
{
	t_way *runner;
	int counter;

	counter = 0;
	runner = way;
	while (runner)
	{
		counter++;
		runner = runner->next;
	}
	return (counter);
}

t_way 	*add_room_to_way(t_room *room, t_way *new_way)
{
	t_way *new_list_of_way;

	if (!(new_list_of_way = (t_way *)ft_memalloc(sizeof(t_way))))
		return (NULL);
	new_list_of_way->room = room;
	new_list_of_way->next = new_way;
	new_way = new_list_of_way;
	return (new_way);
}

t_way	*processing_way(t_struct *all, t_room *last_room, t_way *new_way)
{
	t_room *room_runner;

	if(!(new_way = (t_way *)ft_memalloc(sizeof(t_way))))
		return (NULL);
	room_runner = last_room;
	while (room_runner)
	{
		new_way = add_room_to_way(room_runner, new_way);
		room_runner = room_runner->go_from;
	}
	return (new_way);
}

t_ways 	*record_ways(t_struct *all)
{
	t_ways	*all_ways;
	t_ways	*clean_all_ways;
	t_way	*way;
	t_ways	*head_of_ways;

	if(!(all_ways = (t_ways *)ft_memalloc(sizeof(t_ways))))
		return (NULL);
	head_of_ways = all_ways;
	annual_rooms_vars(all);
	while (bfs(all))
	{
		way = processing_way(all, all->end, NULL);
		all_ways->way = way;
		all_ways->rm_qn = calc_rooms_in_way(way);
		all_ways->next = (t_ways *)ft_memalloc(sizeof(t_ways));
		all_ways = all_ways->next;
		preparing_to_bfs(all, way);
	}
	return(all_ways);
}