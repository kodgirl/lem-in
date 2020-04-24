 #include "../includes/lem_in.h"
// # define INT_MAX 2147483647

 void        ft_solution(t_struct *all)
 {
	t_way   *way;
	t_way   ways[1000];
	unsigned int    i;

	i = 1000;
	ft_bzero(ways, sizeof(t_way));
	while (i)
    {
	    way = bfs(all);
	    if (way == NULL)
	        break;
	    i--;
    }
 }


// /*
// Суть алгоритма Дейкстры:
//  1. Приходит граф со всеми пременными.
//  2. В цикле ставим условием - по кол-ву вершин и пока есть эти верщины
//  3. Если достиг последней вершины, то сообщает об этом.
//  4. В ином случае из всех рёбер текущей вершины выбирает самое наименьшее
//  по стоимости ребро через сравнение в цикле и сохраняет наименьш. в переменной keep.
//  5. Находим это ребро keep в настоящей вершине.
//  6. Каждая вершина, кроме старта, имеет стоимость бесконечности.
//  7. Перед проходом в новую вершину, мы сначала сложим стоимость настоящей вершины
//  и ребра, через которое проходим в новую вершину, в стоимость этой новой вершины.
//  8. Отмечаем настоящее ребро как посещенное, обозначив в переменной visit = 1.
//  9. Сохраняем настоящую вершину в last, чтобы далее сохранить как родителя следующей
//  вершины.
//  10. Переходим в новую вершину и устанавливаем в tmp->parent = last предыдущую вершину, откуда пришли.

//  Не работает установка родителя.
//  */

// t_way       *ft_dijkstra(t_struct *all)
// {
// 	t_room  *present;
// 	t_edge  *edge;
// 	int     count;
//
// 	present = all->room;
// 	edge = all->room->edge;
// 	count = 0;
// 	while (present)
// 	{
// 		while (present->edge)
// 		{
// 			if (present->edge > edge)
//
// 		}
// 	}
// }
//
// t_way       *ft_dijkstra(t_struct *all)
// {
// 	t_room  *tmp_rm;
// 	t_edge  *keep;
// 	int     cp_count;
// 	t_edge  *find_keep;
// 	t_room  *last;
//
// 	cp_count = all->rm_count + 2; // plus start and end rooms;
// 	tmp_rm = all->start; //than to start cycle
// 	all->start->parent = (t_room *)malloc(sizeof(t_room));
// 	ft_bzero(all->start->parent, sizeof(t_room));
// 	all->start->cost = 0;
// 	all->start->visit = 0; // всегда устанавливаем флаг, что в начальной вершине не были.
// 	all->end->visit = 0; // то же самое, чтобы дошёл до конечной вершины.
// 	keep = tmp_rm->edge;
//
// 	t_way   *head_w;
// 	t_way   *w;
// 	head_w = (t_way *)malloc(sizeof(w));
// 	head_w->room = tmp_rm;
// 	head_w->next = NULL;
// 	w = head_w;
// 	while (cp_count-- != 0 && tmp_rm)
// 	{
// 		if (tmp_rm == all->end)
// 		{
// 				printf("%s\n", tmp_rm->name);
// 				w->next = NULL;
// 		}
// 		find_keep = tmp_rm->edge;
// 		while (find_keep) // перебираем ребра и находим наименьшее
// 		{
// 			if (keep->cost >= find_keep->cost && find_keep->room->visit != -1)
// 				keep = find_keep;
// 			find_keep = find_keep->next;
// 		}
// 		while (tmp_rm->edge != keep && tmp_rm->edge) //ищём это ребро
// 			tmp_rm->edge = tmp_rm->edge->next;
// 		keep->room->cost = keep->cost + tmp_rm->cost; // перед тем как пройти по этому пути,
// 		//устанавливаем ту стоимость, которая сохранена в ребре, в комнату, куда она направила.
// 		tmp_rm->visit = -1;
// 		printf("%s-->", tmp_rm->name);
// 		last = tmp_rm;
// 		tmp_rm = keep->room; // и переходим в эту новую вершину.
// 		tmp_rm->parent = last;
// 		tmp_rm->parent = tmp_rm->parent->next;
// 		w->next = (t_way *)malloc(sizeof(t_way));
// 		w->room = tmp_rm;
// 		w = w->next;
// 	}
// 	return (head_w);
// }
//
// void    check_parent(t_way *way)
// {
// 	t_room  *tmp;
//
// 	tmp = way;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 	}
// 	printf("\nSexy\n");
// }
//
// /*
//  ** At first setting to every room cost infinity
//  ** Than to calculate cost of road to this room;
//  */
//
// void        ft_solution(t_struct *all)
// {
// 	t_room  *set_infinity;
// 	t_way   *way;
//
// 	set_infinity = all->room;
// 	while (set_infinity != NULL)
// 	{
// 		if (!(set_infinity == all->end) || !(set_infinity == all->start))
// 			set_infinity->cost = INT_MAX;
// 		set_infinity = set_infinity->next;
// 	}
// 	way = ft_dijkstra(all);
// 	check_parent(way);
// 	printf("Way added\n");
// }

