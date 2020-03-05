/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:32:20 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/05 20:11:22 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

int	parce_doors(t_way *doors, char *line)
{
	++line;
	if (*line == '#' && line++)
	{
		if (ft_strcmp(line, "start") == 0 && doors->start == 0)
			doors->start = 1;
		else if (ft_strcmp(line, "end") == 0 && doors->end == 0)
			doors->end = 1;
		else
		{
			printf("ERROR\n");
			return(0);
		}			
	}
	return (1);
}

int	read_line(char *line, t_room *room, int size, t_way *doors)
{
	int 	error;
	char	**array_digits;
	char	**array_edges;
	int		len;
	
	error = 0;
	if (*line == '#')
	{
		if (room->link_flag == 0)
			parce_doors(doors, line);
		else
		{
			write (1, "Error\n", 6);
			return (0);
		}
	}
	else 
	{
		array_digits = ft_strsplit(line, ' ');
		len = array_len(array_digits);
		if (len == 3 && room->link_flag == 0)
		{
			array_len(array_digits);
			room->name = *array_digits;
			array_digits++;
			room->x = f_atoi(*array_digits, &error);
			array_digits++;
			room->y = f_atoi(*array_digits, &error);
		}
		else if (len == 1)
		{
			if (room->link_flag == 0)
			{
				room->link_flag = 1;
				alphabet_sort_rooms(room);		
			}
			array_edges = ft_strsplit(line, '-');
			len = array_len(array_edges);
			if (len == 2)
			{
				parse_edges(array_edges, room);
			}
			else
			{
				write (1, "Error\n", 6);
				return (0);
			}
		}
		else
		{
			write (1, "Error\n", 6);
			return (0);
		}
	}
	printf("%d   %d\n", doors->start, doors->end);
	return (1);
}

int	read_ant(char *line)
{
	int error;
	int ant;

	error = 0;
	ant = f_atoi(line, &error);
	if (error || ant <  1)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	else
		return (ant);
}

int	parser(int ac, char **av, t_room *room)
{
	int			size;
	char		*line;
	t_way		doors;
	t_struct	all;
	
	doors.start = 0;
	doors.end = 0;
	all.ant_flag = 0;
	while ((size = get_next_line(0, &line)) > 0)
	{
		if (all.ant_flag == 0)
		{
			all.ant_flag = 1;
			all.ant = read_ant(line);
		}
		else if (all.ant_flag == 1)
			read_line(line, room, size, &doors);
		else
		{
			write (1, "Error\n", 6);
			return (0);
		}
		printf("%d\n", all.ant);
		free(line);
	}
	//del_links(&link);
	return (1);
}
