/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:32:20 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 21:24:51 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

// FIXME Что делаем, когда приходит аргумент с символом -- в имени. Выходит ошибка, когда устанавливается путь

/*
** changing from char to int and record ants;
*/

void	read_ant(char *line, t_struct *all)
{
	all->ant = f_atoi(line, &(all->error));
}

/*
** Validating format of rooms;
*/

char	**is_room(char *line)
{
	char	**str;
	
	str = ft_strsplit(line, ' ');
	if (array_len(str) != 3)
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

/*
 * TODO Добавить функцию error_print.
*/

int		read_door(t_struct *all, int i, char *line, char **split)
{
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
		free(line);
	}
	if (split)
		ft_free_split(split);
	return (0);
}

int		check_end_start(t_struct *all)
{
	if (!all->start->edge || !all->end->edge)
		all->error = 1;
	return (0);
}

/*
** Through gnl parsing from file;
** Validating through term operator;
** And after it - recording ants, rooms, links;
** Fucntion read_room in different file parse_rooms;
** Function read_links and read_edges in parse_edges;
** read_ant recording to int variable;
** read_room recording to list of rooms;
** read_link allocating memory for edges and adding
** this edges to rooms structure.
** read doors recording comments ##start and ##end;
*/

// FIXME как прочитать фдешник два раза. Сначала печатать всю карту, а потом начать запись.

int		parser(t_struct *all)
{
	int			size;
	char		*line;
	char		**split;

	all->rm_count = 0;
	split = NULL;
	while ((size = get_next_line(0, &line)) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (all->ant == 0)
			read_ant(line, all);
		else if ((split = is_room(line)) && all->link_flag == 0 && *line != '#')
		    read_room(all, split);
		else if((split = is_link(line)) && *line != '#')
		    read_link(all, split, NULL, NULL);
        else if (*line == '#')
			read_door(all, is_door(line + 1), NULL, NULL);
		else
			all->error = 1;
		if (split)
		    ft_free_split(split);
		if (line)
		    free(line);
		if (all->error)
		{
		    free_lem_in(all, NULL, NULL, NULL);
			write(1, "ERROR\n", 7);
			exit(0);
		}
	}
	check_end_start(all);
	if (all->error)
	{
	    free_lem_in(all, NULL, NULL, NULL);
		write(1, "\nERROR\n", 7);
		exit(0);
	}
	return (1);
}






