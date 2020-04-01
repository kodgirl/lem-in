#include "../includes/lem_in.h"

void     *clean_order(t_order *head_order, t_struct *all)
{
	t_order     *tmp;
	t_room      *tmpRoom;

	tmp = NULL;
	tmpRoom = all->room;
	while (tmpRoom)
	{
		tmpRoom->visit = 0;
		tmpRoom = tmpRoom->next;
	}
	while (head_order)
	{
		tmp = head_order;
		head_order = head_order->next;
		free(tmp);
	}
}

t_way    *invert_way(t_way *way)
{
	t_way   *curr;
	t_way   *next;
	t_way   *prev;
	curr = way;
	prev = NULL;
	next = NULL;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	way = prev;
	return(way);
}

t_way   *FixVisitRooms(t_way *way)
{
	t_way   *fix;
	fix = way;
	while (fix) {
		fix->RoomsOrder->visit = 1;
		fix = fix->next;
	}
	return (way);
}

t_way    *record_way(t_struct *all)
{
	t_way   *HeadWay;
	t_way   *way;
	t_room  *room;
	t_room  *tmp;

	way = (t_way *)malloc(sizeof(t_way));
	way->RoomsOrder = (t_room *)malloc(sizeof(t_room));

	HeadWay = way;
	room = all->end;
	while(room != NULL)
	{
		way->RoomsOrder = room;
		if (room == all->start) {
			way->next = NULL;
			break;
		}
		way->next = malloc(sizeof(t_way));
		tmp = room;
		way = way->next;
		way->next = tmp; // как поставить next следующую вершину? как перевернуть?
		room = room->go_from;
	}
	way = HeadWay;
	room = way->RoomsOrder;

	way = invert_way(way);
	way = FixVisitRooms(way);

	printf("\nRecorder way\n");
	while (way)
	{
		printf("%s--->", way->RoomsOrder->name);
		way = way->next;
	}
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
 * Когда второй раз запускаем bfs, то рёбра заканчиваются. Как их восстановить?
 */

t_way		*bfs(t_struct *all)
{
	t_order	*order;
	t_order	*head_order;
	t_way   *way;

	all->start->visit = 0;
	all->end->visit = 0;
	order = malloc_order(all->start); //идёт выделение памяти и ставится в очередь комната старта
	head_order = order;
	while(order)
	{
		if (order->room == all->end)
			break;
		order->room->visit = 1; // отмечаем, что посетили
		while (order->room->edge) //подбор рёбер
		{
			if (order->room->edge->room->visit == 0) //если след комната не посещена, то
			{
				add_to_order(order->room->edge->room, order); //добавляем её в очередь
				order->room->edge->room->go_from = order->room; //указываем родителя новой вершины
			}
			order->room->edge = order->room->edge->next; // и смотрим следующее ребро к вершине
		}
		order = order->next; //как закончили с рёбрами, берем следующу вершину
	}
	write_order(head_order, all); // для печати отправляем начало очереди
	clean_order(head_order, all);
	way = record_way(all);
	return(way);
}
