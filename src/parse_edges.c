/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:52:35 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 20:58:16 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** In cycle finding necessary room and returning
** address;
*/

t_room		*search_room_name(char *name, t_struct *all)
{
	t_room *tmp;

	tmp = all->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	if (!all->error)
		all->error = ERROR_INVALID_LINKS;
	return (NULL);
}

/*
** Allocating memory for edge and annual
** variables in edge structure.
*/

t_edge		*malloc_edge(void)
{
	t_edge	*edge;

	if ((edge = (t_edge *)malloc(sizeof(t_edge))))
	{
		ft_bzero(edge, sizeof(t_edge));
		return (edge);
	}
	return (NULL);
}

/*
** Add allocated edges to structures of room.
** Vertex could have more edges. Therefore,
** We adding new edge by end of edges of this room.
** But if found the same edge - returning signal of error;
*/

int			add_edge_to_room(t_room *room, t_edge *new_edge)
{
	t_edge *edge_runner;

	edge_runner = room->edge;
	if (!room->edge)
	{
		room->edge = new_edge;
		return (1);
	}
	while (edge_runner)
	{
		if (edge_runner->room == new_edge->room)
			return (0);
		edge_runner = edge_runner->next;
	}
	new_edge->next = room->edge;
	room->edge = new_edge;
	return (1);
}

/*
** rooms1 and rooms2 - rooms than to create edge between them.
** Find two vertex names in our list [0] and [1];
** edg1 and edg2 are for create edge without orientations.
** If rooms found - allocating memory for edge of room1 to room2
** and vice versa;
** Adding edges to structure of room. That's all.
** TODO рассортировать функцию ниже.
*/

int			read_link(t_struct *all, char **split, t_room *room1, t_room *room2)
{
	t_edge	*edg1;
	t_edge	*edg2;

	if (all->end_flag != 1 || all->start_flag != 1)
	{
		if (!all->error)
		{
			all->error = 3;
		}
		return (0);
	}
	all->link_flag = 1;
	room1 = search_room_name(split[0], all);
	room2 = search_room_name(split[1], all);
	if (room1 && room2)
	{
		edg1 = malloc_edge();
		edg2 = malloc_edge();
		edg1->room = room2;
		edg2->room = room1;
		if (add_edge_to_room(room1, edg1) == 0)
			if (!all->error)
			{
				all->error = 3;
				free(edg1);
				free(edg2);
				return (0);
			}
		if (add_edge_to_room(room2, edg2) == 0)
			if (!all->error)
			{
				all->error = 3;
				free(edg2);
				free(edg1);
				return (0);
			}
		edg1->cost = 0;
		edg2->cost = 0;
		return (1);
	}
	else
		return (0);
}
