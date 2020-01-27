/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:52 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/27 16:15:44 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

static	int		check_specifier(char *str, int i, t_tags *tags)
{

	if (str[i] == 'c')
		print_c(tags);
//	if (str[i] == 's')
//		print_s(tags);
//	if (str[i] == 'p')
//		print_p(tags);
//	if (str[i] == 'd')
//		print_d(tags);
//	if (str[i] == 'i')
//		print_i(tags);
//	if (str[i] == 'o')
//		print_o(tags);
//	if (str[i] == 'u')
//		print_u(tags);
//	if (str[i] == 'x')
//		print_x(tags);
//	if (str[i] == 'X')
//		print_cap_x(tags);
//	if (str[i] == 'f')
//
	return (i);
}

static	int		check_length(char *str, int i, t_tags *tags, va_list ap)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		tags->length = "hh";
		i += 2;
	}
	else if (str[i] ==  'l' && str[i +1] == 'l')
	{
		tags->length = "ll";
		i += 2;
	}
	else if (str[i] == 'l')
		tags->length = "l";
	else if (str[i] == 'L')
		tags->length = "L";
	else if (str[i] == 'h')
		tags->length = "h";	
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		i++;	
	return (check_specifier(str, i, tags, ap));
}

static	int		get_nbr(char *str, int i)
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

static	int		check_width_preci(char *str,int i,t_tags *tags, va_list ap)
{
	if (str[i] >= '0' && str[i] <= '9')
		tags->width = get_nbr(str, i);
	while (str[i] >= '0' && str[i] <= '9')	
		i++;
	if (str[i] == '.')
		tags->preci = get_nbr(str, ++i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	printf("2, %d\n", i);
	return (check_length(str, i, tags, ap));
}

int				check_tags(char *str, int i, t_tags *tags, va_list ap)
{
	int		hit;

	hit = i;
	while (str[i] == '#')
	{
		tags->flags[0] = '#';
		i++;
	}
	while (str[i] == '0')
	{
		tags->flags[1] = '0';
		i++;

	}
	while (str[i] == '-')
	{
		tags->flags[2] = '-';
		i++;
	}
	while (str[i] == '+')
	{
		tags->flags[3] = '+';
		i++;
	}
	if (hit - i != 0)
		i++;
	return (check_width_preci(str, i, tags, ap));
}
