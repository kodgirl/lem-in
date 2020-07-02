/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <dpenney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:20:23 by dpenney           #+#    #+#             */
/*   Updated: 2020/06/26 12:20:24 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Article about calculation than to launch new way;
** https://clck.ru/PG2Y6
** At this function taking for expression two ways length -
** current and next ways;
** Calculating length of next way with current way.
** cWay is current way and nWay is next way.
*/

static void			calc_ways(t_ways *ways, t_struct *all,
		int curr_len, int next_len)
{
	t_ways			*curr_way;
	t_ways			*next_way;

	curr_way = ways;
	next_way = ways->next;
	while (next_way)
	{
		curr_way = ways->next;
		curr_len = 0;
		next_len = 0;
		while (curr_way != next_way)
		{
			curr_len += curr_way->rm_qn;
			next_len += next_way->rm_qn;
			curr_way = curr_way->next;
		}
		next_way->calc = next_len - curr_len;
		next_way = next_way->next;
	}
}

void				free_void_list(t_ways *all_ways)
{
	t_ways			*runner;
	t_ways			*tmp;

	runner = all_ways;
	while (runner)
	{
		if (runner->way == NULL)
		{
			free(runner);
			tmp->next = NULL;
			break ;
		}
		tmp = runner;
		runner = runner->next;
	}
}

int					start_actions(t_struct *all)
{
	t_ways			*ways;

	ways = NULL;
	if (ways = record_ways(all, NULL, NULL, NULL))
	{
		free_void_list(ways);
		calc_ways(ways, all, 0, 0);
		ants_movement(ways, all);
	}
	//free_lem_in2(all, ways);
	exit(0);
}

void				ants_movement(t_ways *ways, t_struct *all)
{
	unsigned		current_ant;
	unsigned		remain_ants;
	t_ways			*ways_head;

	current_ant = 1;
	remain_ants = all->ant;
	ways_head = ways;
	ft_putchar('\n');
	while (all->ant != all->end->ant)
	{
		while (ways)
		{
			movement(ways, &current_ant, &remain_ants);
			ways = ways->next;
		}
		ft_putchar('\n');
		ways = ways_head;
	}
}
