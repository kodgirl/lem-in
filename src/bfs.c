#include "../includes/lem_in.h"

void 	free_order(t_order *head_order, t_order *tmp)
{
	while (head_order)
	{
		tmp = head_order;
		head_order = head_order->next;
		free(tmp);
	}
}

void     *clean_order(t_order *head_order, t_struct *all, t_room *tmpRoom, t_edge *edges)
{
	tmpRoom = all->room;
	while (tmpRoom)
    {
        edges = tmpRoom->edge;
	    while (edges)
	    {
	        if (edges->cost == -1)
	            edges = edges->next;
	        else
            {
	            edges->cost = 1;
	            edges = edges->next;
	        }
	    }
	    tmpRoom = tmpRoom->next;
    }
	free_order(head_order, NULL);
}


void	write_order(t_order *order, t_struct *all)
{
	t_room	*room;

	room = all->end;
	printf ("\nOrder:\n");
	while (order)
	{
		printf("%s ---> ", order->room->name); //печатаем весь путь.
		order = order->next;
	}
	printf("\nThe smallest way from the end:\n");
	printf ("%s ---> ", room->name);
	while (room != all->start)
	{
		printf ("%s ---> ", room->go_from->name); //идём по родителям.
		room = room->go_from;
	}
	printf("\n");
}

/*
** To create order - we are just allocating memory like for simple list
** And move the start room to order
*/

t_order	*malloc_order(t_room *rm)
{
	t_order	*order;
	
	if ((order = (t_order*)malloc(sizeof(t_order))))
	{
		ft_bzero(order, sizeof(t_order));
		order->room = rm;
		return (order);
	}
	else
		return (NULL);
}

/*
** Every new room will be added after allocating memory
** and move by next of current room in order.
*/

void	add_to_order(t_room *room, t_order *order)
{
	t_order	*add;
	t_order *tmp;
	
	tmp = order;
	add = malloc_order(room);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;	
}

/*
** Когда второй раз запускаем bfs, то рёбра заканчиваются. Как их восстановить?
** Init visit variable in start and end with 0.
** Allocating memory for order and puting first room by order.
** And launching cycle with allocated order. In cycle comparing room in order and end order.
** If room in order isn't end - marking that we visited this room.
** In new cycle looking for new rooms via edges of current room.
** If next of edge room isn't visited - adding this room to order
** and marking parent of this room.
** And going to the next edge of current room.
** If all edges ended - alg checking next room in order.
** After bfs - cleaning memory which allocated for order.
** Используется order->room->visit для того, чтобы если, например,
** граф начинается с А и есть связь от А к В и от В к А, то чтобы от В к А
** (т.е. к началу) не возвращался.
*/
int 	perform_order(t_order *order, t_struct *all, t_edge *tmp_edges, t_room *tmp_room)
{
	if (order->room == all->end)
		return (1);
	tmp_room = order->room;
	tmp_edges = tmp_room->edge;
	order->room->visit = 1;
	while (tmp_edges) {
		if (tmp_edges->cost == 1 && tmp_edges->room->visit == 0) {
			add_to_order(tmp_edges->room, order);
			tmp_edges->room->go_from = tmp_room;
		}
		tmp_edges = tmp_edges->next;
	}
}

t_way		*bfs(t_struct *all, t_order *order, t_order *head_order, t_way *way)
{
	int 	i;

	i = 0;
	order = malloc_order(all->start);
	head_order = order;
	while(order)
	{
		i = perform_order(order, all, NULL, NULL);
		if (i == 1)
			break ;
		order = order->next;
	}
	if (head_order->next == NULL)
	    return (NULL);
    way = record_way(all, NULL, NULL, NULL);
	clean_order(head_order, all, NULL, NULL);
	return(way);
}

//	write_order(head_order, all);