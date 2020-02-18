/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:40:04 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/30 15:40:07 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"


void	print_p(t_tags *tags)
{
    int      add;     
    char    *str;
    int     i;

    i = 0;
    add = va_arg(tags->arg, int);
    str = ft_itoa_base(add, 16);
    write(1, "0x10", 5);
    ft_putstr(str);
}