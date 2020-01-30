/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:25:15 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/29 13:42:37 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

t_tags 		*tap_flags(char *str, t_tags *tags)
{
	if(str[tags->i] == '0')
		tags->flags[0] = '0';
	if(str[tags->i] == '#')
		tags->flags[1] = '#';
	if(str[tags->i] == '-')
		tags->flags[2] = '-';	
	if(str[tags->i] == '+')
		tags->flags[3] = '+';
	if(str[tags->i] == ' ')
		tags->flags[4] = ' ';
	
	return (tags);
}

//void       check_flags(t_tags *tags)
//{
//   if(tags->flags[0] == '0')
//}