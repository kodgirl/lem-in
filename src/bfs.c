#include "../includes/lem_in.h"

void	write_order(t_order *order, t_struct *all)
{
	t_room	*room;
	t_way   *ways;

	ways = (t_way *)malloc(sizeof(t_way));
	ft_bzero(ways, sizeof(t_way));
	room = all->end;
	ways->room = room;
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
		ways->room = room->go_from;
		ways->next = (t_way *)malloc(sizeof(t_way));
		ways = ways->next;
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
 * ************************************************
 * 1. КАК СОХРАНИТЬ ПУТЬ?
 * 2. КАК ЗАПУСКАТЬ ВТОРОЙ РАЗ, ЕСЛИ ПОСЛЕ ПЕРВОГО ЗАПУСКА ОТМЕЧАЕТСЯ И НЕ НУЖНАЯ ВЕРШИН?
 * ЕСЛИ ОТ А ЕСТЬ ПУТЬ В Б И В, ТО ДАЖЕ ЕСЛИ ЕСЛИ КОРОТКИЙ ПУТЬ ЭТО ЧЕРЕЗ Б, ТО В ТОЖЕ
 * ОТМЕЧАЕТСЯ -1 КАК ПОСЕЩЁННЫЙ.
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
	return(0);
}
