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
 * Здесь высчитывается арифметикой следует ли запускать муравья по настоящему пути.
 * Если кол-во муравьёв больше чем вершин в настоящем пути, то по нему
 * запускается новый муравей.
 * И выходит.
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

/*
 * Пришедший путь мы берём в copyWay и запускаем его в цикле.
 * Если в пути это последняя комната, то мы в финише, соот-но просто выходим.
 * А если это предпоследняя комната, то обнуляем предпоследнюю комнату и увеличиваем
 * кол-во муравьёв в последней комнате на единицу. А дальше обновляет голову пути, чтобы ещё продвинуть
 * муравьёв по настоящему пути.
 * Если в настоящей комнате есть муравей, а в следующем нет, то передвигает муравья и выходит из цикла.
 * В ином случае дальше идёт по комнатам.
 * Когда заканчивает передвижения, то приступает к запуску новых муравьёв по сдедующему пути.
 */

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

// FIXME В valid/vs/1.map заходит в бесконечный цикл, т.к. вершина №1 используется два раза.

t_ways *check_ant_in_way(t_ways *ways, t_struct *all)
{
	t_ways 	*head;
	t_way	*way;
	int 	i;

	i = 0;
	way = ways->way;
	while (way)
	{
		if (way->room == all->end)
			break;
		i = way->room->ant;
		way = way->next;
	}
	if (i == 0)
		ways = ways->next;
	return (ways);
}

/*
 * Копируются кол-во муравьёв в antsRemain, чтобы вычитать за каждый ушедший муравей.
 * antsCurrent это номер определённого муравья, который пускается в старт.
 * В expression высчитывается арифметикой необходимость подключения нового пути для передвижения.
 * Далее в цикле пока все муравьи не достигли конца, мы новом цикле проходимся по всем путям.
 * А когда пути заканчиваются, то обновляем голову лситов путей.
 */

/*
 *
 */

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
	//printRecordWay(head);
	while (all->end->ant != all->ant)
	{
		while (copyWays)
		{
			walking_ants(copyWays, &antsRemain, &antsCurrent, all);
			copyWays = copyWays->next;
		}
		ft_printf("\n");
		copyWays = head;
//		head = check_ant_in_way(head, all);
	}
}