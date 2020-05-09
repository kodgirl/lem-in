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
	printf("\nRecorder way\n");
	while (head_wayS) {
		while (head_wayS->way) {
			printf("%s->", head_wayS->way->room->name);
			head_wayS->way = head_wayS->way->next;
		}
		printf("\tlong: %d", head_wayS->vtx_qn);
		printf("\n");
		head_wayS = head_wayS->next;
	}
	printf("\n");
}

t_ways 	*sort(t_ways *self)
{
	t_ways	*current;
	t_ways	*index;
	t_way	*temp;
	int 	*tmp_qn;
	t_way 	*keep_head;

	keep_head = self;
	current = self;
	index = NULL;

	if (!self)
		exit(1);
	else
		while (current)
		/*
		 * Проходим по всем путям, сохраненным
		 * Сравниваем индекс настоящего и следующего путей.
		 * Если настоящий больше следующего, то меняю их пути, но не цифры пока.
		 */
		{
			index = current->next;
			while (index != NULL && current)
			{
				if (current->vtx_qn > index->vtx_qn)
				{
					temp = current->way;
					current->way = index->way;
					index->way = temp;
					tmp_qn = current->vtx_qn;
					current->vtx_qn = index->vtx_qn;
					index->vtx_qn = tmp_qn;
				}
				index = index->next;
				current = current->next;
			}
		}
	self = keep_head;
	return (self);
}

void 		print_array(t_array *arr)
{
	int 	i, j = 0;
	t_ways 	*tmp;

	while (arr->wayS[i]->way)
	{
		j = 0;
		arr->wayS[i];
		printf("\n%s", tmp->way[j].room->name);
		i++;
	}
}

void		to_array(t_struct *all, t_ways *wayS, int ways_qn) {
	t_array arr;
	t_ways *source_ways;
	int i;
	int j;

	source_ways = wayS;
	i = 0;
	j = 0;
	arr.rooms = ft_memalloc(sizeof(t_room *) * 10);
	while (all->room)
	{
		arr.rooms[i] = all->room;
		i++;
	}
	while (arr.rooms[i])
	{
		printf("\n%s\n", arr.rooms[i]->name);
		i--;
	}
	print_array(&arr);
}

/*
** FIXME Создаёт лишнюю ветку в массиве для хранения пути в head_wayS;
 * FIXME не работает с картами из /home/dpenney/Desktop/lem-in/maps/valid/difficult/
 * FIXME добавить случай, когда не нашёл ни один из путей. Что должен выводить?
 * TODO отсортировать все пути согласно её длине.
 * ways_qn - количество вершин в одном пути.
*/

void       ft_solution(t_struct *all, t_way *way, t_ways *wayS, int *ways_qn, t_ways *head_wayS) {

	wayS = ft_memalloc(sizeof(t_ways));
	ft_bzero(wayS, sizeof(t_ways));
	head_wayS = wayS;
	wayS->vtx_qn = 0;
	while ((way = bfs(all, NULL, NULL)) != NULL) {
		annual_visit_vertex(all, NULL);
		wayS->way = way;
		wayS->vtx_qn = calc_way(way);
		if (!(wayS->next = (t_ways *) malloc(sizeof(t_ways))))
			exit(-1);
		ft_bzero(wayS->next, sizeof(t_ways));
		wayS = wayS->next;
		ways_qn++;
	}
	to_array(all, head_wayS, ways_qn);
}


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
 * Во вторым вершинам прошёлся, однако со вторых на третьи вершины не смог
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