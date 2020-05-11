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

/*
** Every room is vertex of graph.
** index - variable which keep index of vertexes;
** *name - for name of vertexes;
** x and y for coordinate of every vertex;
** *next - direct to the next vertex;
** *edge - keep direction of one vertex to next;
** 0: 1->2 // vertex have edge with 1 and 2;
** 1: 3->4 // vertex 1 have edge with 2 and 4 ...
*/

typedef struct		s_room
{
	char	        *name;
	int		        x;
	int		        y;
	int             distance;
	int             visit;
	struct s_room	*next;
	int             index;
	struct s_edge	*edge;
	struct s_room	*go_from;
	int 			ant;
}					t_room;


/*
** t_edge using for build edges between vertexes.
** cost - variable which keep info about used this direction or not;
** *next contain direction to next vertex (or room);
*/

typedef struct		s_edge
{
	int				cost;
	struct s_room	*room;
	struct s_edge	*next;
}					t_edge;

/*
** start_flag indicate have argument start room or not;
** end_flag, ant_flag, and link_flag have the same goal.
** link_flag checking existing of connections between rooms;
** *room - all vertexes;
** ant - count of ants in arguments;
** *start - starting room;
** *end - finish room where should be ants;
** error - if have not correct data;
*/

typedef struct		s_struct
{
	int				ant;
	t_room			*room;
	t_room			*start;
	t_room			*end;
	int             rm_count;
	int				error;
	unsigned short int	start_flag;
	unsigned short int	end_flag;
	unsigned short int	ant_flag;
	unsigned short int	link_flag;
}					t_struct;

typedef struct      s_way
{
	t_room          *room;
	struct s_way    *next;
}                   t_way;



typedef struct		s_order
{
	t_room			*room;
	struct s_order	*next;
}					t_order;

typedef struct      s_ways
{
    t_way           *way;
    int 			vtx_qn;
	int 			expression;
	struct s_ways   *next;
}                   t_ways;

/*
 * FIXME change names of structure;
*/

typedef struct		s_sum
{
	int				number_of_ants;
	int				sum_steps_all_ways;
	int				number_of_ways;
	int				result;
	int				str_sum;
}					t_calc;

typedef struct 		s_array
{
	t_way			**way;
	t_ways			**wayS;
	t_room			**rooms;
}					t_array;

int		    parser(t_struct *all);
int		    f_atoi(char *str, int *error);
int 	    array_len(char **str);
int		    read_room(t_struct *all, char **split);
int		    read_link(t_struct *all, char **split);
int		    room_validation(t_room *room, t_room *flat);
void        free_lem_in(t_struct *all);
void        ft_free_split(char **for_free);

int 		ft_solution(t_struct *all, t_way *way, t_ways *wayS, t_ways *head_wayS);
t_way       *ft_dijkstra(t_struct *all);
t_way		*bfs(t_struct *all, t_order *order, t_order *head_order, t_way *way);
void     	*clean_order(t_order *head_order, t_struct *all, t_room *tmpRoom, t_edge *edges);
/*
** Record way function
*/

t_way		*record_way(t_struct *all, t_way *HeadWay, t_way *way, t_room *room);
t_way		*FixVisitRooms(t_way *way, t_way *tmpWay, t_edge *tmpEdge, t_room *room);
t_way		*invert_way(t_way *way, t_way *curr, t_way *next, t_way *prev);

/*
 * TODO change names of fucntions;
 */

void 		printRecordWay(t_ways *head_wayS);

int 		move_ant(t_way *way, int i, t_struct *all);
void 	gen_cycle(t_ways *head_wayS, t_struct *all);

#endif