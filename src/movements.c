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
 */

void			launch_new_way(t_way *startNewWay, int *antsRemain, int *antsCurrent, t_ways *wayS)
{
	if (*antsRemain > wayS->expression && !startNewWay->next->room->ant)
	{
		startNewWay->next->room->ant = *antsCurrent;
		ft_printf("L%d-%s ", *antsCurrent, startNewWay->next->room->name);
		*antsRemain = *antsRemain - 1;
		*antsCurrent = *antsCurrent + 1;
		return;
	}
}

void		walking_ants(t_ways *wayS, int *antsRemain, int *antsCurrent, t_struct *all)
{
	t_way		*copyWay;

	copyWay = wayS->way;
	while (copyWay)
	{
		if (copyWay->room == all->end)
			break;
		else if (copyWay->room->ant && copyWay->next->room == all->end)
		{
				ft_printf("L%d-%s ", copyWay->room->ant, copyWay->next->room->name);
				copyWay->next->room->ant++;
				copyWay->room->ant = 0;
				copyWay = wayS->way;
		}
		else if (copyWay->room->ant && !copyWay->next->room->ant)
		{
			copyWay->next->room->ant = copyWay->room->ant;
			copyWay->room->ant = 0;
			ft_printf("L%d-%s ", copyWay->next->room->ant, copyWay->next->room->name);
			break;
		}
		copyWay = copyWay->next;
	}
	copyWay = wayS->way;
	launch_new_way(copyWay, antsRemain, antsCurrent, wayS);
}

void		gen_cycle(t_ways *head, t_struct *all)
{
	t_ways 	*copyWays;

	int		antsCurrent;
	int 	antsRemain;

	antsRemain = all->ant;
	antsCurrent = 1;
	copyWays = head;
	expression(head);
	ft_printf("\n");
	while (all->end->ant != all->ant)
	{
		while (copyWays)
		{
			walking_ants(copyWays, &antsRemain, &antsCurrent, all);
			copyWays = copyWays->next;
		}
		ft_printf("\n");
		copyWays = head;
	}
}