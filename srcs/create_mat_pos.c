/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mat_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:53:05 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 11:01:13 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_set_separation(t_map *map)
{
	int	i;
	int	j;

	ft_calcuate_separation(map);
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			map->mat[j][i].x = i * map->separator * map->scale;
			map->mat[j][i].y = j * map->separator * map->scale;
			map->mat[j][i].z = map->mat[j][i].h * (map->z_sep + map->z_mod) \
				* map->scale;
			i++;
		}
		j++;
	}
}

void	ft_rot_z(t_map *map)
{
	int		i;
	int		j;
	double	x;
	double	y;

	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			x = map->mat[j][i].x;
			y = map->mat[j][i].y;
			map->mat[j][i].x = \
				(x * cos(map->ang_z)) - (y * sin(map->ang_z));
			map->mat[j][i].y = \
				(x * sin(map->ang_z)) + (y * cos(map->ang_z));
			i++;
		}
		j++;
	}
}

void	ft_rot_x(t_map *map)
{
	int		i;
	int		j;
	double	y;
	double	z;

	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			y = map->mat[j][i].y;
			z = map->mat[j][i].z;
			map->mat[j][i].y = (y * cos(map->ang_x)) - \
				(z * sin(map->ang_x));
			map->mat[j][i].z = (y * sin(map->ang_x)) + \
				(z * cos(map->ang_x));
			i++;
		}
		j++;
	}
}

void	ft_set_origin(t_map *map)
{
	int	i;
	int	j;

	map->origin_y = 540 - ((map->mat[map->rows - 1][map->cols - 1].y \
		- map->mat[0][0].y) / 2) + map->mov_y;
	map->origin_x = map->wind.wind_x / 2 + map->mov_x;
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			map->mat[j][i].x = \
				(map->mat[j][i].x + map->origin_x);
			map->mat[j][i].y = \
				(map->mat[j][i].y + map->origin_y);
			i++;
		}
		j++;
	}
}

void	ft_create_mat_pos(t_map *map)
{
	ft_set_separation(map);
	ft_rot_z(map);
	ft_rot_x(map);
	ft_set_origin(map);
}
