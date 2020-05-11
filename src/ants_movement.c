#include "../includes/lem_in.h"


/*
 * FIXME первый доходит до конца, а все остальные муравьи не доходят до конца.
 */
int 	move_ant(t_way *head_way, int i, t_struct *all)
{
	t_way 	*tmpW;

	tmpW = head_way;
	while (tmpW)
	{
		/*
		 * Если это последняя комната,
		 * то увеличиваем кол-во муравьёв в последней комнате и беремся
		 * за следующий путь.
		 */
		if (tmpW->room == all->end)
		{
			tmpW->room->ant++;
			break;
		}
		/*
		 * Если муравьи есть в настоящей комнате И
		 * Если нет муравьёв в следующей комнате
		 */
		if (tmpW->room->ant && !tmpW->next->room->ant)
		{
			/*
			 * Если настоящая комната стартовая, то
			 * значит, что следующая комната это комната из второй вершины.
			 * Соот-но пересылаем одного муравья со старта во вторую веришну.
			 * А стартовую уменьшаем на одну комнату.
			 */
			if (tmpW->room != all->start)
			{
				tmpW->next->room->ant = tmpW->room->ant;
				tmpW->room->ant = 0;
				printf("\nL%d - %s", tmpW->next->room->ant, tmpW->next->room->name);
				return (1);
			}
			/*
			 * FIXME на третьем пути, когда передаёт от А к Х, то не входит в эту структуру, пропускает, хотя в Х муравья 0.
			 */
			else if (tmpW->room == all->start && tmpW->room->next->ant == 0)
			{
				tmpW->next->room->ant = i;
				tmpW->room->ant = tmpW->room->ant - 1;
				printf("\nL%d - %s", tmpW->next->room->ant, tmpW->next->room->name);
				return (0);
			}
		}
		else if (tmpW->room->ant && tmpW->next->room == all->end)
		{
			tmpW->room->ant = 0;
			tmpW->next->room->ant++;
			printf("\nL%d - %s", tmpW->next->room->ant, tmpW->next->room->name);
			return (1);
		}
		else
		{
			tmpW = tmpW->next;
		}

	}
}

/*
 * Пока есть муравьи - прохожу по всем путям путём запуска цикла каждый раз сызнова для каждого отдельного пути.
 * Нельзя просто взять и сохранить указатель на последнюю вершину, пока я не знаю как это делать.
 * Поэтому каждый раз я буду проходить по всем вершинам. Если в этой вершине есть муравей, то буду двигать его вперёд.
 * Если эта вершина не имеет муравья, то пропускаю её.
 * Даст стар с первой вершины. Соотв-но, передаст во вторую вершину и тогда цикк прекратит дальше двигаться, выйдет из него, так как
 * передвинул. Дальше будет по следующему пути передвигать муравья. Уже второго муравья во вторую вершину и выйдет.
 * В следующий раз так же заново будет проходить. Так он проверит первую вершину, там всегда почти есть. Отлично,
 * проверим теперь следующую вершину. Если вершина Б пуста, то передвинет в Б. Иначе просто перейдет к вершине Б и передаст
 * на следующую вершину - вершину В. Если там нет муравьёв, то передвинет в В своего муравья и сам освободится.
 * Если
 */

void 	gen_cycle(t_ways *head_wayS, t_struct *all)
{
	t_ways		*ways;
	int 		i;
	t_way		*head;


	i = 1;
	ways = head_wayS;
//	while (all->ant)
//	{
//		move_ant(ways->way, i, all);
//		ways = ways->next;

//		i++;
	head = ways->way;
	i = 1;
	int 	j;
	j = 0;

	t_room 	*ann_ants = all->room;
	while (ann_ants)
	{
		ann_ants->ant = 0;
		ann_ants = ann_ants->next;
	}
	all->start->ant = all->ant;
	while (all->end->ant != all->ant)
	{
		j = move_ant(ways->way, i, all);
		ways->way = head;
//		ways = ways->next;
//		if (!ways)
//			ways = head_wayS;
		i = i + 1 - j;
	}
}