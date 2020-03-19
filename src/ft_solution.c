#include "../includes/lem_in.h"
# define INT_MAX 2147483647

/*
 * looking for smallest edge and saving
 * in variable keep;
 * After it
 */

t_way        *ft_dijkstra(t_struct *all)
{
	t_room  *tmp;
	t_edge  *keep;
	t_way   *way;
	t_way   *tmp_way;
	int     cp_count;

	cp_count = all->rm_count;
	tmp = all->start; //than to start cycle
	way->rooms = tmp; // than to record begin of graph
	tmp_way = way; // than to don't lost head of way;
	all->start->cost = 0;
	all->start->visit = 0; // всегда устанавливаем флаг, что в этих вершинах не были
	all->end->visit = 0; // то же самое, чтобы дошёл до конечной вершины.

	while (cp_count-- != 0)
	{
		if (tmp == all->end)
			printf("SEXY!\n");
		keep = tmp->edge;
		while (tmp->edge) //смотрим рёбра настоящей вершины
		{
			if (keep > tmp->edge && !(tmp->edge->room->cost > INT_MAX)) // в цикле ищём наименьшее ребро и проверяем НЕ является ли
				//эта комната посещённой. Если была посещена, то пропускаем.
				keep = tmp->edge;
			tmp->edge = tmp->edge->next;
		}
		while (tmp->edge) // ищём нами найденное наименьшее ребро
		{
			if (tmp->edge == keep)
				break;
			tmp->edge = tmp->edge->next;
		}
		if (tmp->edge == keep) //если нашли, то берём от этого ребра следующую вершину.
		{
			tmp->edge->room->cost = tmp->edge->cost; // перед тем как пройти по этому пути,
			//устанавливаем ту стоимость, которая сохранена в ребре, в комнату, куда она направила.
			tmp = tmp->edge->room; // и переходим в эту новую вершину.
		}
		tmp->visit = -1;
		way->rooms = tmp;
		way->rooms = way->rooms->next;
	}
	return (tmp_way);
}

/*
 ** At first setting to every room cost infinity
 ** Than to calculate cost of road to this room;
 */

void        ft_solution(t_struct *all)
{
	t_way   *way;
	t_room  *set_infinity;
	set_infinity = all->room;
	while (set_infinity != NULL)
	{
		if (!(set_infinity == all->end) || !(set_infinity == all->start))
			set_infinity->cost = INT_MAX;
		set_infinity = set_infinity->next;
	}
	way = ft_dijkstra(all);
}