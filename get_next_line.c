/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/05 20:22:49 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *files[4096];
	char		*swap2;
	char		*swap3;
	int			n;

	if (line)
		free(line);
	if (!(files[fd]))
	{
		getline(fd, files);
		n = strchr_int(files[fd], 10);
		*line = ft_memalloc(n + 2);
		*line = ft_strncpy(*line, files[fd], n);
		swap2 = ft_memalloc(BUFF_SIZE + 1);
		swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - n), n);
		free(files[fd]);
		files[fd] = ft_strncpy(files[fd], swap2, (BUFF_SIZE - n));
		free(swap2);
		return (1);
	}
	else
	{
		if 
		else
		{
			swap2 = ft_strdup(files[fd]);
			free(files[fd];
			swap3 = getline(fd, files);
			line = ft_strjoin(swap2, swap3);
			free(swap2);
			free(swap3);
		}
	}
}

int	getline(const int fd, char **files)
{
	if (!(files[fd] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	files[fd][BUFF_SIZE + 1] = '\0';
	read(fd, files[fd], BUFF_SIZE);
	return (1);
}
