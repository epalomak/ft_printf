/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:35:29 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:55 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

int		get_nbr(char *str, int i)
{
	int		nbr;

	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}

void	set_tags(t_tags *head)
{
	head->flags[0] = '\0';
	head->flags[1] = '\0';
	head->flags[2] = '\0';
	head->flags[3] = '\0';
	head->preci = 0;
	head->specif = '\0';
	head->negative = 1;
}

int			ft_printf(const char *formt, ...)
{
	char		*tmp;
//	va_list		ap;
	int			i;
	t_tags		*head;

	if (!(head = (t_tags*)malloc(sizeof(t_tags))))
		return (0);
	set_tags(head);
//	va_start(ap. formt);
	i = 0;
	while(formt[i] != '\0')
	{
		if (formt[i] != '%')
			ft_putchar(formt[i]);
		else if (formt[i] == '%' && formt [i + 1] != '%')
		{
			printf ("%d\n", i);
			printf("working\n");
			i = check_flags(formt, ++i, head);	
			printf ("%d\n", i);
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
 *	flag[0] = '#'
 *	flag[1] = '0'
 *	flag[2] = '-'
 *	flag[3] = '+'
 *
 * 
 * */
