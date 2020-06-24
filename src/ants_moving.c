#include "../includes/lem_in.h"

static void		two_rooms_to_movement(t_ways *current_way, unsigned *current_ant, unsigned *remain_ants)
{
	print_ants(*current_ant, current_way->way_in_arr[1]->name, 1);
	current_way->way_in_arr[1]->ant += 1;
	*current_ant += 1;
	*remain_ants -= 1;
}

/*
 * Array ending with 0, finish room in position -1, start room
 * begin with 0.
 */
static void		move_to_finish_room(t_ways *curr_way)
{
	print_ants(curr_way->way_in_arr[curr_way->rm_qn - 2]->ant,
			  curr_way->way_in_arr[curr_way->rm_qn - 1]->name, 1);
	curr_way->way_in_arr[curr_way->rm_qn - 1]->ant += 1;
	curr_way->way_in_arr[curr_way->rm_qn - 2]->ant = 0;
}

/*
 * Function checking from end to beginning.
 */

static void		go_on_movement(t_ways *current_way)
{
	unsigned	back_runner;

	back_runner = current_way->rm_qn - 3;
	while (back_runner)
	{
		if (current_way->way_in_arr[back_runner]->ant)
		{
			print_ants(current_way->way_in_arr[back_runner]->ant, current_way->way_in_arr[back_runner + 1]->name, 1);
			current_way->way_in_arr[back_runner + 1]->ant = current_way->way_in_arr[back_runner]->ant;
			current_way->way_in_arr[back_runner]->ant = 0;
		}
		back_runner--;
	}
}

static void		laucnh_new_ant(t_ways *curr_way, unsigned *curr_ant, unsigned *remain_ants) {
	if (*remain_ants > curr_way->calc)
	{
		print_ants(*curr_ant, curr_way->way_in_arr[1]->name, 1);
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

void		movement(t_ways *curr_way, unsigned *curr_ant, unsigned *remain_ants)
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

