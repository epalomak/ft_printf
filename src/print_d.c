/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:48:31 by epalomak          #+#    #+#             */
/*   Updated: 2020/02/04 14:48:33 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers.h"

char    *put_plus(char *str)
{
    char    *dst;
    int    i;
    int    j;

    i = 0;
    j= 0;
    dst = ft_strnew(ft_strlen(str) + 1);
    dst[i++] = '+';
    while (str[j] != '\0')
        dst[i++] = str[j++];
    return (dst);
}

char    *create_str(int src, t_tags *tags)
{
    char    *dst;

    if (tags->preci == 0)
    {
        dst = ft_itoa(src);
        return (dst);
    }
    if (src < 0)
    {
        src *= -1;
        tags->negative = -1;
    }
    dst = ft_itoa(src);
    return (dst);
}

char    *zero_str(t_tags *tags, int count, char *str)
{
    char    *dst;
    int     i;

    i = 0;
    dst = ft_strnew(tags->preci - count + 1);
    if (tags->negative == -1)
        dst[i++] = '-';
    while(count++ < tags->preci)
        dst[i++] = '0';
    return (dst);
}

void	print_d(t_tags *tags)                       // doesn't work with + flag
{
    int         count;               
    char        *str;
    char        *p;

    str = create_str(va_arg(tags->arg, int), tags);
    if (tags->preci != 0)
    {   
        p = zero_str(tags, ft_strlen(str), str);
        str = ft_strjoin(p, str);
    }
    if (tags->flags[3] == '+')
        str = put_plus(str);
    count = ft_strlen(str) + 1;
    if (tags->flags[2] == '-')
        ft_putstr(str);
    if (tags->width != 0)
    {
	    while(count++ <= tags->width)
		    write(1, &tags->flags[0], 1); 
        if (tags->flags[2] != '-')
            ft_putstr(str);
	}
	else if (tags->flags[2] != '-')
		ft_putstr(str);
}