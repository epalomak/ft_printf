/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:12:57 by epalomak          #+#    #+#             */
/*   Updated: 2020/03/05 15:13:03 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	int		ft_num_count(long double nb)
{
	int	c;

	c = 0;
	if (nb < 0)
		nb *= -1;
	while (nb >= 1)
	{
		c++;
		nb /= 10;
	}
	return (c);
}

char			*ft_ftoa(long double src, int preci)
{
	int			i;
	int			len;
	char		*dst;
	intmax_t	src2;

	i = 0;
	dst = (char*)malloc(sizeof(char) * (ft_num_count(src) + preci + 2));
	if (src < 0)
	{
		dst[i++] = '-';
		src *= -1;
	}
	src2 = (intmax_t)src;
	dst = ft_join_free(dst, ft_intmax_itoa(src2));
	len = ft_strlen(dst);
	i = len;
	dst[i++] = '.';
	while (i < (preci + len + 1))
	{
		src = (src - (long double)src2) * 10;
		src2 = (intmax_t)src;
		dst[i++] = src2 + '0';
	}
	dst[i] = '\0';
	return (dst);
}
