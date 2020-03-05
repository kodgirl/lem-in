/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:35:44 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/17 21:12:57 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if ((new->content = (void *)ft_memalloc(content_size)))
		{
			new->content = ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		else
			ft_memdel((void **)new);
	}
	return (new);
}
