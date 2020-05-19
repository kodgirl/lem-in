/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:44:50 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/10 20:58:39 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

/*
** Variable flat mean all rooms of argument;
** Checking duplicates between names of recorded rooms and new room.
** Checking duplicates of coordinates of rooms;
** If all fine, sending 1 than to record new room;
*/

int		room_validation(t_room *room, t_room *flat)
{
	while (flat && room != flat)
	{
		if (ft_strcmp(room->name, flat->name) == 0)
			return (0);
		if (room->x == flat->x && room->y == flat->y)
			return (0);
		flat = flat->next;
	}
	return (1);
}