/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:32:20 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/10 22:30:19 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

void	read_ant(char *line, t_struct *all)
{
	all->ant = f_atoi(line, &(all->error));
}

char	**is_room(char *line)
{
	char	**str;
	
	str = ft_strsplit(line, ' ');
	if (array_len(str) != 3)
		return (NULL);
	return (str);
}

char	**is_link(char *line)
{
	char	**str;
	
	str = ft_strsplit(line, '-');
	if (array_len(str) != 2)
		return (NULL);
	return (str);
}

void	print_all_rooms(t_struct *all)
{
	t_room	*lk;
	t_edge	*ed;

	if (all->room)
	{
		lk = all->room;
		while (lk)
		{
			printf("name_rooms%s x=%d  y=%d\n", lk->name, lk->x, lk->y);
			lk = lk->next;
		}
		printf("start: %d\n", all->start_flag);
		printf("end: %d\n", all->end_flag);
		if (all->start)
			printf("start: %s x=%d  y=%d\n", all->start->name, all->start->x, all->start->y);
		if (all->end)
			printf("end: %s x=%d  y=%d\n", all->end->name, all->end->x, all->end->y);
		lk = all->room;
		while (lk)
		{
			ed = lk->edge;
			while (ed)
			{
				printf("edge %s: %s\n", lk->name, ed->room->name);
				ed = ed->next;
			}
			lk = lk->next;
		}
	}
}

int		is_door(char *line)
{
	if (line && *line == '#' && ft_strcmp(line, "#start") == 0)
		return (1);
	if (line && *line == '#' && ft_strcmp(line, "#end") == 0)
		return (2);
	return (0);
}

void	door_to_room(t_room *room, t_struct *all, int i)
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

int		read_door(t_struct *all, int i)
{
	char		*line;
	char		**split;
	
	split = NULL;
	line = NULL;
	if ((i == 1 && all->start_flag == 1) || (i == 2 && all->end_flag == 1))
		all->error = 1;
	else if (i != 0 && get_next_line(0, &line) > 0)
	{
		if ((split = is_room(line)) && all->link_flag == 0)
		{
			read_room(all, split);
			door_to_room(all->room, all, i);
		}			
		else
			all->error = 1;
	}
	if (split)
		free(split);
	if (line)
		free(line);
	return (0);
}

int		parser(t_struct *all)
{
	int			size;
	char		*line;
	char		**split;
	
	split = NULL;
	while ((size = get_next_line(0, &line)) > 0)
	{
		if (all->ant == 0)
			read_ant(line, all);
		else if ((split = is_room(line)) && all->link_flag == 0)
			read_room(all, split);
		else if((split = is_link(line)))
			read_link(all, split);
		else if (*line == '#')
			read_door(all, is_door(line + 1));
		else
			all->error = 1;	
		if (split)
			free(split);
		free(line);
		if (all->error)
		{
			write(1, "Error, sorry guy :(\n", 20);
			return (0);
		}
	}
	print_all_rooms(all);
	//del_links(&link);
	return (1);
}
