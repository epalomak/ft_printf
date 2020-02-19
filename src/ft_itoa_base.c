/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:34:06 by epalomak          #+#    #+#             */
/*   Updated: 2020/02/04 14:34:08 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers.h"

static int	ft_ncount(long nb, int base)
{
	size_t	c;

	c = 0;
	while (nb)
	{
		nb /= base;
		c++;
	}
	return (c);
}

char    *ft_itoa_base(int src, int base, int uppercase)
{
    char        *base_tab;
    char       	*dst;
	int			i;

	if (base < 2 || base > 16)
		return (0);
	i = ft_ncount(src, base);	
	dst = (char*)malloc(sizeof(char) * (i + 1));
	base_tab = "0123456789abcdef";
	if (uppercase == 1)
		base_tab = "0123456789ABCDEF";
	dst[i--] = '\0';
	if (src < 0)
	{
		src = -src;
		dst[0] = '-';
	}
	if (src == 0)
		dst[0] = '0';
	while (src != 0)
	{
		dst[i--] = base_tab[src % base];
		src /= base;
	}
	return(dst);
}