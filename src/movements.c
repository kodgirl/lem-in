#include "../includes/lem_in.h"

void 		expression(t_ways *head)
{
	int		k;
	t_ways 	*tmpWays;
	int 	i;

	k = 0;
	i = 0;
	tmpWays = head;
	while (tmpWays)
	{
		if (!tmpWays->next)
			break;
		k += tmpWays->vtx_qn;
		if (i != 0)
			tmpWays->next->expression = (tmpWays->next->vtx_qn * 2) - k;
		else
			tmpWays->next->expression = tmpWays->next->vtx_qn - k;
		tmpWays = tmpWays->next;
		i++;
	}
}

///*
// * Если это последняя комната, то просто добавляет
// * муравья в финишную комнату.
// */
//
////int 		check_preced_finish(t_room *room, t_room *end)
////{
////	if (room == end)
////	{
////		//room->ant++;
////		return (1);
////	}
////	return (0);
////}
//
///*
// * Если настоящая комната это стартовая, а следующая пуста, то
// * перекидываем отдельный номер нового муравья.
// * А если настоящая комната не стартовая, то просто передаём муравя от
// * одной комнаты в другую.
// */
//
//int		pass_the_ant(t_way *tmp, int *i, t_struct *all)
//{
//	if (tmp->room == all->start && tmp->next->room->ant == 0 \
//			&& tmp->next->room != all->end)
//	{
//		tmp->next->room->ant = *i;
//		tmp->room->ant--;
//		printf("L%d-%s ", tmp->next->room->ant, tmp->next->room->name);
//		return (0);
//	}
//	else if (tmp->room != all->start)
//	{
//		tmp->next->room->ant = tmp->room->ant;
//		tmp->room->ant = 0;
//		printf("L%d-%s ", tmp->next->room->ant, tmp->next->room->name);
//		*i--;
//	}
//}
//
///*
// * If current room is start room - we should decrease number of ants
// * but not pass all quantities to finish room.
// *
// */
//
//void	pass_of_preced_to_finish(t_way *tmp, t_struct *all)
//{
//	if (tmp->room == all->start)
//		tmp->room->ant--;
//	else
//		tmp->room->ant = 0;
//	tmp->next->room->ant++;
//	printf("L%d-%s ", tmp->next->room->ant, tmp->next->room->name);
//}

/*
 * Запускается в цикле один из путей.
 * Если это последняя комната, то выйти.
 * Если эта комната имеет муравья, а следующая последняя, то добавляет муравья в счётчик
 * последней комнаты.
 * Если в этой комнате есть муравей, а в следующей нет, то передаёт муравья и печатае.
 * Если по расчётам нужен ещё один путь, то запускает следующего муравья в начало этого пути.
 * FIXME файл testing. Когда доходит до операции с 3-ей строки, то
 */

int		walking_ants(t_ways *wayS, int *antsOstatok, int *antsCurrent, t_struct *all)
{
	t_way		*copyWay;
	t_way 		*startNewWay;

	startNewWay = wayS->way;
	copyWay = wayS->way;
	while (copyWay)
	{
		if (copyWay->room == all->end)
			break;
		else if (copyWay->room->ant && copyWay->next->room == all->end)
		{
			printf("L%d-%s ", copyWay->room->ant, copyWay->next->room->name);
			copyWay->next->room->ant++;
			copyWay->room->ant = 0;
			copyWay = startNewWay;
		}
		else if (copyWay->room->ant && !copyWay->next->room->ant)
		{
			copyWay->next->room->ant = copyWay->room->ant;
			copyWay->room->ant = 0;
			printf("L%d-%s ", copyWay->next->room->ant, copyWay->next->room->name);
			break;
		}
		copyWay = copyWay->next;
	}
	//FIXME sub.test. Когда приходит третий муравей, то он заменяет 2-ой муравей, который ещё не двигался.
	if (*antsOstatok > wayS->expression && !startNewWay->next->room->ant)
	{
		startNewWay->next->room->ant = *antsCurrent;
		printf("L%d-%s ", *antsCurrent, startNewWay->next->room->name);
		*antsOstatok = *antsOstatok - 1;
		*antsCurrent = *antsCurrent + 1;
		return (1);
	}
}

/*
 *  Функция проходит по очереди по каждому пути и отправляет муравьёв.
 */


void		gen_cycle(t_ways *head, t_struct *all)
{
	t_ways 	*copyWays;
	printf("\n");

	int		antsCurrent;
	int 	antsOstatok;
	int 	i;

	i = 0;

	antsOstatok = all->ant;
	antsCurrent = 1;
	copyWays = head;
	expression(head);
	while (all->end->ant != all->ant)
	{
		while (copyWays)
		{
			i = walking_ants(copyWays, &antsOstatok, &antsCurrent, all);
			copyWays = copyWays->next;
		}
		printf("\n");
		copyWays = head;
	}
}


// IT'S ONE OF VERSION
///*
// * Если расчёты expression меньше кол-ва муравьёв, то в этой же
// * функции передаём на новый путь муравья.
// * 1. Если это последняя комната, то просто выходим.
// * 2. Если есть муравей в настоящей и нет в следующей,
// * то отпр-ю в pass_the_ant, где скидывается на след. комнату.
// * 3. Если настоящая комната имеет муравья, а след. это финиш,
// * то отпр-ем в pass_of_preced_to_finish
// * 4. В ином случае передвигаемся по листам.
// */
//
//int		walking_ants(t_way *way, int *i, t_struct *all, t_ways *tmpWays)
//{
//	t_way 	*tmp;
//
//	tmp = way;
//	while (tmp)
//	{
//		if (tmp->room == all->end)
//			break; // FIXME может здесь вообще нужно просто возвр-ть 1?
//		else if (tmp->room->ant && tmp->next->room == all->end)
//		{
//			pass_of_preced_to_finish(tmp, all);
//			return (1);
//		}
//		else if (tmp->room->ant && tmp->next->room->ant == 0)
//		{
//			if (pass_the_ant(tmp, i, all))
//				return (1);
//			else
//			{
//				return (0);
//			}
//		}
//		else
//			tmp = tmp->next;
//	}
//}

//void		gen_cycle(t_ways *head, t_struct *all)
//{
//	t_ways 	*tmpWays;
//	int 	i;
//	int 	j;
//
//	j = 0;
//	i = 1;
//
//	printf("\n");
//
//	tmpWays = head;
//	all->start->ant = all->ant;
//	expression(head);
//	while (all->end->ant != all->ant)
//	{
//		while (all->end->ant != all->ant)
//		{
//			j = walking_ants(tmpWays->way, &i, all, tmpWays);
//			i = i + 1 - j;
//			if (tmpWays->next && all->start->ant > tmpWays->next->expression)
//			{
//				tmpWays->way->next->room->ant = i;
//				printf("L%d-%s ", tmpWays->way->next->room->ant, tmpWays->way->next->room->name);
//				printf("\n");
//				tmpWays = tmpWays->next;
//			}
//			else
//				tmpWays = head;
//		}
//	}
//
//}