#include "../includes/lem_in.h"
#include <limits.h>

void 	push_room(t_edge *currentEdge, t_order *order, t_struct *all)
{
	t_room *read_rooms;

	read_rooms = currentEdge->room;
	if (read_rooms->)
}

int 	bfs(t_struct *all)
{
	t_room	*runner_rm;
	t_order *order;
	t_order *orders_head;
	t_edge	*runner_ed;

	order = ft_memalloc(sizeof(t_order));
	order->room = all->start;
	orders_head = order;
	order->room->visit = 1;
	while (order)
	{
		if (order->room == all->end)
			break;
		runner_ed = order->room;
		while (runner_ed)
		{
			if (runner_ed->cost == 1)
				runner_ed = runner_ed->next;
			else
				push_room(runner_ed, order, all);
		}
	}
}