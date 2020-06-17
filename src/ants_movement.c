#include "../includes/lem_in.h"

/*
 * Goal of function is to implement calc of the decision
 * put next ant to new memory or no.
 * Therefore program expressing values to every way.
 * If count of ants > than (count of the way - count of the last room)
 * program add new ant to new way. Else spend all ants via one way.
 * https://medium.com/@jamierobertdawson/lem-in-finding-all-the-paths-and-deciding-which-are-worth-it-2503dffb893
 * Up link is about calc in details.
 */

void 		ways_expressions(t_ways *ways, t_struct *all)
{
	int 	k;
	int		i;
	t_ways	*read_ways;

	read_ways = ways;
	k = 0;
	i = 0;
	while (read_ways)
	{
		if (!read_ways->next)
			break;
		k += read_ways->rm_qn;
		if (i != 0)
			read_ways->next->calc = (read_ways->next->rm_qn * 2) - k;
		else
			read_ways->next->calc = read_ways->next->rm_qn - k;
		read_ways = read_ways->next;
		i++;
	}
}

void	two_rooms_to_movement(t_ways *current_way, unsigned *current_ant, unsigned *remain_ants)
{
	ft_printf("L%d-%s ", *current_ant, current_way->way_in_arr[1]->name);
	current_way->way_in_arr[1]->ant += 1;
	*current_ant += 1;
	*remain_ants -= 1;
}

/*
 * Array ending with 0, finish room in position -1, start room
 * begin with 0.
 */
void	move_to_finish_room(t_ways *current_way)
{
	ft_printf("L%d-%s ", current_way->way_in_arr[current_way->rm_qn - 2]->ant,
			  current_way->way_in_arr[current_way->rm_qn - 1]->name);
	current_way->way_in_arr[current_way->rm_qn - 1]->ant += 1;
	current_way->way_in_arr[current_way->rm_qn - 2]->ant = 0;
}

/*
 * Function checking from end to beginning.
 */

void	go_on_movement(t_ways *current_way)
{
	unsigned	back_runner;

	back_runner = current_way->rm_qn - 3;
	while (back_runner)
	{
		if (current_way->way_in_arr[back_runner]->ant)
		{
			ft_printf("L%d-%s ", current_way->way_in_arr[back_runner]->ant, current_way->way_in_arr[back_runner + 1]->name);
			current_way->way_in_arr[back_runner + 1]->ant = current_way->way_in_arr[back_runner]->ant;
			current_way->way_in_arr[back_runner]->ant = 0;
		}
		back_runner--;
	}
}

void 			laucnh_new_ant(t_ways *curr_way, unsigned *curr_ant, unsigned *remain_ants) {
	if (*remain_ants > curr_way->calc)
	{
		ft_printf("L%d-%s ", *curr_ant, curr_way->way_in_arr[1]->name);
		curr_way->way_in_arr[1]->ant = *curr_ant;
		*curr_ant += 1;
		*remain_ants -= 1;
	}
}
/*
** At first checking count of rooms in a way. If it's two
 * we should just increase in finish room and decrease in start room
 * without assignments to finish room and annual start rooms ants.
 * If proceed of finish room have ant - function
*/

void 	movement(t_ways *curr_way, unsigned *curr_ant, unsigned *remain_ants)
{
	if (*remain_ants > curr_way->calc && curr_way->rm_qn == 2)
		two_rooms_to_movement(curr_way, curr_ant, remain_ants);
	else
	{
		if (curr_way->way_in_arr[curr_way->rm_qn - 2]->ant)
			move_to_finish_room(curr_way);
		go_on_movement(curr_way);
		laucnh_new_ant(curr_way, curr_ant, remain_ants);
	}
}

void		ants_movement(t_ways *ways, t_struct *all)
{
	unsigned current_ant;
	unsigned remain_ants;
	t_ways	*ways_head;

	current_ant = 1;
	remain_ants = all->ant;
	ways_head = ways;
	ft_putchar('\n');
	while (all->ant != all->end->ant)
	{
		while (ways && ways->next)
		{
			movement(ways, &current_ant, &remain_ants);
			ways = ways->next;
		}
		ft_putchar('\n');
		ways = ways_head;
	}
}
