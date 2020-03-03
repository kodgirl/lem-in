/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:33:18 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:45 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int ac, char **av)
{
	t_room	room;
	int		visual;

	visual = 0;
	ft_bzero(&room, sizeof(t_room));
	while (ac >= 2 && !ft_strcmp(av[1], "-v"))
	{
		if (!ft_strcmp(av[1], "-v"))
			visual = 1;
		av++;
		ac--;
	}
	if (ac == 1)
		parser(ac, av, &room);
	return (0);
}
