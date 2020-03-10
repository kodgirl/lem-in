/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:21:26 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/10 20:50:03 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

t_room	*malloc_room(char **split)
{
	t_room 	*rm;
	int		error;
	
	if ((rm = (t_room*)malloc(sizeof(t_room))))
	{
		ft_bzero(rm, sizeof(t_room));
		rm->name = ft_strdup(split[0]);
		rm->x = f_atoi(split[1], &error);
		rm->y = f_atoi(split[2], &error);
		if (error != 0)
		{
			free(rm->name);
			free(rm);
			return (NULL);
		}
		return (rm);
	}
	else
		return (NULL);
}

int		read_room(t_struct *all, char **split)
{
	t_room	*rm;
	t_room	*temp;
	
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
			return (1);
		}
	}
	all->error = 1;
	return (0);
}
