/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:59:34 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/03 18:47:40 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// void	del_links(t_link *link)
// {
// 	t_link	*tmp;

// 	while (link)
// 	{
// 		ft_strdel(&link->name1);
// 		ft_strdel(&link->name2);
// 		tmp = link->next;
// 		if (link)
// 			free(link);
// 		link = tmp;
// 	}
// }

void	del_double_massive(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&(str[i]));
		++i;
	}
	free(str);
}
