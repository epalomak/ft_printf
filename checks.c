/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:52 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/23 17:19:36 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

int		check_flags(const char *str, int i, t_tags *head)
{
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
	return (i);
}
