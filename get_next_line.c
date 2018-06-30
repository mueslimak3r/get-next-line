/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 23:47:06 by calamber          #+#    #+#             */
/*   Updated: 2018/06/29 17:59:04 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(const int fd, char **line)
{
	if (line[0] || line[1])
	{
		free(line[0]);
		line[0] = ft_strdup(line[1]);
		free(line[1]);
		return (readline(fd, 2, line));
	}
	else
	{
		if (!(readline(fd, 1, line)));
			return (0);
		return (readline(fd, 2, line));
	}
	return (0);
}

int	readline(const int fd, int p, char **line)
{
	char	buffer[BUFF + 1]
	char	temp;
	int		i;

	i = 1;
	buffer[BUFF + 1] = '\0';
	while ((temp != '\n') && (buffer))
	{
		read(fd, temp, 1);
		buffer[i++] = temp;
	}

	return (0);
}


