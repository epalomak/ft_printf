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
    int  count;
    int  add;     
    char *str;

    add = (int)va_arg(tags->arg, void*);
    str = ft_itoa_base(add);
    count = 0;
    ft_putstr("0x");
    ft_putstr(str);

}