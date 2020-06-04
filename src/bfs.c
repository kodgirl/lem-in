#include "../includes/lem_in.h"
#include <limits.h>

/*
 * Выделяю лист для следующей комнаты в очереди.
 * Смотрю является ли эта комната посещённой.
 * Если нет, то проверяю является ли она последней.
 * Далее в цикле дохожу к концу очереди. Создаю новый лист для комнаты.
 * Закидываю туда соседнюю комнату. Делаю вычисления для опр-я порядка визита.
 * Указываю с какой комнаты она прибыла.
 *
 */

void 	push_room(t_edge *read_edge, t_order *order, t_struct *all)
{
	t_room *read_rooms;
	t_order *orders_runner;

	orders_runner = order;
	read_rooms = read_edge->room;
	if (read_rooms->visit == -1 || read_rooms->visit == INT_MAX)
	{
		if (read_rooms->visit == INT_MAX)
			read_rooms->go_from = order->room;
		while (orders_runner->next != NULL)
			orders_runner = orders_runner->next;
		orders_runner->next = (t_order *)ft_memalloc(sizeof(t_order));
		orders_runner->next->room = read_edge->room;
		orders_runner->next->room->visit = order->room->visit + 1;
		orders_runner->next->room->go_from = order->room;
		read_edge->cost = 1;
	}
	else
		read_edge = read_edge->next;
}

t_way 	*bfs(t_struct *all)
{
	t_room	*runner_rm;
	t_order *order;
	t_order *orders_head;
	t_edge	*runner_ed;
	t_way	*way;

	order = ft_memalloc(sizeof(t_order));
	order->room = all->start;
	orders_head = order;
	order->room->visit = 0;
	while (order)
	{
		if (order->room == all->end)
			break;
		runner_ed = order->room->edge;
		while (runner_ed)
		{
			if (runner_ed->cost == 1)
				runner_ed = runner_ed->next;
			else {
				push_room(runner_ed, order, all);
				runner_ed = runner_ed->next;
			}
		}
		order = order->next;
	}
	return (1);
}