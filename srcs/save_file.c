/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:02:41 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 10:59:01 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (-1);
}

static int	ft_fill_mat(t_map *map, char **linesplit)
{
	int		numrow;
	int		numcol;
	char	**str;

	numrow = 0;
	while (numrow < map->rows)
	{
		numcol = 0;
		map->mat[numrow] = malloc(sizeof(t_pos) * (map->cols));
		if (!map->mat[numrow])
			return (-1);
		str = ft_split(linesplit[numrow], ' ');
		while (numcol < map->cols)
		{
			if (ft_atoi(str[numcol]) > INT_MAX \
				|| ft_atoi(str[numcol]) < INT_MIN)
				return (ft_free_str(str));
			map->mat[numrow][numcol].h = ft_atoi(str[numcol]);
			numcol++;
		}
		ft_free_str(str);
		numrow++;
	}
	return (0);
}

int	ft_save_file(t_map *map)
{
	char	**linesplit;

	linesplit = ft_split(map->strfile, '\n');
	map->mat = malloc(sizeof(t_pos *) * (map->rows));
	if (!map->mat)
		return (-1);
	if (ft_fill_mat(map, linesplit) == -1)
	{
		ft_free_str(linesplit);
		return (-1);
	}
	ft_free_str(linesplit);
	return (0);
}
