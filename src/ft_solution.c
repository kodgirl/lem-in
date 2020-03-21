#include "../includes/lem_in.h"
# define INT_MAX 2147483647

/*
 * looking for smallest edge and saving
 * in variable keep;
 * After it
 */

void     *ft_dijkstra(t_struct *all)
{
	t_room  *tmp_rm;
	t_edge  *keep;
	int     cp_count;
	t_edge  *find_keep;
	t_room  *last;

	cp_count = all->rm_count + 2; // plus start and end rooms;
	tmp_rm = all->start; //than to start cycle

	all->start->parent = (t_room *)malloc(sizeof(t_room));
	ft_bzero(all->start->parent, sizeof(t_room));
	all->start->cost = 0;
	all->start->visit = 0; // всегда устанавливаем флаг, что в начальной вершине не были.
	all->end->visit = 0; // то же самое, чтобы дошёл до конечной вершины.
	keep = tmp_rm->edge;
	while (cp_count-- != 0 && tmp_rm != all->end)
	{
		if (tmp_rm == all->end)
			printf("SEXY!\n");
		find_keep = tmp_rm->edge;
		while (find_keep) // перебираем ребра и находим наименьшее
		{
			if (keep->cost >= find_keep->cost && find_keep->room->visit != -1)
				keep = find_keep;
			find_keep = find_keep->next;
		}

		while (tmp_rm->edge != keep && tmp_rm->edge) //ищём это ребро
			tmp_rm->edge = tmp_rm->edge->next;

		tmp_rm->edge->room->cost = keep->cost + tmp_rm->cost; // перед тем как пройти по этому пути,
		//устанавливаем ту стоимость, которая сохранена в ребре, в комнату, куда она направила.
		tmp_rm->visit = -1;
		last = tmp_rm;
		tmp_rm = keep->room; // и переходим в эту новую вершину.
		tmp_rm->parent = last;
		tmp_rm->parent = tmp_rm->parent->next;
	}
	// !!! Установи parent предыдущей вершины.
	// Не работает во второй раз.
}

/*
 ** At first setting to every room cost infinity
 ** Than to calculate cost of road to this room;
 */

void        ft_solution(t_struct *all)
{
	t_room  *set_infinity;
	set_infinity = all->room;
	while (set_infinity != NULL)
	{
		if (!(set_infinity == all->end) || !(set_infinity == all->start))
			set_infinity->cost = INT_MAX - 1;
		set_infinity = set_infinity->next;
	}
	ft_dijkstra(all);
	ft_dijkstra(all);
	printf("Way added\n");
}