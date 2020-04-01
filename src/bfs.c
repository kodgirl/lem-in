#include "../includes/lem_in.h"

void    record_way(t_struct *all)
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

	// переворачиваю путь.
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
	t_way   *fix;
	fix = way;
	while (fix) {
		fix->RoomsOrder->visit = 1;
		fix = fix->next;
	}
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
		rm->visit = 0;
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
 * ************************************************
 * 1. КАК СОХРАНИТЬ ПУТЬ?
 * 2. КАК ЗАПУСКАТЬ ВТОРОЙ РАЗ, ЕСЛИ ПОСЛЕ ПЕРВОГО ЗАПУСКА ОТМЕЧАЕТСЯ И НЕ НУЖНАЯ ВЕРШИН?
 * ЕСЛИ ОТ А ЕСТЬ ПУТЬ В Б И В, ТО ДАЖЕ ЕСЛИ ЕСЛИ КОРОТКИЙ ПУТЬ ЭТО ЧЕРЕЗ Б, ТО В ТОЖЕ
 * ОТМЕЧАЕТСЯ -1 КАК ПОСЕЩЁННЫЙ.
 * Варианты разделения пути - 1. Не отмечать, что прошлись по этим вершинам и, сохранив пути,
 * сравнить списки записанных путей. 2. Делать отметки и найти способ...
 * А что, если найдя путь - отметить его единицей, только после записи.
 * 3. Как перевернуть список записанного пути?
 */

int		bfs(t_struct *all)
{
	t_order	*order;
	t_order	*head_order;

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
	// clean_order(head_order);
	record_way(all);
	return(0);
}
