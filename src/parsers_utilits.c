# include "../includes/lem_in.h"

/*
** changing from char to int and record ants;
*/

void	read_ant(char *line, t_struct *all)
{
	all->ant = f_atoi(line, &all->error);
}

/*
** Validating format of rooms;
*/

char	**is_room(char *line)
{
	char	**str;

	str = ft_strsplit(line, ' ');
	if (array_len(str) != 3 || *line == '#')
	{
		ft_free_split(str);
		return (NULL);
	}
	return (str);
}

char	**is_link(char *line)
{
	char	**str;

	str = ft_strsplit(line, '-');
	if (array_len(str) != 2)
	{
		ft_free_split(str);
		return (NULL);
	}
	return (str);
}

/*
** Checking comments of start and end
** which indicating with two sharps (##);
*/

int		is_door(char *line)
{
	if (line && *line == '#' && ft_strcmp(line, "#start") == 0)
		return (1);
	if (line && *line == '#' && ft_strcmp(line, "#end") == 0)
		return (2);
	return (0);
}