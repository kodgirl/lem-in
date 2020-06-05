#include "../includes/lem_in.h"

void free_orders_rooms(t_order *clean_order)
{
	t_order *tmp;
	while (clean_order)
	{
		tmp = clean_order;
		clean_order = clean_order->next;
		free(tmp);
	}
}

t_order *allocate_orders_list(t_room *start_room)
{
	t_order 	*new_orders_list;

	if (!(new_orders_list = (t_order *)ft_memalloc(sizeof(t_order))))
		return (NULL);
	ft_bzero(new_orders_list, sizeof(t_order));
	new_orders_list->room = start_room;
	return (new_orders_list);
}

void 	add_room(t_order *order, t_room *new_room)
{
	t_order *orders_runner;
	t_order *new_orders_list;

	orders_runner = order;
	new_orders_list = allocate_orders_list(new_room);
	while (orders_runner->next)
		orders_runner = orders_runner->next;
	orders_runner->next = new_orders_list;
}

int 	read_edges_room(t_edge *edge, t_order *order, t_struct *all)
{
	t_room *next_room;
	t_edge *edges_runner;

	edges_runner = edge;
	next_room = edges_runner->room;
	if (next_room == all->end)
	{
		next_room->go_from = order->room;
		next_room->visit = 1;
		return (1);
	}
	if (!edges_runner->cost && !next_room->visit && !next_room->in_way)
	{
		add_room(order, next_room);
		next_room->go_from = order->room;
		next_room->visit = 1;
	}
	return (0);
}

int 	bfs(t_struct *all)
{
	t_order *order;
	t_order *clean_order;
	t_edge	*read_edges;

	order = allocate_orders_list(all->start);
	order->room->visit = 1;
	clean_order = order;
	while (order)
	{
		if (order->room == all->end)
			break;
		read_edges = order->room->edge;
		while (read_edges)
		{
			if (read_edges->cost == 1)
				read_edges = read_edges->next;
			if (read_edges_room(read_edges, order, all))
				break;
			read_edges = read_edges->next;
		}
		order = order->next;
	}
	free_orders_rooms(clean_order);
	return (1);
}

