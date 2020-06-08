#include "../includes/lem_in.h"

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
			ft_printf("name_rooms%s x=%d  y=%d\n", lk->name, lk->x, lk->y);
			lk = lk->next;
		}
		ft_printf("start: %d\n", all->start_flag);
		ft_printf("end: %d\n", all->end_flag);
		if (all->start)
			ft_printf("start: %s x=%d  y=%d\n", all->start->name, all->start->x, all->start->y);
		if (all->end)
			ft_printf("end: %s x=%d  y=%d\n", all->end->name, all->end->x, all->end->y);
		lk = all->room;
		while (lk)
		{
			ed = lk->edge;
			while (ed)
			{
				ft_printf("edge %s: %s\n", lk->name, ed->room->name);
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
	ft_printf("\nRecorder way\n");
	while (wayS) {
		while (wayS->way) {
			ft_printf("%s->", wayS->way->room->name);
			wayS->way = wayS->way->next;
		}
		ft_printf("\tlong: %d", wayS->rm_qn);
		ft_printf("\n");
		wayS = wayS->next;
		i++;
	}
	ft_printf("\n%d ways", i );
}

void	write_order(t_order *order, t_struct *all)
{
	t_room	*room;

	room = all->end;
	ft_printf ("\nOrder:\n");
	while (order)
	{
		ft_printf("%s ---> ", order->room->name); //печатаем весь путь.
		order = order->next;
	}
	ft_printf("\nThe smallest way from the end:\n");
	ft_printf ("%s ---> ", room->name);
	while (room != all->start)
	{
		ft_printf ("%s ---> ", room->go_from->name); //идём по родителям.
		room = room->go_from;
	}
	ft_printf("\n");
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

