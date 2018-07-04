/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2018/07/03 22:43:38 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *files[4096];
	char		swap[BUFF_SIZE + 1];
	char		*swap2;
	char		*swap3;

	if (line)
		free(line);
	if (!(buffer[fd]))
	{
		line = getnewline(fd, buffer, &files);
		return (1);
	}
	else
	{
		if (ft_strchr(files[fd]))

		else
		{
			swap2 = ft_strdup(files[fd]);
			free(files[fd];
			swap3 = getnewline(fd, buffer, &files);
			line = ft_strjoin(swap2, swap3);
			free(swap2);
			free(swap3);
		}
	}
}
