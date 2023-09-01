/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:39:23 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 16:57:32 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_movements(int key, t_map *map)
{
	if (key == ESC)
		ft_close_window(map);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_mov_origin(key, map);
	else if (key == CTRL)
		ft_change_color(map);
	else if (key == TAB)
		ft_change_view(map);
	else if (key == KEY_W || key == KEY_S)
		ft_rotate_view(key, map);
	else if (key == KEY_Q || key == KEY_A)
		ft_mod_height(key, map);
	return (0);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->wind.mlx, map->wind.mlx_win);
	exit (0);
	return (0);
}

int	ft_mouse_zoom(int scroll, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (scroll == MOUSE_ZOOM_IN && map->scale < map->max_scale)
		map->scale *= 2;
	else if (scroll == MOUSE_ZOOM_OUT && map->scale > map->min_scale)
		map->scale /= 2;
	ft_draw(map); 
	return (0);
}

void	ft_window(t_map *map)
{
	map->wind.mlx = mlx_init();
	map->wind.mlx_win = mlx_new_window(map->wind.mlx, \
		map->wind.wind_x, map->wind.wind_y, "FDF");
	ft_draw(map);
	mlx_hook(map->wind.mlx_win, 2, 1L << 0, ft_movements, map);
	mlx_hook(map->wind.mlx_win, 17, 1L << 5, ft_close_window, map);
	mlx_mouse_hook(map->wind.mlx_win, ft_mouse_zoom, map);
	mlx_loop(map->wind.mlx);
}
