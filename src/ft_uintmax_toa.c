/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_toa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:49:29 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/08 13:59:45 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int			ft_unb_count(uintmax_t nb)
{
	long	c;

	c = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

char		*ft_uintmax_itoa(uintmax_t n)
{
	uintmax_t	i;
	char		*dst;

	i = ft_unb_count(n);
	if (n < 0)
	{
		if (!(dst = ft_strnew(i + 1)))
			return (NULL);
		dst[0] = '-';
		n = -n;
	}
	else if (!(dst = ft_strnew(i--)))
		return (NULL);
	if (n == 0)
		dst[0] = '0';
	while (n > 0)
	{
		dst[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}
