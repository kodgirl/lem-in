/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:32:20 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/07 19:05:05 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

// int	parce_doors(t_way *doors, char *line, int *error)
// {
// 	++line;
// 	if (*line == '#' && line++)
// 	{
// 		if (ft_strcmp(line, "start") == 0 && doors->start == 0)
// 			doors->start = 1;
// 		else if (ft_strcmp(line, "end") == 0 && doors->end == 0)
// 			doors->end = 1;
// 		else
// 			*error = 1;			
// 	}
// 	return (0);
// }

// int	read_line(char *line, t_room *room, int size, t_way *doors, int *error)
// {
// 	char	**array_digits;
// 	char	**array_edges;
// 	int		len;
	
// 	if (*line == '#')
// 	{
// 		if (room->link_flag == 0)
// 			parce_doors(doors, line, error);
// 		else
// 			*error = 1;
// 	}
// 	else 
// 	{
// 		array_digits = ft_strsplit(line, ' ');
// 		len = array_len(array_digits);
// 		if (len == 3 && room->link_flag == 0)
// 		{
// 			array_len(array_digits);
// 			room->name = *array_digits;
// 			array_digits++;
// 			room->x = f_atoi(*array_digits, error);
// 			array_digits++;
// 			room->y = f_atoi(*array_digits, error);
// 		}
// 		else if (len == 1)
// 		{
// 			if (room->link_flag == 0)
// 			{
// 				room->link_flag = 1;
// 				alphabet_sort_rooms(room);		
// 			}
// 			array_edges = ft_strsplit(line, '-');
// 			len = array_len(array_edges);
// 			if (len == 2)
// 				parse_edges(array_edges, room);
// 			else
// 				*error = 1;
// 		}
// 		else
// 			*error = 1;
// 	}
// 	printf("%d   %d\n", doors->start, doors->end);
// 	return (0);
// }

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
		while (temp && temp->next)
			temp = temp->next;
		if (temp)
			temp->next = rm;
		else
			all->room = rm;
		return (1);
	}
	else
	{
		all->error = 1;
		return (0);
	}
}

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

void	print_all_rooms(t_struct *all)
{
	t_room	*lk;

	if (all->room)
	{
		lk = all->room;
		while (lk)
		{
			printf("name_rooms%s x=%d  y=%d\n", lk->name, lk->x, lk->y);
			lk = lk->next;
		}
	}
}

int	parser(t_struct *all)
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
		else if((split = is_link(line)) && all->link_flag == 1)
			read_link(all, split);
		// else if () // для старт и енд
		if (split)
			free(split);
		free(line);
	}
	print_all_rooms(all);
	//del_links(&link);
	return (1);
}
