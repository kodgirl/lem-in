/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:52:35 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/08 15:22:56 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

t_room	*search_room_name(char *name, t_struct *all)
{
	t_room *tmp;
	
	tmp = all->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_edge	*malloc_edge(void)
{	
	t_edge	*edge;
	
	if ((edge = (t_edge *)malloc(sizeof(t_edge))))
	{
		ft_bzero(edge, sizeof(t_edge));
		return (edge);
	}
	return (NULL);
}

void	add_edge_to_room(t_room *rm, t_edge *edge)
{
	t_edge	*tmp;

	tmp = rm->edge;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	if (tmp)
		tmp->next = edge;
	else
		rm->edge = edge;	
}

int		read_link(t_struct *all, char **split)
{
	t_room	*room1;
	t_room	*room2;
	t_edge	*edg1;
	t_edge	*edg2;
	
	room1 = search_room_name(split[0], all);
	room2 = search_room_name(split[1], all);
	if (room1 && room2)
	{
		edg1 = malloc_edge();
		edg2 = malloc_edge();
		edg1->room = room2;
		edg2->room = room1;
		add_edge_to_room(room1, edg1);
		add_edge_to_room(room2, edg2);
		return (1);
	}
	else
		return (0);	
}