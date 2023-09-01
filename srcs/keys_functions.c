/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:09:44 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/04 18:16:30 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_change_color(t_map *map)
{
	if (map->col_pair < 4)
		map->col_pair++;
	else
		map->col_pair = 0;
	ft_draw(map);
}

void	ft_mov_origin(int key, t_map *map)
{
	if (key == UP)
	{
		if (map->mov_y < 700)
			map->mov_y += 50;
	}
	else if (key == DOWN)
	{
		if (map->mov_y > -700)
			map->mov_y -= 50;
	}
	if (key == RIGHT)
	{
		if (map->mov_x < 700)
			map->mov_x += 50;
	}
	else if (key == LEFT)
	{
		if (map->mov_x > -700)
			map->mov_x -= 50;
	}
	ft_draw(map);
}

void	ft_change_view(t_map *map)
{
	if (map->view < 2)
		map->view++;
	else
		map->view = 0;
	if (map->view == 0)
	{
		map->ang_x = 35 * PI / 180;
		map->ang_y = 45 * PI / 180;
		map->ang_z = 45 * PI / 180;
	}
	else if (map->view == 1)
	{
		map->ang_x = 0 * PI / 180;
		map->ang_y = 0 * PI / 180;
		map->ang_z = 0 * PI / 180;
	}
	else if (map->view == 2)
	{
		map->ang_x = 90 * PI / 180;
		map->ang_y = 0 * PI / 180;
		map->ang_z = 0 * PI / 180;
	}
	ft_draw(map);
}

void	ft_rotate_view(int key, t_map *map)
{
	if (key == KEY_W)
		map->ang_x = map->ang_x + 0.25;
	else if (key == KEY_S)
		map->ang_x = map->ang_x - 0.2;
	ft_draw(map);
}

void	ft_mod_height(int key, t_map *map)
{
	if (key == KEY_Q)
	{
		if (map->z_sep + map->z_mod < 200)
			map->z_mod += 0.5;
	}
	else if (key == KEY_A)
	{
		if (map->z_sep + map->z_mod > -200)
			map->z_mod -= 0.5;
	}
	ft_draw(map);
}
