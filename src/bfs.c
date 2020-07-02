/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <dpenney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:19:42 by dpenney           #+#    #+#             */
/*   Updated: 2020/06/26 12:19:44 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Function of free orders lists.
*/

t_order			*allocate_orders_list(t_room *start_room)
{
	t_order		*new_orders_list;

	if (!(new_orders_list = (t_order *)ft_memalloc(sizeof(t_order))))
		return (NULL);
	ft_bzero(new_orders_list, sizeof(t_order));
	new_orders_list->room = start_room;
	return (new_orders_list);
}

/*
** allocating memory to new list of order and
** put new room to the orders list.
** After it - adding new list by the end of orders
** lists.
*/

void			add_room(t_order *order, t_room *new_room)
{
	t_order *orders_runner;
	t_order *new_orders_list;

	orders_runner = order;
	new_orders_list = allocate_orders_list(new_room);
	while (orders_runner->next)
		orders_runner = orders_runner->next;
	orders_runner->next = new_orders_list;
}

/*
** Checking - if next rooms is finish room, function
** marking in go_from pointer of room where did it come from and marking
** like visited room and returning one than to break
** process of reading edges and reading next room.
** If it's not finish room, function checking next terms:
** 1. this edge did not use early AND
** 2. Rooms of the edge don't visited. AND
** 3. This room don't include to the other saved way.
** If all terms are true, function adding this room to
** order, marking in go_from in pointer where did it come
** from and marking this room like visited than don't
** add in future. Returning zero than to continue read edges.
*/

int				read_edges_room(t_edge *edge, t_order *order, t_struct *all)
{
	t_room	*next_room;
	t_edge	*edges_runner;

	edges_runner = edge;
	next_room = edges_runner->room;
	if (next_room == all->end && !next_room->visit)
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

/*
** Allocationg memory for order and put to order start room.
** Marking start room like visited than later don't add to
** order.
** Launching cycle of orders contains rooms.
** If current room in order is finish room - breaking process,
** because way found.
** Next step is reading edges of current room and adding edges
** rooms to order if this edge did not used in past.
*/

int				bfs(t_struct *all, t_order *order, t_order *clean_order)
{
	t_edge	*read_edges;

	order = allocate_orders_list(all->start);
	order->room->visit = 1;
	clean_order = order;
	while (order)
	{
		if (order->room == all->end)
			break ;
		read_edges = order->room->edge;
		while (read_edges)
		{
			if (!read_edges->cost)
			{
				if (read_edges_room(read_edges, order, all))
					break ;
			}
			read_edges = read_edges->next;
		}
		order = order->next;
	}
	free_order(clean_order);
	if (all->end->go_from)
		return (1);
	return (0);
}
