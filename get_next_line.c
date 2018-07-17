/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/17 14:10:05 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	gnewline(const int fd, char **files)
{
	files[fd] = ft_memalloc(BUFF_SIZE + 1);
	read(fd, files[fd], BUFF_SIZE);
	return ;
}

int			strchr_int(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char		*strsubcpy(char *dst, const char *src, int len, int start)
{
	char	*pointer;

	pointer = dst;
	while (start-- > 0)
		src++;
	while (len > 0 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0 && *dst != '\0')
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (pointer);
}

int		get_next_line(const int fd, char **line)
{
	static char		*files[4864];
	char			*swap2;
	int				n;

	if (files[fd])
	{
		if (*line)
		{
			free(*line);
			n = strchr_int(files[fd], 10);
			if (n >= 0)
			{
				*line = ft_memalloc(n + 1);
				*line = ft_strncpy(*line, files[fd], n);
				swap2 = ft_memalloc(ft_strlen(files[fd]) - (n + 1));
				swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - n), (n + 1));
				free(files[fd]);
				files[fd] = ft_memalloc(ft_strlen(swap2));
				files[fd] = ft_strncpy(files[fd], swap2, (ft_strlen(swap2)));
				free(swap2);
				return (1);
			}
			if (sizeof(files[fd]) == 0)
				return (0);
		}
	}
	else
	{
		gnewline(fd, files);
		n = strchr_int(files[fd], 10);
		if (n >= 0)
		{

			*line = ft_memalloc(n + 1);
			*line = ft_strncpy(*line, files[fd], n);
			swap2 = ft_memalloc(ft_strlen(files[fd]) - n + 1);
			swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - n), (n + 1));
			free(files[fd]);
			files[fd] = ft_memalloc(ft_strlen(ft_strlen) - n + 1);
			files[fd] = ft_strncpy(files[fd], swap2, (ft_strlen(swap2)));
			free(swap2);
			return (1);
		}
		else
		{
			swap2 = ft_strccpy(swap2, files[fd], 0, ft_strlen(files[fd]));
			free(files[fd]);
			gnewline(fd, files);
			n = strchr_int(files[fd], 10);
			if (n >= 0)
			{
				*line = ft_memalloc(n + ft_strlen(swap2) + 1);
				*line = ft_strncpy(*line, swap2, ft_strlen(swap2));
				*line = ft_strsubcpy(*line, files[fd], n + 1, ft_strlen(swap2));
				free(swap2);
			}
		}
	}
	return (0);
}
