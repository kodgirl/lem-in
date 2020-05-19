#include "../includes/lem_in.h"

/*
** For free bfs's order.
*/

void	free_order(t_order *head_order, t_order *tmp)
{
	while (head_order)
	{
		tmp = head_order;
		head_order = head_order->next;
		free(tmp);
	}
}

/*
** Next functions for print other processes.
*/

void	print_all_rooms(t_struct *all)
{
	t_room	*lk;
	t_edge	*ed;

	if (all->room)
	{
		lk = all->room;
		while (lk)
		{
			printf("name_rooms%s x=%d  y=%d\n", lk->name, lk->x, lk->y);
			lk = lk->next;
		}
		printf("start: %d\n", all->start_flag);
		printf("end: %d\n", all->end_flag);
		if (all->start)
			printf("start: %s x=%d  y=%d\n", all->start->name, all->start->x, all->start->y);
		if (all->end)
			printf("end: %s x=%d  y=%d\n", all->end->name, all->end->x, all->end->y);
		lk = all->room;
		while (lk)
		{
			ed = lk->edge;
			while (ed)
			{
				printf("edge %s: %s\n", lk->name, ed->room->name);
				ed = ed->next;
			}
			lk = lk->next;
		}
	}
}

void 		printRecordWay(t_ways *head_wayS)
{
	int 	i;
	t_ways	*wayS;

	wayS = head_wayS;
	i = 0;
	printf("\nRecorder way\n");
	while (wayS) {
		while (wayS->way) {
			printf("%s->", wayS->way->room->name);
			wayS->way = wayS->way->next;
		}
		printf("\tlong: %d", wayS->vtx_qn);
		printf("\n");
		wayS = wayS->next;
		i++;
	}
	printf("\n%d ways", i );
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

void	del_double_massive(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&(str[i]));
		++i;
	}
	free(str);
}

