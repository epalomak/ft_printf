/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:41:05 by epalomak          #+#    #+#             */
/*   Updated: 2020/02/19 12:41:07 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static char    *check_rest_flags(char *str, t_tags *tags)
{
    char    *dst;
    int    i;
    int    j;

    i = 0;
    j= 0;
    dst = ft_strnew(ft_strlen(str) + 1);
    if(tags->flags[4] == ' ' && tags->negative != -1 && tags->flags[3] != '+')
        dst[i++] = ' ';
    if(tags->flags[3] == '+' && tags->negative != -1)
        dst[i++] = '+';
    while (str[j] != '\0')
        dst[i++] = str[j++];
    return (dst);
}

static char    *create_str(int src, t_tags *tags)
{
    char    *dst;

    if (tags->preci == 0)
    {
        if (src < 0)
            tags->negative = -1;
        dst = ft_itoa_base(src, 8, 0);
        return (dst);
    }
    if (src < 0)
    {
        src *= -1;
        tags->negative = -1;
    }
    dst = ft_itoa_base(src, 8, 0);
    return (dst);
}

static char    *zero_str(t_tags *tags, int count, char *str)
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

void	print_o(t_tags *tags) 
{
    int         count;               
    char        *str;
    char        *p;

    str = create_str(va_arg(tags->arg, int), tags);
    if (tags->preci != 0 && tags->preci > ft_strlen(str))
    {   
        p = zero_str(tags, ft_strlen(str), str);
        str = ft_strjoin(p, str);
    }
    str = check_rest_flags(str, tags);
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