/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsubcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:04:48 by calamber          #+#    #+#             */
/*   Updated: 2018/07/07 18:33:21 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*strsubcpy(char *dst, const char *src, int len, int start)
{
	char	*pointer;

	pointer = dst;
	while (start > 0)
		src++;
	while (len > 0 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (pointer);
}
