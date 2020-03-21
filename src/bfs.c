#include "../includes/lem_in.h"

void	write_order(t_order *order, t_struct *all)
{
	t_room	*room;

	room = all->end;
	printf ("\nOrder:\n");
	while (order)
	{
		printf("%s ---> ", order->room->name);
		order = order->next;
	}
	printf("\nThe smallest way from the end:\n");
	printf ("%s ---> ", room->name);
	while (room != all->start)
	{
		printf ("%s ---> ", room->go_from->name);
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

int		bfs(t_struct *all)
{
	t_order	*order;
	t_order	*head_order;

	order = malloc_order(all->start);
	head_order = order;
	while(order)
	{
		if (order->room == all->end)
			break;
		order->room->visit = 1;
		while (order->room->edge)
		{
			if (order->room->edge->room->visit == 0)
			{
				add_to_order(order->room->edge->room, order);
				order->room->edge->room->go_from = order->room;
			}
			order->room->edge = order->room->edge->next;
		}
		order = order->next;
	}
	write_order(head_order, all);
	return(0);
}
