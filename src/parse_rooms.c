/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:21:26 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 21:31:35 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Allocating memory for room;
** Annual all cells;
** recording name and coordinates of room;
** Checking errors;
*/

t_room			*malloc_room(char **split)
{
	t_room		*rm;
	int			error;

	error = 0;
	if ((rm = (t_room *)malloc(sizeof(t_room))))
	{
		ft_bzero(rm, sizeof(t_room));
		rm->name = ft_strdup(split[0]);
		rm->x = f_atoi(split[1], &error);
		rm->y = f_atoi(split[2], &error);
		if (error != 0 || rm->name[0] == 'L')
		{
			free(rm->name);
			free(rm);
			return (NULL);
		}
		rm->in_way = 0;
		return (rm);
	}
	else
		return (NULL);
}

/*
** Through function malloc_room recording name, x and y of room;
** Taking pointer of all->room than to add new room.
** Sending receiving room and pointer of list of all rooms
** to function room_validation which check dupl of names and x/y;
** If all fine - recording new room by end of list of rooms
** or put new room by start of list;
*/

int				read_room(t_struct *all, char **split)
{
	t_room		*rm;
	t_room		*temp;

	if ((rm = malloc_room(split)))
	{
		temp = all->room;
		if (room_validation(rm, temp) == 1)
		{
			while (temp && temp->next)
				temp = temp->next;
			if (temp)
				temp->next = rm;
			else
				all->room = rm;
			all->rm_count++;
			return (1);
		}
		free(rm->name);
		free(rm);
	}
	if (!all->error)
		all->error = ERROR_READ_ROOMS;
	return (0);
}

void			door_to_room(t_room *room, t_struct *all, int i)
{
	t_room *tmp;

	tmp = room;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (i == 1)
	{
		if (tmp)
			all->start = tmp;
		else
			all->start = room;
		all->start_flag = 1;
	}
	if (i == 2)
	{
		if (tmp)
			all->end = tmp;
		else
			all->end = room;
		all->end_flag = 1;
	}
}

int				read_door(t_struct *all, int i, char *line, char **split)
{
	if ((i == 1 && all->start_flag == 1) || (i == 2 && all->end_flag == 1))
		all->error = 4;
	while (i != 0 && get_next_line(0, &line) > 0 && line[0] == '#')
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	if (line)
	{
		ft_putstr(line);
		ft_putstr("\n");
		if ((split = is_room(line)) && all->link_flag == 0)
		{
			read_room(all, split);
			door_to_room(all->room, all, i);
		}
		else
			all->error = ERROR_RECORD_START_FINISH;
		free(line);
	}
	if (split)
		ft_free_split(split);
	return (0);
}
