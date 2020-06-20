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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../src/libft/includes/libft.h"
# include "../src/libft/ft_printf/printf.h"

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

//TODO распиши здесь все коды ошибки и вызывай ошибки не по номеру, а по определенным здесь константам

#define ERROR_ANTS 1
#define ERROR_READ_ROOMS 2
#define ERROR_INVALID_LINKS 3
#define ERROR_RECORD_START_FINISH 4
#define ERROR_WAYS_NOT_FOUND 5

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
	short 			in_way;
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
	int 			rm_count;
	int				error;
	short			start_flag;
	short			end_flag;
	short			ant_flag;
	short			link_flag;
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
	unsigned		rm_qn;
	int calc;
	t_room			**way_in_arr;
	struct s_ways   *next;
}                   t_ways;

int					parser(t_struct *all, char *line, char **split);
void				read_ant(char *line, t_struct *all);
char				**is_room(char *line);
char				**is_link(char *line);
int					is_door(char *line);
int				    f_atoi(char *str, int *error);
int 			    array_len(char **str);
int				    read_room(t_struct *all, char **split);
int					read_link(t_struct *all, char **split, t_room *room1, t_room *room2);
int				    room_validation(t_room *room, t_room *flat);
void    		    free_lem_in(t_struct *all, t_room *tmp_rooms, t_room *tmp_rooms2, t_edge *tmp_edges2);
void				ft_free_split(char **for_free);
void				error_print(t_struct *all);
int					check_end_start(t_struct *all);

/*
** Functions of find ways and print results
*/

int					start_actions(t_struct *all);
t_ways 				*record_ways(t_struct *all);
t_way				*processing_way(t_struct *all, t_room *last_room, t_way *new_way);
t_way 				*add_room_to_way(t_room *room, t_way *new_way, t_struct *all);
int 				calc_rooms_in_way(t_way *way);
void 				annual_rooms_vars(t_struct *all);

/*
 * Next functions of bfs regulation
 */

int					bfs(t_struct *all);
int					read_edges_room(t_edge *edge, t_order *order, t_struct *all);
void				add_room(t_order *order, t_room *new_room);
t_order				*allocate_orders_list(t_room *start_room);


/*
 * Next functions with goal of marking used edges and rooms
 * in new way and clear variable visited than to start bfs again.
 */

void 				annual_rooms_vars(t_struct *all);
void 				mark_used_rooms(t_struct *all, t_way *way);
void 				mark_used_edges(t_struct *all, t_way *way);
void				preparing_to_bfs(t_struct *all, t_way *way);
void				free_order(t_order *clean_order);
t_room				**record_to_array(t_way *way, int quantity);

/*
 * Functions for printing results
 */

void 				ants_movement(t_ways *all_ways, t_struct *all);
void		 		ways_expressions(t_ways *ways, t_struct *all);

/*
 * Utilits
 */

void 				print_way(t_room **arr);

#endif