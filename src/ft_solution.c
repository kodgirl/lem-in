 #include "../includes/lem_in.h"

/*
 * Annualing visited vertexes as bfs could to go back else.
 */

void        annual_visit_vertex(t_struct *all, t_room *tmpRoom)
{
     tmpRoom = all->room;
     while (tmpRoom)
     {
         tmpRoom->visit = 0;
         tmpRoom = tmpRoom->next;
     }
}

/*
 * Calculating long of the way;
 */

int 	calc_way(t_way *way)
{
	int 	i;

	i = 0;
	while (way)
	{
		i++;
		way = way->next;
	}
	return (i);
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

/*
* Sorting all the found ways depending on the number of rooms in the way.
*/

t_ways 	*sort(t_ways *self, int tmp_vtx_qn, t_way *tmp_way, t_ways *head)
{
	head = self->next;
	free(self);
	self = head;
	while (self && self->next) {
		if (self->vtx_qn > self->next->vtx_qn) {
			tmp_way = self->way;
			tmp_vtx_qn = self->vtx_qn;
			self->way = self->next->way;
			self->vtx_qn = self->next->vtx_qn;
			self->next->way = tmp_way;
			self->next->vtx_qn = tmp_vtx_qn;
		}
		self = self->next;
	}
	self = head;
	return (head);
}

t_way 		**way_to_array(t_way *way, int len)
{
	t_way	**res;
	int 	i;

	i = 0;
	res = (t_way *)malloc(sizeof(t_way) * (len + 1));
	while (way)
	{
		res[i] = way;
		way = way->next;
		i++;
	}
	return(res);
}

t_ways		**to_array(t_ways *head, int len)
{
	 t_ways *tmp;
	 t_ways **arr_wayS;
	 int 	i;

	 i = 0;
	 tmp = head;
	 arr_wayS = (t_ways *)malloc(sizeof(t_ways) * (len + 1));
	 tmp = head;
	 while (tmp)
	 {
		 arr_wayS[i] = way_to_array(tmp->way, tmp->vtx_qn);
		 tmp = tmp->next;
		 i++;
	 }
	 return (arr_wayS);
}

/*
 * FIXME не работает с картами из /home/dpenney/Desktop/lem-in/maps/valid/difficult/
 * FIXME добавить случай, когда не нашёл ни один из путей. Что должен выводить?
 * TODO запуск всех муравьёв по всем путям.
 * ways_qn - количество вершин в одном пути.
 * В этой функции запускается bfs запускается для поиска всех путей
 * Записываются все найденные пути в переменную wayS.
 * Внутри очищаются annual_visit_vertex, чтобы можно было запустить bfs ещё раз.
 * Далее всё сортируется в sort.
 * Отправляется всё в gen_cycle, где самое решение
*/

int       ft_solution(t_struct *all, t_way *way, t_ways *wayS, t_ways *head_wayS) {

	int		ways_qn;
//	t_ways 	**arr;

	wayS = ft_memalloc(sizeof(t_ways));
	head_wayS = wayS;
	wayS->vtx_qn = 0;
	ways_qn = 0;
	while ((way = bfs(all, NULL, NULL, NULL)) != NULL)
	{
		if (!(wayS->next = (t_ways *) malloc(sizeof(t_ways))))
			exit(-1);
		if (!way)
			return (1); // TODO вот здесь должен быть вызов ошибки.
		ft_bzero(wayS->next, sizeof(t_ways));
		wayS = wayS->next;
		wayS->way = way;
		wayS->vtx_qn = calc_way(way);
		annual_visit_vertex(all, NULL);
		ways_qn++;
	}
	head_wayS = sort(head_wayS, 0, NULL, NULL);
//	arr = to_array(head_wayS, ways_qn);
	gen_cycle(head_wayS, all);
	return (0);
}

// int       ft_solution(t_struct *all, t_way *way, t_ways *wayS, t_ways *head_wayS) {
//
//	 int		ways_qn;
//
//	 wayS = ft_memalloc(sizeof(t_ways));
//	 head_wayS = wayS;
//	 wayS->vtx_qn = 0;
//	 ways_qn = 0;
//	 while ((way = bfs(all, NULL, NULL, NULL)) != NULL)
//	 {
//		 if (!(wayS->next = (t_ways *) malloc(sizeof(t_ways))))
//			 exit(-1);
//		 if (!way)
//			 return (1);
//		 ft_bzero(wayS->next, sizeof(t_ways));
//		 wayS = wayS->next;
//		 wayS->way = way;
//		 wayS->vtx_qn = calc_way(way);
//		 annual_visit_vertex(all, NULL);
//		 ways_qn++;
//	 }
//	 head_wayS = sort(head_wayS, 0, NULL, NULL);
//	 gen_cycle(head_wayS, all);
//	 return (0);
// }