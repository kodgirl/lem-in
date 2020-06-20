#include "../includes/lem_in.h"

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

t_way 	*add_room_to_way(t_room *room, t_way *new_way, t_struct *all)
{
	t_way *new_list_of_way;

	if (!(new_list_of_way = (t_way *)ft_memalloc(sizeof(t_way))))
		return (NULL);
	new_list_of_way->room = room;
	if (room != all->end)
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
		new_way = add_room_to_way(room_runner, new_way, all);
		room_runner = room_runner->go_from;
	}
	return (new_way);
}

void 		free_void_list(t_ways *all_ways)
{
	t_ways *runner;
	t_ways *tmp;

	runner = all_ways;
	while (runner)
	{
		if (runner->way == NULL)
		{
			free(runner);
			tmp->next = NULL;
			break;
		}
		tmp = runner;
		runner = runner->next;
	}
}


/*
 * TODO Free found ways in lists
 */

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
		all_ways->rm_qn = calc_rooms_in_way(way);
		all_ways->way = way;
		all_ways->way_in_arr = record_to_array(way, all_ways->rm_qn);
		print_way(all_ways->way_in_arr);
		all_ways->next = (t_ways *)ft_memalloc(sizeof(t_ways));
		all_ways = all_ways->next;
		preparing_to_bfs(all, way);
	}
	free_void_list(head_of_ways);
	if (head_of_ways->rm_qn)
		return(head_of_ways);
	else
	{
		all->error = ERROR_WAYS_NOT_FOUND
//		ft_printf("ERROR: Ways not found.");
//		exit(-1);
	}
}