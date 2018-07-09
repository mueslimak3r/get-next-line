/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:26:41 by calamber          #+#    #+#             */
/*   Updated: 2018/07/08 20:08:14 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char	*line;
	int	fd;

	printf("started");
	fd = open("test", O_RDONLY);
	printf("%d\n", fd);
	if (!(get_next_line(fd, &line) == 1))
		return (0);
	if (line)
		printf("%s", line);
	else
		printf("line is null");
	return (0);
}
