//#include "../includes/lem_in.h"
//
//
///*
//** FIXME расставь правильно перенос строки, чтобы волны запуска путей печатались
//** отдельной строкой каждая соответственно.
//** From input getting way and launching the cycle of rooms of this way.
//** If it's last room - adding ant's by end.
//** If current room have ant and next room have not ant we are making sure that
//** current room is not start room. Because if it's start room - we should to decrise
//** ants quantity.
//** If it's not start room - we are put number of ant to the next room and printing.
//** Else if the current room is preceed to the room by end - we are annualing ant's number
//** in current room and increasing quantity in end room.
//** If current room have ant and next room have ant - we are moving to the next room.
//*/
//
//
//Добрый день, Светлана!
//Я один из студентов Школы.
//		Спасибо, что вы с нами и отдельное спасибо за организацию встреч)
//int 	move_ant(t_way *head_way, int i, t_struct *all)
//{
//	t_way 	*tmpW;
//
//	tmpW = head_way;
//	while (tmpW)
//	{
//		if (tmpW->room == all->end)
//		{
//			tmpW->room->ant++;
//			break;
//		}
//		if (tmpW->room->ant && !tmpW->next->room->ant)
//		{
//			if (tmpW->room != all->start)
//			{
//				tmpW->next->room->ant = tmpW->room->ant;
//				tmpW->room->ant = 0;
//				printf("L%d-%s  ", tmpW->next->room->ant, tmpW->next->room->name);
//				return (1);
//			}
//			else if (tmpW->room == all->start && tmpW->next->room->ant == 0)
//			{
//				tmpW->next->room->ant = i;
//				tmpW->room->ant = tmpW->room->ant - 1;
//				printf("L%d-%s  ", tmpW->next->room->ant, tmpW->next->room->name);
//				return (0);
//			}
//		}
//		else if (tmpW->room->ant && tmpW->next->room == all->end)
//		{
//			if (tmpW->room == all->start)
//				tmpW->room->ant--;
//			else
//				tmpW->room->ant = 0;
//			tmpW->next->room->ant++;
//			printf("L%d-%s ", tmpW->next->room->ant, tmpW->next->room->name);
//			return (1);
//		}
//		else
//		{
//			tmpW = tmpW->next;
//		}
//	}
//	write(1, "\n", 1);
//}
//
////void 	move_ants_copy(t_way *head_way, int i, t_struct *all)
////{
////	t_way 	*tmp;
////	while (tmp) {
////
////	}
////}
//
//void 	init_prev(t_ways  *head)
//{
//	t_ways		*tmp;
//	t_ways 		*keep;
//
//	tmp = head;
//	while (tmp)
//	{
//		if (tmp->next)
//			tmp->next->prev = tmp;
//		if (tmp->next)
//			break;
//		tmp = tmp->next;
//	}
//}
//
//void 	expression(t_ways *head)
//{
//	t_ways	*tmp;
//	int 	current;
//	int 	prev;
//
//	current = 0;
//	prev = 0;
//	tmp = head;
//	while (tmp)
//	{
//		if (!tmp->next)
//			break;
//		prev += tmp->vtx_qn - 1;
//		current += tmp->next - 1;
//		tmp->next->expression = current - prev;
//	}
//}
//
///*
// * Пока есть муравьи - прохожу по всем путям путём запуска цикла каждый раз сызнова для каждого отдельного пути.
// * Нельзя просто взять и сохранить указатель на последнюю вершину, пока я не знаю как это делать.
// * Поэтому каждый раз я буду проходить по всем вершинам. Если в этой вершине есть муравей, то буду двигать его вперёд.
// * Если эта вершина не имеет муравья, то пропускаю её.
// * Даст стар с первой вершины. Соотв-но, передаст во вторую вершину и тогда цикк прекратит дальше двигаться, выйдет из него, так как
// * передвинул. Дальше будет по следующему пути передвигать муравья. Уже второго муравья во вторую вершину и выйдет.
// * В следующий раз так же заново будет проходить. Так он проверит первую вершину, там всегда почти есть. Отлично,
// * проверим теперь следующую вершину. Если вершина Б пуста, то передвинет в Б. Иначе просто перейдет к вершине Б и передаст
// * на следующую вершину - вершину В. Если там нет муравьёв, то передвинет в В своего муравья и сам освободится.
// * Если
// */
//
///*
// * FIXME 1 линия за ход должна быть.
// * FIXME N движений за один ход.
// * TODO работаю над тем, чтобы использовать наименьшее кол-во путей для передвижения.
// * FIXME второй муравей не дошёл до конца, когда подаёшь два муравья
// */
//
//void 	gen_cycle(t_ways *head_wayS, t_struct *all)
//{
//	t_ways		*ways;
//	int 		i;
//	int 	j;
//
//	ways = head_wayS;
//	i = 1;
//	j = 0;
//	init_prev(head_wayS);
//	t_room 	*ann_ants = all->room;
//
//	all->start->ant = all->ant;
//	printf("\n");
////	expression(ways);
//	while (all->end->ant != all->ant)
//	{
//		j = move_ant(ways->way, i, all);
//		//TODO вот здесьс следует сделать вычисления. Если кол-во комнат настоящей вершины + кол-во меравьев в настоящей комнате > кол-ва вершин в следующей вершине, то переход к следующему пути.
//		//TODO и ещё можно добавлять указатель на заднюю вершину, чтоб если вышеназванное вычисление меньше, то идёт по прошлому пути.
//		if (ways->next)
//				ways = ways->next;
//		if (!ways->next)
//		{
//			ways = head_wayS;
//		}
//		i = i + 1 - j;
//		if (j)
//			printf("\n");
//	}
//}