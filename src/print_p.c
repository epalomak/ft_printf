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
    intmax_t    add;     
    char        *str;
    int         count;

    add = va_arg(tags->arg, int);
    str = ft_strjoin("0x10", ft_intmax_itoa_base(add, 16, 0));
    count = ft_strlen(str);
    if (tags->flags[2] == '-')
        ft_putstr(str);
    if (tags->width != 0) 
	{
		while (count++ < tags->width)
			write(1, &tags->flags[0], 1);
		if (tags->flags[2] != '-')
	    	ft_putstr(str);
	}
	else if(tags->flags[2] != '-')
		ft_putstr(str);
    tags->count += count;
}