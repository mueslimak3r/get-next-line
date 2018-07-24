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
	int	ret;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		close(fd);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("ret= %d ", ret);
			printf("%s\n", line);
			free(line);
		}
		printf("ret= %d\n", ret);
	}
	else
	{
		fd = 0;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (line)
			{
				printf("ret= %d ", ret);
				printf("%s\n", line);
				free(line);
			}
		}
		printf("ret= %d\n", ret);
	}
	return (0);
}
