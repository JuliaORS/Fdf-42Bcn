/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:35:24 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 11:03:34 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//MOUSE
# define MOUSE_ZOOM_IN	4
# define MOUSE_ZOOM_OUT	5

//KEYS
# define ESC	53
# define UP		125
# define DOWN	126
# define RIGHT	124
# define LEFT	123
# define CTRL	256
# define TAB	48
# define KEY_W	13
# define KEY_S	1
# define KEY_Q	12
# define KEY_A	0

//COLORS
# define MAGENTA	0xFF00FF
# define CYAN		0x00FFFF
# define YELLOW		0xFFF700
# define BLUED		0x00B2FF
# define GREEND		0x01EA67
# define PINK		0xFF00E0
# define BLUE		0x00BDFE
# define GREEN 		0xA2FE00 
# define ORANGE		0xFFF700
# define RED		0xFFF0000

# define PI 3.141592

typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
	int		h;
}	t_pos;

typedef struct s_color {
	int	min;
	int	max;
}	t_color;

typedef struct s_mlx_win {
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		wind_x;
	int		wind_y;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_mlx_win;

typedef struct s_map
{
	int				rows;
	int				cols;
	char			*strfile;
	t_pos			**mat;
	t_mlx_win		wind;	
	float			scale;
	float			scalez;
	int				separator;
	float			z_sep;
	float			z_mod;
	int				origin_x;
	int				origin_y;
	float			ang_x;
	float			ang_y;
	float			ang_z;
	float			max_scale;
	float			min_scale;
	float			min_z;
	float			max_z;
	int				mov_x;
	int				mov_y;
	t_color			color[5];
	int				col_pair;
	int				view;
}	t_map;

#endif
