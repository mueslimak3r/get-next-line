/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/18 17:30:27 by calamber         ###   ########.fr       */
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

void	read_and_combine(const int fd, char **files)
{
	char	*swap2;
	char	*swap3;
	int		n;

	swap2 = ft_memalloc(ft_strlen(files[fd]));
	swap2 = ft_strcpy(swap2, files[fd]);
	free(files[fd]);
	gnewline(fd, files);
	n = strchr_int(files[fd], 10);
	swap3 = ft_memalloc(ft_strlen(swap2) + ft_strlen(files[fd]));
	swap3 = ft_strcpy(swap3, swap2);
	swap3 = strsubcpy(swap3, swap2, ft_strlen(swap2), (ft_strlen(swap2) + ft_strlen(files[fd])));
	free(swap2);
	free(files[fd]);
	files[fd] = ft_memalloc(ft_strlen(swap3));
	files[fd] = ft_strcpy(files[fd], swap3);
}

int		get_next_line(const int fd, char **line)
{
	static char		*files[4864];
	char			*swap2;
	int				n;

	if (files[fd])
	{
		if (*line)
			free(*line);	
		n = strchr_int(files[fd], 10);
		if (n >= 0)
		{
			*line = ft_memalloc(n);
			*line = ft_strncpy(*line, files[fd], n);
			swap2 = ft_memalloc(ft_strlen(files[fd]) - (n + 1));
			swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - n), (n + 1));
			free(files[fd]);		
			files[fd] = ft_memalloc(ft_strlen(swap2));
			files[fd] = ft_strncpy(files[fd], swap2, (ft_strlen(swap2)));
			free(swap2);
			return (1);
		}
		else
		{
			read_and_combine(fd, files);
			if (get_next_line(fd, line) == 1)
				return (1);
		}
	}
	else
	{
		gnewline(fd, files);
		n = strchr_int(files[fd], 10);
		if (n >= 0)
		{
			*line = ft_memalloc(n);
			*line = ft_strncpy(*line, files[fd], n);
			swap2 = ft_memalloc(ft_strlen(files[fd]) - n);
			swap2 = strsubcpy(swap2, files[fd], n, (ft_strlen(files[fd]) - n));
			free(files[fd]);
			files[fd] = ft_memalloc(ft_strlen(swap2));
			files[fd] = ft_strcpy(files[fd], swap2);
			free(swap2);
			return (1);
		}
		else
		{
			read_and_combine(fd, files);
			if (get_next_line(fd, line) == 1)
				return (1);
		}
	}
	return (0);
}
