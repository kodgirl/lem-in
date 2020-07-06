/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sources.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <dpenney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:19:50 by dpenney           #+#    #+#             */
/*   Updated: 2020/06/26 12:19:52 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			free_edges(t_room *room)
{
	t_edge			*curr_edge;
	t_edge			*tmp;

	curr_edge = room->edge;
	while (curr_edge)
	{
		tmp = curr_edge;
		curr_edge = curr_edge->next;
		free(tmp);
	}
	free(curr_edge);
}

static void			free_rooms(t_room *room)
{
	t_room	*curr;
	t_room	*tmp;

	curr = room;
	while (curr)
	{
		tmp = curr;
		free(tmp->name);
		free_edges(tmp);
		curr = curr->next;
		free(tmp);
	}
}

static void			free_array(t_room **way_in_arr, int len)
{
	if (way_in_arr)
		free(way_in_arr);
	way_in_arr = NULL;
}

void				free_lists_of_way(t_way *way)
{
	t_way			*tmp;

	tmp = way;
	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp);
	}
}

void				free_lem_in2(t_struct *all, t_ways *ways)
{
	t_ways	*tmp;

	free_rooms(all->room);
	while (ways != NULL)
	{
		free_array(ways->way_in_arr, ways->rm_qn - 1);
		free_lists_of_way(ways->way);
		tmp = ways;
		ways = ways->next;
		free(tmp);
	}
	free(all);
}
