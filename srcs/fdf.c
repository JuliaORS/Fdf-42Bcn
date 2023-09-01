/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:40:07 by julolle-          #+#    #+#             */
/*   Updated: 2023/07/24 12:40:07 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "Error: Invalid arguments", 24);
		return (-1);
	}
	if (ft_strchr(argv[1], '.') == 0)
	{
		write (1, "Error: File is invalid", 22);
		return (-1);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".fdf", 4) != 0)
	{
		write (1, "Error: File is invalid", 22);
		return (-1);
	}
	return (0);
}

static void	ft_define_colors(t_map *map)
{
	map->color[0].min = MAGENTA;
	map->color[0].max = CYAN;
	map->color[1].min = YELLOW;
	map->color[1].max = BLUED;
	map->color[2].min = GREEND;
	map->color[2].max = PINK;
	map->color[3].min = BLUE;
	map->color[3].max = GREEN;
	map->color[4].min = ORANGE;
	map->color[4].max = RED;
}

static void	ft_init_vars(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->strfile = NULL;
	map->wind.wind_x = 1920;
	map->wind.wind_y = 1080;
	map->ang_x = 35 * PI / 180;
	map->ang_y = 45 * PI / 180;
	map->ang_z = 45 * PI / 180;
	map->max_scale = 20.0;
	map->min_scale = 0.1;
	map->scale = 1;
	map->z_mod = 0;
	map->mov_y = 0;
	map->mov_x = 0;
	map->view = 0;
	map->col_pair = 0;
	ft_define_colors(map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (ft_check_args(argc, argv) == -1)
		return (0);
	ft_init_vars(&map);
	if (ft_check_file(argv[1], &map) == -1)
		return (0);
	ft_window(&map);
}
