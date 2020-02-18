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

char    *ft_itoa_base(int src, int base)
{
    char        *base_tab;
    char       	*dst;
	static char	buf[66];

	dst = &buf[65];
	base_tab = "0123456789abcdef";
	*dst = '\0';
	if (src == 0)
		dst[0] = '0';
	while (src != 0)
	{
		*--dst = base_tab[src % base];	
		src /= base;
	}
	return(dst);
}