/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 00:24:45 by calamber          #+#    #+#             */
/*   Updated: 2018/07/08 19:17:10 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int		length;
	int		sign;
	char	*str;

	sign = nbr;
	length = 1;
	while (sign /= 10)
		length++;
	sign = nbr < 0 ? 1 : 0;
	length += (nbr < 0) ? 1 : 0;
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	nbr *= (nbr < 0) ? -1 : 1;
	while (--length >= sign)
	{
		str[length] = (nbr >= 10) ? nbr % 10 + 48 : nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
