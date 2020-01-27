/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:35:29 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/27 16:17:51 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

void	set_tags(t_tags *tags)
{
	tags->flags[0] = '\0';
	tags->flags[1] = '\0';
	tags->flags[2] = '\0';
	tags->flags[3] = '\0';
	tags->flags[4] = '\0';
	tags->preci = 0;
	tags->negative = 1;
	tags->length = "\0";
}

int			ft_printf(const char *formt, ...)
{
	char		*tmp;
	va_list		ap;
	int			i;
	t_tags		*tags;

	if (!(tags = (t_tags*)malloc(sizeof(t_tags))))
		return (0);
	set_tags(tags);
	va_start(ap, formt);
	i = 0;
	while(formt[i] != '\0')
	{
		if (formt[i] == '%' && formt [i + 1] != '%')
		{
			i = check_tags((char *)formt, ++i, tags);
			
		}
		i++;
	}
	return(0);
}

int		main(void)
{
	ft_printf("working? %d");
}

/*
 * intmax_t can take integer of any length
 * uintmax_t can take unsigned interger of any length
 *
 * printf returns total length of printed strings.
 *
 *	flag[0] = '0'
 *	flag[1] = '#'
 *	flag[2] = '-'
 *	flag[3] = '+'
 *	flag[4] = ' '
 *
 *	in test main print return value and do this printf("[%-4s]") so you can easily see the spaces.
 * 
 * */
