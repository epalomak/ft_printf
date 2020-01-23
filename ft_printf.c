/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:35:29 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/23 14:23:24 by epalomak         ###   ########.fr       */
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

void	set_tags

char	*check_flag(char *str, int i)
{
	if (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i]  == '+')
	{
		i++;
	}
	if (str[i] >= 0 && str[i] <= 9)
	{
	 	get_nbr(str)
	}
		
}

int			ft_printf(const char *formt, ...)
{
	char		*tmp;
	va_list		ap;
	t_tags		head;

	set_tags(head);
	va_start(ap. formt);
	i = 0;
	while(formt[i] != '\0')
	{
		if (formt[i] != '%')
			ft_putchar(formt);
		else if (formt[i] == '%' && formt [i + 1] != '%')
			check_flags(formt, i)
			 
		i++;

	}
	return(0);
}

int		main(void)
{
	int i = 0;
	int	nbr = 0;
	char *s1 = "2167";
	nbr = get_nbr(s1, i);
	printf("%d", nbr);
}

/*
 * intmax_t can take integer of any length
 * uintmax_t can take unsigned interger of any length
 *
 *
 *
 * 
 * */
