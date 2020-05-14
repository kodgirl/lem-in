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

void		walking_ants(t_way *way, int ants_ostatok, int ants_current)
{
	int 	last;
	if (way)
}

void		gen_cycle(t_ways *head, t_struct *all)
{
	int 	ants_ostatok;
	int 	ants_current;
	t_ways 	*tmpWays;

	tmpWays = head;
	all->start->ant = all->ant;
	expression(head);
	ants_current = 1;
	ants_ostatok = all->ant;
	while (all->end->ant != all->ant)
	{
		while (tmpWays)
		{
			walking_ants(tmpWays->way, &ants_ostatok, &ants_current);
		}
		tmpWays = head;
	}

}
