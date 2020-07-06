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

#include "../includes/lem_in.h"

int				check_end_start(t_struct *all)
{
	if (!all->start->edge || !all->end->edge)
		error_print(all);
	return (0);
}

void			error_print(t_struct *all)
{
	if (all->error || !all->room || !all->start || !all->end)
	{
		error_free(all, NULL, NULL, NULL);
		free(all);
		ft_putstr("\nERROR\n");
		exit(0);
	}
}

static void		print_just_text(int fd, char *line, t_struct *all)
{
	int			i;

	i = 0;
	free(line);
	all->error = 1;
	while ((i = get_next_line(0, &line) > 0))
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	error_print(all);
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

int				parser(t_struct *all, char *line, char **split, int size)
{
	while ((size = get_next_line(0, &line)) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (all->error || !(*line))
			print_just_text(0, line, all);
		if (all->ant == 0)
			read_ant(line, all);
		else if (all->link_flag == 0 && (split = is_room(line)) && *line != '#')
			read_room(all, split);
		else if ((split = is_link(line)) && *line != '#')
			read_link(all, split, NULL, NULL);
		else if (*line == '#')
			read_door(all, is_door(line + 1), NULL, NULL);
		if (split)
			ft_free_split(split);
		if (line)
			free(line);
	}
	if (size == -1)
		error_print(all);
	error_print(all);
	check_end_start(all);
	return (1);
}
