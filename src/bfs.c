#include "../includes/lem_in.h"

void	*clean_order(t_order *head_order, t_struct *all, t_room *tmpRoom, t_edge *edges)
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
 * Если добавляемая комната последняя, то выходит. Так как от последней комнаты некуда дальше идти.
 * А иначе берётся комната и рёбра этой комнаты в tmp_edges;
 * Настоящая комната отмечается помеченной, чтобы обратно не возвращаться.
 * Дальше идём по рёбрам настоящей комнаты. Если выбранное ребро комнаты не использовано, а та комната, на которое указывает ребро, не посещено,
 * то эта комната добавляется в очередь.
 * Так проходим по всем рёбрам настоящей комнаты.
 *
 * Почему код во второй раз добавляет D через F, если он уже был добавлен через E.
 * Приходит лист с очередлью. Беру из очереди комнату, из комнаты ребро и прохожусь по всем рёбрам в цикле.
 * Сразу указываю в комнате, которая посещена через ребро, единицей. Далее смотрю - если эта комната
 * последняя, то указываю родителя и выхожу.
 * Если же нет, то смотрю было ли использовано это ребро И посещена ли была эта, на которую указывает ребро
 * И не входит ли эта комната в другой путь. Если нет, то добавляю её в список очереди.
*/
int 	perform_order(t_order *order, t_struct *all, t_edge *tmp_edges, t_room *tmp_room)
{
	if (order->room == all->end)
		return (1);
	tmp_room = order->room;
	tmp_edges = tmp_room->edge;
	while (tmp_edges) {
		if (tmp_edges->room == all->end)
		{
			tmp_edges->room->go_from = tmp_room;
			tmp_edges->room->visit = 1;
			return 1;
		}
		if (tmp_edges->cost == 1 && tmp_edges->room->visit == 0 && !tmp_edges->room->in_way) {
			add_to_order(tmp_edges->room, order);
			tmp_edges->room->go_from = tmp_room;
		}
		tmp_edges->room->visit = 1;
		tmp_edges = tmp_edges->next;
	}
	return (0);
}

/*
 * Создаётся очередь в виде листов.
 * В лист добавляется первая комната.
 * Когда все рёбра первой комнаты рассмотрены и добавлены в очередь, тогда
 * продвигаемся дальше по найденным через рёбра комнатам.
 * Когда дошли по одному из путей до конца, то записываем этот путь в record_way
 * и очищаем память от order, выделенную для очереди.
 */

t_way		*bfs(t_struct *all, t_order *order, t_order *head_order, t_way *way)
{
	int 	i;

	i = 0;
	order = malloc_order(all->start);
	head_order = order;
	all->start->in_way = 0;
	all->start->visit = 1;
	all->end->in_way = 0;
	while(order)
	{
		i = perform_order(order, all, NULL, NULL);
		if (i == 1)
			break;
		order = order->next;
	}
	//TODO если путь не нашёл, то что должен делать?
	if (!all->end->visit)
	    return (NULL);
    way = record_way(all, NULL, NULL, NULL);
	clean_order(head_order, all, NULL, NULL);
	return(way);
}


