/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:33:18 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 20:22:58 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int ac, char **av)
{
	t_struct	all;
	int			visual;

	visual = 0;
	ft_bzero(&all, sizeof(t_struct));
	while (ac >= 2 && !ft_strcmp(av[1], "-v"))
	{
		if (!ft_strcmp(av[1], "-v"))
			visual = 1;
		av++;
		ac--;
	}
	if (ac == 1)
	{
        parser(&all);
		bfs(&all);
    }
	free_lem_in(&all);
	return (0);
	//	ft_solution(&all);
}
