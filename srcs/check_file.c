/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:49:14 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/08 16:56:36 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_num_cols(char *line)
{
	int	i;
	int	cols;

	i = 0;
	cols = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		cols++;
	}
	return (cols);
}

static int	ft_check_lines(int fd, t_map *map)
{
	char	*line;
	int		numlastcols;

	while (fd) 
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->strfile = ft_strjoingnl(map->strfile, line);
		if (map->cols == 0)
			numlastcols = ft_num_cols(line);
		map->cols = ft_num_cols(line);
		if (map->cols != numlastcols)
		{
			free(line);
			free(map->strfile);
			write (1, "Invalid .fdf file", 17);
			return (-1);
		}
		numlastcols = map->cols;
		free(line);
		map->rows++;
	}
	free(line);
	return (0);
}

int	ft_check_file(char *filefdf, t_map *map)
{
	int		fd;

	fd = open(filefdf, O_RDONLY);
	if (fd == -1)
	{
		write (1, "Error: File is invalid", 22);
		return (-1);
	}
	if (ft_check_lines(fd, map) == -1)
		return (-1);
	else
	{
		if (!map->strfile)
		{
			write (1, "Invalid .fdf file", 17);
			return (-1);
		}
	}
	if (ft_save_file(map) == -1)
		return (-1);
	close (fd);
	return (0);
}
