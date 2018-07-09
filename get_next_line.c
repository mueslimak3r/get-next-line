/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/08 20:05:03 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	getline(const int fd, char **files)
{
	files[fd] = ft_memalloc(BUFF_SIZE + 1);
	read(fd, files[fd], BUFF_SIZE);
	return ;
}

int		get_next_line(const int fd, char **line)
{
	static char	*files[4096];
	char		*swap2;
	int		n;

	if (files[fd])
	{
		free(*line);
		n = strchr_int(files[fd], 10);
		if (n >= 0)
		{
			*line = ft_memalloc(n + 2);
			*line = ft_strncpy(*line, files[fd], n);
			swap2 = ft_memalloc(BUFF_SIZE + 1);
			swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - (n + 2)), n);
			free(files[fd]);
			files[fd] = ft_memalloc(BUFF_SIZE + 1);
			files[fd] = ft_strncpy(files[fd], swap2, (BUFF_SIZE - (n + 1)));
			free(swap2);
			return(1);
		}
	}
	else
	{
		getline(fd, files);
		n = strchr_int(files[fd], 10);
		*line = ft_memalloc(n + 2);
		*line = ft_strncpy(*line, files[fd], n);
		swap2 = ft_memalloc(BUFF_SIZE + 1);
		swap2 = strsubcpy(swap2, files[fd], (BUFF_SIZE - (n + 1)), n);
		free(files[fd]);
		files[fd] = ft_memalloc(BUFF_SIZE + 1);
		files[fd] = ft_strncpy(files[fd], swap2, (BUFF_SIZE - (n + 1)));
		free(swap2);
		return (1);
	}
	return (0);
}
