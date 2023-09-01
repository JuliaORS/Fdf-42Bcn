/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:57:31 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 11:39:27 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "defines.h"
# include <math.h>
# include <limits.h>

//FDF FILE
int		ft_check_file(char *filefdf, t_map *map);
int		ft_save_file(t_map *map);

//WINDOW
void	ft_window(t_map *map);
int		ft_close_window(t_map *map);
int		ft_movements(int key, t_map *map);

//IMAGE
void	ft_create_mat_pos(t_map *map);
void	ft_calcuate_separation(t_map *map);
void	ft_draw(t_map *map);

//KEYS FUNCTIONS
void	ft_change_color(t_map *map);
void	ft_mov_origin(int key, t_map *map);
void	ft_change_view(t_map *map);
void	ft_rotate_view(int key, t_map *map);
void	ft_mod_height(int key, t_map *map);

#endif
