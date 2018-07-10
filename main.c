/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:26:41 by calamber          #+#    #+#             */
/*   Updated: 2018/07/09 17:01:39 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char	*line;
	int	fd;
	int	i;

	printf("started\n");
	fd = open("test", O_RDONLY);
	printf("FD = %d\n", fd);
	i = get_next_line(fd, &line);
	printf("First Line: %s\n", line);
	i = get_next_line(fd, &line);
	printf("Second Line: %s\n", line);
	return (0);
}
