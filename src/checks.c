/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:52 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/29 13:32:33 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

static	t_tags	*check_specifier(char *str, t_tags *tags)
{

	if (str[tags->i] == 'c')
		print_c(tags);
	if (str[tags->i] == 's')
		print_s(tags);
	if (str[tags->i] == 'p')
		print_p(tags);
	if (str[tags->i] == 'd')
		print_d(tags);
//	if (str[tags->i] == 'i')
//		print_i(tags);
//	if (str[tags->i] == 'o')
//		print_o(tags);
//	if (str[tags->i] == 'u')
//		print_u(tags);
//	if (str[tags->i] == 'x')
//		print_x(tags);
//	if (str[tags->i] == 'X')
//		print_cap_x(tags);
//	if (str[tags->i] == 'f')
//		print_f(tags);

	return (tags);
}

static t_tags		*check_length(char *str,t_tags *tags)
{
	if (str[tags->i] == 'h' && str[tags->i + 1] == 'h')
	{
		tags->length = "hh";
		tags->i += 2;
	}
	else if (str[tags->i] ==  'l' && str[tags->i +1] == 'l')
	{
		tags->length = "ll";
		tags->i += 2;
	}
	else if (str[tags->i] == 'l')
		tags->length = "l";
	else if (str[tags->i] == 'L')
		tags->length = "L";
	else if (str[tags->i] == 'h')
		tags->length = "h";	
	if (str[tags->i] == 'h' || str[tags->i] == 'l' || str[tags->i] == 'L')
		tags->i++;
	//printf("4.%zu\n", tags->i);
	return (check_specifier(str, tags));
}

static int		get_nbr(char *str, t_tags *tags)
{
	int		nbr;

	nbr = 0;
	while (str[tags->i] >= '0' && str[tags->i] <= '9' && str[tags->i] != '\0')
	{
		nbr = nbr * 10 + str[tags->i] - '0';
		tags->i++;
	}
	return (nbr);
}

static	t_tags		*check_width_preci(char *str, t_tags *tags)
{
	if (str[tags->i] >= '0' && str[tags->i] <= '9')
		tags->width = get_nbr(str, tags);
	while (str[tags->i] >= '0' && str[tags->i] <= '9')	
		tags->i++;
	//printf("1.\n");
	if (str[tags->i] == '.')
	{
		tags->i++;
		tags->preci = get_nbr(str, tags);
	}
	while (str[tags->i] >= '0' && str[tags->i] <= '9')
		tags->i++;
	//printf("2.\n");
	return (check_length(str, tags));
}

t_tags				*check_tags(char *str, t_tags *tags)
{
	tags->i++;
	while (str[tags->i] == '0' || str[tags->i] == '-' || str[tags->i] == '+' 
			|| str[tags->i] == '#' || str[tags->i] == ' ')  
	{
		tap_flags(str, tags);
		tags->i++;
	}
	if(tags->flags[2] == '-')
		tags->flags[0] = ' ';
	//printf("2.%zu\n",tags->i);
	return (check_width_preci(str, tags));
}
