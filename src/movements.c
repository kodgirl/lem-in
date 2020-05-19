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