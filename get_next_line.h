/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:24:12 by calamber          #+#    #+#             */
/*   Updated: 2018/06/30 19:57:25 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef
# define

typedef static struct	s_fd
{
	char				*buffer;
	const int			fd;
	struct s_fd			*next;
}						t_fd

int					get_next_line(const int fd, char **line);

# endif
