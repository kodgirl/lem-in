#include "../includes/lem_in.h"
#include <limits.h>
//
//void	*clean_order(t_order *head_order, t_struct *all, t_room *tmpRoom, t_edge *edges)
//{
//	tmpRoom = all->room;
//	while (tmpRoom)
//    {
//        edges = tmpRoom->edge;
//	    while (edges)
//	    {
//	        if (edges->cost == -1)
//	            edges = edges->next;
//	        else
//            {
//	            edges->cost = 1;
//	            edges = edges->next;
//	        }
//	    }
//	    tmpRoom = tmpRoom->next;
//    }
//	free_order(head_order, NULL);
//}
//
//
///*
//** To create order - we are just allocating memory like for simple list
//** And move the start room to order
//*/
//
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
//
///*
//** Every new room will be added after allocating memory
//** and move by next of current room in order.
//*/
//
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
//
///*
// * Если добавляемая комната последняя, то выходит. Так как от последней комнаты некуда дальше идти.
// * А иначе берётся комната и рёбра этой комнаты в tmp_edges;
// * Настоящая комната отмечается помеченной, чтобы обратно не возвращаться.
// * Дальше идём по рёбрам настоящей комнаты. Если выбранное ребро комнаты не использовано, а та комната, на которое указывает ребро, не посещено,
// * то эта комната добавляется в очередь.
// * Так проходим по всем рёбрам настоящей комнаты.
//*/
//int 	perform_order(t_order *order, t_struct *all, t_edge *tmp_edges, t_room *tmp_room)
//{
//	if (order->room == all->end)
//		return (1);
//	tmp_room = order->room;
//	tmp_edges = tmp_room->edge;
//	order->room->visit += 1;
//	while (tmp_edges) {
//		if (tmp_edges->room->visit == -1) {
//			add_to_order(tmp_edges->room, order);
//			tmp_edges->room->go_from = tmp_room;
//		}
//		tmp_edges = tmp_edges->next;
//	}
//}
//
///*
// * Создаётся очередь в виде листов.
// * В лист добавляется первая комната.
// * Когда все рёбра первой комнаты рассмотрены и добавлены в очередь, тогда
// * продвигаемся дальше по найденным через рёбра комнатам.
// * Когда дошли по одному из путей до конца, то записываем этот путь в record_way
// * и очищаем память от order, выделенную для очереди.
// * Почему его комната сразу находит при одной и той же
// * карте Е, а моя карта находит В?
// * Проблема может кроиться в парсере, который неправильно парсит
// * данные. Если сначала должен добавить ребро к Е, то у меня
// * добавляет ребро к В.
// * Я не понимаю до сих пор. Попробую поменять местами рёбра А.
// */
//
//void 	change_edge_positions(t_struct *all)
//{
//	t_edge *tmp;
//
//	tmp = all->start->edge;
//	all->start->edge = all->start->edge->next;
//	all->start->edge->next = tmp;
//}
//
//t_way		*bfs(t_struct *all, t_order *order, t_order *head_order, t_way *way)
//{
//	int 	i;
//
//	i = 0;
//	order = malloc_order(all->start);
//	head_order = order;
//	while(order)
//	{
//		i = perform_order(order, all, NULL, NULL);
//		if (i == 1)
//			break ;
//		order = order->next;
//	}
//	if (head_order->next == NULL)
//	    return (NULL);
//    way = record_way(all, NULL, NULL, NULL);
//	clean_order(head_order, all, NULL, NULL);
//	return(way);
//}
t_way		*bfs(t_struct *all, t_order *order, t_order *head_order, t_way *way)
{
	t_order *orders_runner;

	orders_runner = malloc_order(all->start);

}