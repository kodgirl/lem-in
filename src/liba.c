/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:01:06 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 20:16:42 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			error_free(t_struct *all, t_room *tmp_rooms,
						t_room *tmp_rooms2, t_edge *tmp_edges2)
{
	t_edge		*tmp_edges;

	tmp_rooms = all->room;
	while (tmp_rooms)
	{
		tmp_edges = tmp_rooms->edge;
		while (tmp_edges)
		{
			tmp_edges2 = tmp_edges;
			tmp_edges = tmp_edges->next;
			free(tmp_edges2);
		}
		tmp_rooms2 = tmp_rooms;
		tmp_rooms = tmp_rooms->next;
		free(tmp_rooms2->name);
		free(tmp_rooms2);
	}
	return ;
}

void			ft_free_split(char **for_free)
{
	size_t		i;

	i = 0;
	if (for_free)
	{
		while (for_free[i])
		{
			if (for_free[i])
				free(for_free[i]);
			i++;
		}
		free(for_free);
	}
	for_free = NULL;
}

int				check_char(int *b, char str, int *error)
{
	int			check;

	check = *b;
	*b = (str - 48) + *b * 10;
	if (check != *b / 10)
	{
		*error = 1;
		return (1);
	}
	return (0);
}

int				f_atoi(char *str, int *error)
{
	int			a;
	int			b;

	a = 1;
	b = 0;
	if (*str == 45 && str++)
		a = -a;
	if (*str < 48 || *str > 57)
	{
		*error = 1;
		return (0);
	}
	while (*str >= 48 && *str <= 57)
	{
		if (check_char(&b, *str, error))
			return (0);
		str++;
	}
	if (*str != '\0')
		*error = ERROR_ANTS;
	return (a * b);
}

int				array_len(char **str)
{
	int			len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		++len;
	return (len);
}
