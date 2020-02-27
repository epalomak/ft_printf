/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:57:20 by epalomak          #+#    #+#             */
/*   Updated: 2020/02/20 15:57:22 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

double    ft_round_nbr(double nbr)       // Change this completely                                    
{
    return (nbr);
}

static int	ft_num_count(double nb)
{
	long	c;

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

static char *ft_ftoa(double src, int preci)
{
    int     i;
    int     len;
    char    *dst;
    int     src2;
    
    i = 0;
    dst = (char*)malloc(sizeof(char) * (ft_num_count(src) + preci + 2));
    if (src < 0)
    {
        *dst++ = '-';
        src *= -1;
    }
    src2 = (int)src;
    dst = ft_strjoin(dst, ft_itoa(src2));
    len = ft_strlen(dst);
    i = len;
    dst[i++] = '.';
    while (i < (preci + len + 2))
    {
        src = src - (double)src2;
        src *= 10;
        src2 = (int)src;
        dst[i++] = src2 + '0';
    }
    return (dst);
}

void       print_f(t_tags *tags)
{
    double  src;
    char    *str;
    int     count;

    if (tags->preci == 0)
        tags->preci = 6;
    src = (va_arg(tags->arg, double));
    src = ft_round_nbr(src);
    str = ft_ftoa(src, tags->preci);
    ft_putstr(str);
    count = ft_strlen(str);
    tags->count += count;
}