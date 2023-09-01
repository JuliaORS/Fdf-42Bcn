/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:49:22 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 13:07:17 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	int	*img;

	img = (int *)map->wind.addr;
	if (x >= 0 && x < map->wind.wind_x && y >= 0 && y < map->wind.wind_y)
		img[x + map->wind.wind_x * y] = color;
}

static int	add_color(t_map *map, float z)
{
	int		red;
	int		green;
	int		blue;
	float	ratio;

	if (map->min_z == map->max_z)
		ratio = 1;
	else
	{
		if (z >= 0)
			ratio = z / map->max_z;
		else
			ratio = z / map->min_z;
	}
	red = ((map->color[map->col_pair].max >> 16) & 0xFF) * ratio \
		+ ((map->color[map->col_pair].min >> 16) & 0xFF) * (1 - ratio);
	green = ((map->color[map->col_pair].max >> 8) & 0xFF) * ratio \
		+ ((map->color[map->col_pair].min >> 8) & 0xFF) * (1 - ratio);
	blue = ((map->color[map->col_pair].max) & 0xFF) * ratio \
		+ ((map->color[map->col_pair].min) & 0xFF) * (1 - ratio);
	return ((red << 16) | (green << 8) | blue);
}

static void	ft_draw_line_y(t_map *map, int j, int i)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	pos_tmp;

	if (map->mat[j][i].y < map->mat[j - 1][i].y)
	{
		pos1 = map->mat[j - 1][i];
		pos2 = map->mat[j][i];
	}
	else
	{
		pos1 = map->mat[j][i];
		pos2 = map->mat[j - 1][i];
	}
	pos_tmp.y = pos2.y;
	while (pos_tmp.y <= pos1.y)
	{
		pos_tmp.x = ((pos_tmp.y - pos2.y) * (pos1.x - pos2.x) \
			/ (pos1.y - pos2.y)) + pos2.x;
		pos_tmp.z = ((pos_tmp.y - pos2.y) * (map->mat[j][i].h \
			- map->mat[j - 1][i].h) / (pos1.y - pos2.y)) + map->mat[j - 1][i].h;
		my_mlx_pixel_put(map, (int)pos_tmp.x, \
			(int)pos_tmp.y, add_color(map, pos_tmp.z));
		pos_tmp.y = pos_tmp.y + 0.5;
	}
}

static void	ft_draw_line_x(t_map *map, int j, int i)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	pos_tmp;

	if (map->mat[j][i].x < map->mat[j][i - 1].x)
	{
		pos1 = map->mat[j][i - 1];
		pos2 = map->mat[j][i];
	}
	else
	{
		pos1 = map->mat[j][i];
		pos2 = map->mat[j][i - 1];
	}
	pos_tmp.x = pos2.x;
	while (pos_tmp.x <= pos1.x)
	{
		pos_tmp.y = ((pos_tmp.x - pos2.x) * (pos1.y - pos2.y) \
			/ (pos1.x - pos2.x)) + pos2.y;
		pos_tmp.z = ((pos_tmp.x - pos2.x) * (map->mat[j][i].h \
			- map->mat[j][i - 1].h) / (pos1.x - pos2.x)) + map->mat[j][i - 1].h;
		my_mlx_pixel_put(map, (int)pos_tmp.x, \
			(int)pos_tmp.y, add_color(map, pos_tmp.z));
		pos_tmp.x = pos_tmp.x + 0.5;
	}
}

void	ft_draw(t_map *map)
{
	int	i;
	int	j;

	map->wind.img = mlx_new_image(map->wind.mlx, map->wind.wind_x, \
		map->wind.wind_y);
	map->wind.addr = mlx_get_data_addr(map->wind.img, \
		&map->wind.bits_per_pixel, &map->wind.line_lenght, &map->wind.endian);
	ft_create_mat_pos(map);
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			if (j != 0)
				ft_draw_line_y(map, j, i);
			if (i != 0)
				ft_draw_line_x(map, j, i);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(map->wind.mlx, map->wind.mlx_win, \
		map->wind.img, 0, 0);
}
