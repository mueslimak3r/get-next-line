/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/09 21:13:32 by calamber         ###   ########.fr       */
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
				swap2 = ft_memalloc(BUFF_SIZE + 1);
				swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - n), (n + 1));
				free(files[fd]);
				files[fd] = ft_memalloc(BUFF_SIZE + 1);
				files[fd] = ft_strncpy(files[fd], swap2, (BUFF_SIZE - n));
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
			swap2 = ft_memalloc(BUFF_SIZE + 1);
			swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - n), (n + 1));
			free(files[fd]);
			files[fd] = ft_memalloc(BUFF_SIZE + 1);
			files[fd] = ft_strncpy(files[fd], swap2, (BUFF_SIZE - (n + 1)));
			free(swap2);
			return (1);
		}
	}
	return (0);
}
