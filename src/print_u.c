/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:04:27 by epalomak          #+#    #+#             */
/*   Updated: 2020/02/20 15:04:30 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers.h"

static uintmax_t     get_nbr(t_tags *tags)
{
    uintmax_t nbr;

    if (ft_strcmp(tags->length, "hh") == 0)
        nbr = (unsigned char)(va_arg(tags->arg, unsigned int));
    if (ft_strcmp(tags->length, "h") == 0)
        nbr = (unsigned short)(va_arg(tags->arg, unsigned int));
    if (ft_strcmp(tags->length, "ll") == 0)
         nbr = (unsigned long long)(va_arg(tags->arg, unsigned long long int));
    if (ft_strcmp(tags->length, "l") == 0)
        nbr = (unsigned long)(va_arg(tags->arg,unsigned long int));
    if (ft_strcmp(tags->length, "\0") == 0)
        nbr = va_arg(tags->arg, unsigned int);
    return (nbr);
}

/*static char    *check_rest_flags(char *str, t_tags *tags)
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
}*/

static char    *create_str(uintmax_t src, t_tags *tags)
{
    char    *dst;

    if (tags->preci == 0)
    {
        if (src < 0)
            tags->negative = -1;
        dst = ft_uintmax_itoa(src);
        return (dst);
    }
    if (src < 0)
    {
        src *= -1;
        tags->negative = -1;
    }
    dst = ft_uintmax_itoa(src);
    return (dst);
}

static char    *zero_str(t_tags *tags, int count)
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

void	print_u(t_tags *tags)
{
    int         count;
    uintmax_t   nbr;
    char        *str;
    char        *p;

    nbr = get_nbr(tags);
    str = create_str(nbr, tags);
    if (tags->preci != 0 && tags->preci > (int)ft_strlen(str))
    {   
        p = zero_str(tags, ft_strlen(str));
        str = ft_strjoin(p, str);
    }
    //str = check_rest_flags(str, tags);
    count = ft_strlen(str);
    if (tags->flags[2] == '-')
        ft_putstr(str);
    if (tags->width != 0)
    {
	    while(count++ < tags->width)
		    write(1, &tags->flags[0], 1); 
        if (tags->flags[2] != '-')
            ft_putstr(str);
        count--;
	}
	else if (tags->flags[2] != '-')
		ft_putstr(str);
     tags->count += count;
}