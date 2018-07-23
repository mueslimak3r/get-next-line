/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/22 01:43:14 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int				strchr_int(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

int				read_and_combine(const int fd, char **files)
{
	char		*temp;
	char		*old;

	temp = ft_strdup(files[fd]);
	free(files[fd]);
	files[fd] = ft_memalloc(BUFF_SIZE + 1);
	if (read(fd, files[fd], BUFF_SIZE) == 0)
	{
		free(files[fd]);
		files[fd] = ft_strdup(temp);
		return (0);
	}
	old = ft_strjoin(temp, files[fd]);
	free(temp);
	free(files[fd]);
	files[fd] = ft_strdup(old);
	free(old);
	return (1);
}

int				takefrombuffer(const int fd, int n, char **files, char **line)
{
	char		*swap2;

	if (n >= 0)
	{
		*line = ft_memalloc(n + 1);
		*line = ft_strncpy(*line, files[fd], n);
		swap2 = ft_strsub(files[fd], n + 1, (ft_strlen(files[fd]) - n));
		free(files[fd]);
		files[fd] = ft_memalloc(ft_strlen(swap2) + 1);
		files[fd] = ft_strcpy(files[fd], swap2);
		free(swap2);
		return (1);
	}
	return (0);
}

int				firstread(const int fd, char **line, char **files)
{
	int			n;

	files[fd] = ft_memalloc(BUFF_SIZE + 1);
	read(fd, files[fd], BUFF_SIZE);
	n = strchr_int(files[fd], 10);
	if (n >= 0)
		return (takefrombuffer(fd, n, files, line));
	else
	{
		while (read_and_combine(fd, files) == 1)
		{
			n = strchr_int(files[fd], 10);
			if (takefrombuffer(fd, n, files, line) == 1)
				return (1);
		}
		if (read_and_combine(fd, files) == 0)
			return (ft_strlen(files[fd]) > 0 ?
					takefrombuffer(fd, ft_strlen(files[fd]), files, line) : 0);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*files[4864];
	int			n;

	if (files[fd])
	{
		n = strchr_int(files[fd], 10);
		if (takefrombuffer(fd, n, files, line) == 1)
			return (1);
		else
		{
			while (read_and_combine(fd, files) == 1)
			{
				n = strchr_int(files[fd], 10);
				if (takefrombuffer(fd, n, files, line) == 1)
					return (1);
			}
			if (read_and_combine(fd, files) == 0)
				if (ft_strlen(files[fd]) > 0)
					return (takefrombuffer(fd,
								ft_strlen(files[fd]), files, line));
		}
	}
	return (firstread(fd, line, files));
}
