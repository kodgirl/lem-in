 #include "../includes/lem_in.h"

/*
** Annualing visited vertexes as bfs could to go back else.
*/
//
//void		annual_visit_vertex(t_struct *all, t_room *tmpRoom)
//{
//     tmpRoom = all->room;
//     while (tmpRoom)
//     {
//         tmpRoom->visit = 0;
//         tmpRoom = tmpRoom->next;
//     }
//}

/*
** Calculating long of the way;
*/

//int 	calc_way(t_way *way)
//{
//	int 	i;
//
//	i = 0;
//	while (way)
//	{
//		i++;
//		way = way->next;
//	}
//	return (i);
//}

/*
** Sorting all the found ways depending on the number of rooms in the way.
*/

//t_ways		*sort(t_ways *self, int tmp_vtx_qn, t_way *tmp_way, t_ways *head)
//{
//	head = self->next;
//	free(self);
//	self = head;
//	while (self && self->next) {
//		if (self->vtx_qn > self->next->vtx_qn) {
//			tmp_way = self->way;
//			tmp_vtx_qn = self->vtx_qn;
//			self->way = self->next->way;
//			self->vtx_qn = self->next->vtx_qn;
//			self->next->way = tmp_way;
//			self->next->vtx_qn = tmp_vtx_qn;
//		}
//		self = self->next;
//	}
//	self = head;
//	return (head);
//}

/*
 * FIXME не работает с картами из /home/dpenney/Desktop/lem-in/maps/valid/difficult/
 * FIXME добавить случай, когда не нашёл ни один из путей. Что должен выводить?
 * В этой функции запускается bfs запускается для поиска всех путей
 * Записываются все найденные пути в переменную wayS.
 * Внутри очищаются annual_visit_vertex, чтобы можно было запустить bfs ещё раз.
 * Далее всё сортируется в sort, где комнаты сортируются по кол-ву комнат в пути.
 * Отправляется всё в gen_cycle, где передвигаются муравьи.
*/

//int       ft_solution(t_struct *all, t_way *way, t_ways *wayS, t_ways *head_wayS) {
//	wayS = ft_memalloc(sizeof(t_ways));
//	head_wayS = wayS;
//	wayS->vtx_qn = 0;
//	while ((way = bfs(all, NULL, NULL, NULL)) != NULL)
//	{
//		if (!(wayS->next = (t_ways *) malloc(sizeof(t_ways))))
//			exit(-1);
//		if (!way)
//			return (1); // TODO вот здесь должен быть вызов ошибки.
//		ft_bzero(wayS->next, sizeof(t_ways));
//		wayS = wayS->next;
//		wayS->way = way;
//		wayS->vtx_qn = calc_way(way);
//		annual_visit_vertex(all, NULL);
//	}
//	head_wayS = sort(head_wayS, 0, NULL, NULL);
//	gen_cycle(head_wayS, all);
//	return (0);
//}
