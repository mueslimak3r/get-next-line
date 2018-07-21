/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:26:41 by calamber          #+#    #+#             */
/*   Updated: 2018/07/20 17:38:35 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int	fd;

	printf("started\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("FD: %d\n", fd);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
