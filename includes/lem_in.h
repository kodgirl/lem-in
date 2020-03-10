/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:23:02 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/10 21:45:45 by bjasper          ###   ########.fr       */
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

	int				start_flag;
	int				end_flag;
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
int		read_room(t_struct *all, char **split);
int		read_link(t_struct *all, char **split);
int		room_validation(t_room *room, t_room *flat);

#endif