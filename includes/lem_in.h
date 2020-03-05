/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:23:02 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/05 15:42:07 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# define ERROR_NOT_INT		"some arguments are not integers\n"
# define ERROR_BIGGER_INT	"some arguments are bigger than an integer\n"
# define ERROR_DUBL			"there are duplicates\n"
# define ERROR_BAD_INSTRUCT	"wrong instruction\n"

typedef struct		s_room
{
	
	int		link_flag;
	int		index;
	char	*name;
	int		x;
	int		y;
	int		start_end;
	struct s_room	*next;
	struct s_room	*edge;
}					t_room;

typedef struct		s_struct
{
	int				ant_flag;
	t_room			*room;
	int				ant;


}					t_struct;

typedef struct		s_way
{
	int start;
	int end;
}					t_way;


int	parser(int ac, char **av, t_room *room);
int		f_atoi(char *str, int *error);
int 	array_len(char **str);
void	alphabet_sort_rooms(t_room *room);
void	parse_edges(char **array_edges, t_room *room);


#endif