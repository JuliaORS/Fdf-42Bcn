/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mat_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:42:38 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 10:59:49 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_max_height(t_map *map)
{
	int	i;
	int	j;

	map->min_z = 0;
	map->max_z = 0;
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			if (map->mat[j][i].h >= 0)
			{
				if (map->mat[j][i].h >= map->max_z)
					map->max_z = map->mat[j][i].h;
			}
			else
			{
				if (map->mat[j][i].h < map->min_z)
					map->min_z = map->mat[j][i].h;
			}
			i++;
		}
		j++;
	}
}

void	ft_calcuate_separation(t_map *map)
{
	if (map->rows > 400 || map->cols > 400)
		map->separator = 2;
	else
		map->separator = 400 / map->rows;
	ft_max_height(map);
	if ((map->min_z != 0 && map->min_z >= -5) \
		|| (map->max_z != 0 && map->max_z <= 5))
		map->z_sep = 3;
	else if ((map->min_z != 0 && map->min_z >= -20) \
		|| (map->max_z != 0 && map->max_z <= 20))
		map->z_sep = 6;
	else
		map->z_sep = 0.2;
}
