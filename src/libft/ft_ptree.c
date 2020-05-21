/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:56:21 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 20:55:43 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ft_ptree.h>

t_ptree			*new_tree(void)
{
	return ((t_ptree *)ft_memalloc(sizeof(t_ptree)));
}

/*
** Return nonzero on success
** Remove old entry properly if needed
** Value should be freeable
*/

int				insert_value(t_ptree *tree, char *key, void *value)
{
	if ((!tree && !(tree = new_tree())) || !key)
		return (key ? ft_putendl_fd("Could not allocate memory", 2) : 0);
	while (*key)
	{
		if (!tree->child[(int)*key])
		{
			if (!(tree->child[(int)*key] = new_tree()))
			{
				ft_putendl_fd("Could not allocate memory", 2);
				return (0);
			}
		}
		tree = tree->child[(int)*key];
		key++;
	}
	if (tree->value)
		free(tree->value);
	tree->value = value;
	return (1);
}

void			*search_key(t_ptree *tree, char *key)
{
	if (!tree || !key)
		return (NULL);
	while (*key)
	{
		if (!tree->child[(int)*key])
			return (NULL);
		tree = tree->child[(int)*key];
		key++;
	}
	return (tree->value);
}

void			del_key(t_ptree *tree, char *key)
{
	if (!tree || !key)
		return ;
	while (*key)
	{
		if (!tree->child[(int)*key])
			return ;
		tree = tree->child[(int)*key];
		key++;
	}
	free(tree->value);
	tree->value = NULL;
	return ;
}

void			del_tree(t_ptree *tree)
{
	int	i;

	i = 0;
	if (!tree)
		return ;
	while (i < N_CHILDREN)
		del_tree(tree->child[i++]);
	if (tree->value)
		free(tree->value);
	ft_memdel((void *)&tree);
}
