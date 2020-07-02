/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_utilits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <dpenney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:21:13 by dpenney           #+#    #+#             */
/*   Updated: 2020/06/26 12:21:16 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** changing from char to int and record ants;
*/

void	read_ant(char *line, t_struct *all)
{
	all->ant = f_atoi(line, &all->error);
	if (all->ant < 0)
		all->error = ERROR_ANTS;
}

/*
** Validating format of rooms;
*/

char	**is_room(char *line)
{
	char	**str;

	str = ft_strsplit(line, ' ');
	if (array_len(str) != 3 || *line == '#')
	{
		ft_free_split(str);
		return (NULL);
	}
	return (str);
}

char	**is_link(char *line)
{
	char	**str;

	str = ft_strsplit(line, '-');
	if (array_len(str) != 2)
	{
		ft_free_split(str);
		return (NULL);
	}
	return (str);
}

/*
** Checking comments of start and end
** which indicating with two sharps (##);
*/

int		is_door(char *line)
{
	if (line && *line == '#' && ft_strcmp(line, "#start") == 0)
		return (1);
	if (line && *line == '#' && ft_strcmp(line, "#end") == 0)
		return (2);
	return (0);
}
