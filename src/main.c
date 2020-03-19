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

//	visual = 0;
//	while (ac >= 2 && !ft_strcmp(av[1], "-v"))
//	{
//		if (!ft_strcmp(av[1], "-v"))
//			visual = 1;
//		av++;
//		ac--;
//	}
	ft_bzero(&all, sizeof(t_struct));
	if (ac == 2) //ac == 2 if using to debug
	{
        parser(&all, &av[1]); //remove av[1] after debuging
//		ft_solution(&all);
		free_lem_in(&all);
        exit(0);
    }
	return (0);
}
