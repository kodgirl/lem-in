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

int		main(int ac, char **av)
{
	t_struct	all;
	int			visual;
	short 		i;

	i = 0;
	ft_bzero(&all, sizeof(t_struct));
	if (ac == 1)
	{
        parser(&all);
		i = ft_solution(&all, NULL, NULL, NULL);
		if (i)
			exit (1); // Распечатай ошибку и освободи всё.
        exit(0);
    }
	return (0);
}
