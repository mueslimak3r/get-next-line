/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:34:02 by calamber          #+#    #+#             */
/*   Updated: 2018/05/07 16:34:10 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcnt(const char *t, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (t[i] != '\0')
	{
		while (t[i] == c)
			i++;
		if (t[i] != c)
			count++;
		while (t[i] != c && t[i])
			i++;
	}
	return (count);
}
