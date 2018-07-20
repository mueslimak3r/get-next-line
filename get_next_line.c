/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/19 17:34:51 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	gnewline(const int fd, char **files)
{
	files[fd] = ft_memalloc(BUFF_SIZE + 1);
	if (read(fd, files[fd], BUFF_SIZE) == 0)
		return (0);
	return (1);
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

char		*strsubcpy(char *dst, const char *src, int len, int start, char c)
{
	char	*pointer;

	pointer = dst;
	if (c)
	{
	   if (c == 's')
		{
			while (start-- > 0)
				src++;
		}
		if (c == 'd')
		{
			while (start-- > 0)
				dst++;
		}
	}
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

	swap2 = ft_memalloc(ft_strlen(files[fd]) + 1);
	swap2 = ft_strcpy(swap2, files[fd]);
	free(files[fd]);
	gnewline(fd, files);
	swap3 = ft_memalloc(ft_strlen(swap2) + ft_strlen(files[fd]) + 1);
	swap3 = ft_strcpy(swap3, swap2);
	swap3 = strsubcpy(swap3, files[fd], (ft_strlen(swap2) + ft_strlen(files[fd])), ft_strlen(swap2), 'd');
	free(swap2);
	free(files[fd]);
	files[fd] = ft_memalloc(ft_strlen(swap3) + 1);
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
			*line = ft_memalloc(n + 1);
			*line = ft_strncpy(*line, files[fd], n);
			swap2 = ft_memalloc((ft_strlen(files[fd]) - n) + 1);
			swap2 = strsubcpy(swap2, files[fd], (ft_strlen(files[fd]) - n), n + 1, 's');
			free(files[fd]);		
			files[fd] = ft_memalloc(ft_strlen(swap2) + 1);
			files[fd] = ft_strcpy(files[fd], swap2);
			free(swap2);
			return (1);
		}
		else if (n < 0)
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
			*line = ft_memalloc(n + 1);
			*line = ft_strncpy(*line, files[fd], n);
			swap2 = ft_memalloc((ft_strlen(files[fd]) - n) + 1);
			swap2 = strsubcpy(swap2, files[fd], (ft_strlen(files[fd]) - n), n + 1, 's');
			free(files[fd]);
			files[fd] = ft_memalloc(ft_strlen(swap2) + 1);
			files[fd] = ft_strcpy(files[fd], swap2);
			free(swap2);
			return (1);
		}
		else
		{
			read_and_combine(fd, files);
			printf("filesfd: %s\n", files[fd]);
			if (get_next_line(fd, line) == 1)
				return (1);
		}
	}
	return (0);
}
