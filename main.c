/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:26:41 by calamber          #+#    #+#             */
/*   Updated: 2018/07/09 20:54:07 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int	fd;

	printf("started\n");
	fd = open("test", O_RDONLY);
	printf("FD: %d\n", fd);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	return (0);
}
