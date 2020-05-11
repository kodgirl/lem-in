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
	//printRecordWay(self);
	return (head);
}

/*
 * FIXME не работает с картами из /home/dpenney/Desktop/lem-in/maps/valid/difficult/
 * FIXME добавить случай, когда не нашёл ни один из путей. Что должен выводить?
 * TODO запуск всех муравьёв по всем путям.
 * ways_qn - количество вершин в одном пути.
*/

int       ft_solution(t_struct *all, t_way *way, t_ways *wayS, t_ways *head_wayS) {

	int		ways_qn;

	wayS = ft_memalloc(sizeof(t_ways));
	head_wayS = wayS;
	wayS->vtx_qn = 0;
	ways_qn = 0;
	while ((way = bfs(all, NULL, NULL, NULL)) != NULL)
	{
		if (!(wayS->next = (t_ways *) malloc(sizeof(t_ways))))
			exit(-1);
		if (!way)
			return (1);
		ft_bzero(wayS->next, sizeof(t_ways));
		wayS = wayS->next;
		wayS->way = way;
		wayS->vtx_qn = calc_way(way);
		annual_visit_vertex(all, NULL);
		ways_qn++;
	}
	head_wayS = sort(head_wayS, 0, NULL, NULL);
	gen_cycle(head_wayS, all);
	return (0);
}

//	to_array(all, head_wayS, ways_qn);
//	gen_cycle(head_wayS);

/*
 * Записать все пути в листы
 */
// while ((way = bfs(all, NULL, NULL)) != NULL) {
// annual_visit_vertex(all, NULL);
// wayS->way = way;
// wayS->ways_qn = calc_way(way);
// if (!(wayS->next = (t_ways *) malloc(sizeof(t_ways))))
// exit(-1);
// ft_bzero(wayS->next, sizeof(t_ways));
// wayS = wayS->next;
// ways_qn++;
// }




/*
 * Хотел провести всех муравьёв сразу по всем путям, однако
 * как запомнить где остановился и двигать дальше всех муравьев?
 * По вторым вершинам прошёлся, однако со вторых на третьи вершины не смог
 * выдвинуть.
 */
// wayS = head_wayS;
//	way = wayS->way;
//	all->start->ant = all->ant;
//	int 	i = 1;
//	while (all->ant > i)
//	{
//		wayS = head_wayS;
//		while (wayS) {
//			way = wayS->way;
//			if (!wayS->way)
//				break;
//			move_ant(way, i, all);
//			way = way->next;
//			wayS = wayS->next;
//			i++;
//		}
//	}
//
//}
//
//void 	move_ant(t_way *way, int i, t_struct *all)
//{
//	if (way->room == all->end) {
//		all->end->ant++;
//		return ;
//	}
//	while (way->room == all->start || way->room->ant) {
//		way = way->next;
//	}
//	if (way->room != all->start) {
//			way->room->ant = 0;
//		}
//		way->next->room->ant = i;
//		printf("\nL%d-%s", i, way->next->room->name);