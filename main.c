/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:26:41 by calamber          #+#    #+#             */
/*   Updated: 2018/07/05 16:27:42 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int fd;
	char	*line;

	fd = open("file", O_RDONLY);
	get_next_line(fd, &line);
	if (line)
		printf("%s", line);
	else
		printf("line is null");
	return (0);
}
