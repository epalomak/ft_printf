/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:35:29 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/29 13:42:32 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	set_tags(t_tags *tags)
{
	tags->flags[0] = ' ';
	tags->flags[1] = '\0';
	tags->flags[2] = '\0';
	tags->flags[3] = '\0';
	tags->flags[4] = '\0';
	tags->preci = 0;
	tags->negative = 1;
	tags->length = "\0";
	tags->width = 0;
	tags->upp = 0;
}

int			ft_printf(const char *formt, ...)
{
	t_tags		*tags;

	if (!(tags = (t_tags*)malloc(sizeof(t_tags))))
		return (0);
	tags->i = 0;
	tags->count = 0;
	va_start(tags->arg, formt);
	while(formt[tags->i] != '\0')
	{
		if (formt[tags->i] != '%')
		{
			ft_putchar(formt[tags->i]);
			tags->count++;
		}
		if (formt[tags->i] == '%')
		{
			set_tags(tags);
			check_tags((char *)formt, tags);
		}
		tags->i++;
	}
	va_end(tags->arg);
	return(tags->count);
}

/*int		main(void)
{
	//unsigned long i = -42;
	ft_printf("[%llx]\n", 4294967296);
	   printf("[%llx]\n", 4294967296);
	return (0);
} 
*/


/*
 * print_u does not work with over max int, problem probably with itoa.
 * 
 * lenght is handeled only by casting the va_arg 
 *
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
 * 
 * */