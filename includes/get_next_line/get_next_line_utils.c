/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:13:03 by julolle-          #+#    #+#             */
/*   Updated: 2023/08/02 14:56:49 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*str;
	int		lens1;
	int		lens2;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	lens1 = ft_strlen((const char *)s1);
	lens2 = ft_strlen((const char *)s2);
	str = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!str)
	{
		free (s1);
		return (NULL);
	}
	str = ft_strcpycat(s1, s2, str);
	free (s1);
	return (str);
}

char	*ft_strcpycat(char *s1, char *s2, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
