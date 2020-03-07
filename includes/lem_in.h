/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:23:02 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/07 18:51:38 by bjasper          ###   ########.fr       */
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
	
	int		index;
	char	*name;
	int		x;
	int		y;
	struct s_room	*next;
	struct s_edge	*edge;
}					t_room;

typedef struct		s_edge
{
	int				cost;
	struct s_edge	*next;
	struct s_room	*room;
}					t_edge;

typedef struct		s_struct
{
	int				ant_flag;
	t_room			*room;
	int				ant;
	t_room			*start;
	t_room			*end;
	int				error;
	int				link_flag;
}					t_struct;

int		parser(t_struct *all);
int		f_atoi(char *str, int *error);
int 	array_len(char **str);
// void	alphabet_sort_rooms(t_room *room);
// void	parse_edges(char **array_edges, t_room *room);
// void	f_lstadd(t_room **alst, t_room *new);
// t_room	*f_lstnew(size_t content_size);


#endif