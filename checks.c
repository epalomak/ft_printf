/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:52 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/24 15:32:12 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

static	int		check_specifier(const char *str, int i, t_tags *head)
{
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		i++;	
	if (str[i] == 'c')
		head->specif = 'c';
	if (str[i] == 's')
		head->specif = 's';
	if (str[i] == 'p')
		head->specif = 'p';
	if (str[i] == 'd')
		head->specif = 'd';
	if (str[i] == 'i')
		head->specif = 'i';
	if (str[i] == 'o')
		head->specif = 'o';
	if (str[i] == 'u')
		head->specif = 'u';
	if (str[i] == 'x')
		head->specif = 'x';
	if (str[i] == 'X')
		head->specif = 'X';
	printf("4, %d\n", i);
	return (i);
}

static	int		check_length(const char *str, int i, t_tags *head)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		head->length = "hh";
		i += 2;
	}
	else if (str[i] ==  'l' && str[i +1] == 'l')
	{
		head->length = "ll";
		i += 2;
	}
	else if (str[i] == 'l')
		head->length = "l";
	else if (str[i] == 'L')
		head->length = "L";
	else if (str[i] == 'h')
		head->length = "h";	
	printf("3, %d\n", i);
	return (check_specifier(str, i, head));
}

static	int		get_nbr(const char *str, int i)
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

static	int		check_width_preci(const char *str,int i,t_tags *head)
{
	if (str[i] >= '0' && str[i] <= '9')
		head->width = get_nbr(str, i);
	while (str[i] >= '0' && str[i] <= '9')	
		i++;
	if (str[i] == '.')
		head->preci = get_nbr(str, ++i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	printf("2, %d\n", i);
	return (check_length(str, i, head));
}

int				check_flags(const char *str, int i, t_tags *head)
{
	int		hit;

	hit = i;
	while (str[i] == '#')
	{
		head->flags[0] = '#';
		i++;
	}
	while (str[i] == '0')
	{
		head->flags[1] = '0';
		i++;

	}
	while (str[i] == '-')
	{
		head->flags[2] = '-';
		i++;
	}
	while (str[i] == '+')
	{
		head->flags[3] = '+';
		i++;
	}
	if (hit - i != 0)
		i++;
	printf("1, %d\n", i);
	return (check_width_preci(str, i, head));
}
