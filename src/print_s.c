/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:00:57 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/29 17:00:59 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	print_s(t_tags *tags)
{
	int 	count;
	char 	*str;
	char	*str2;
	int		i;

	i = 0;
	str = va_arg(tags->arg, char*);
	if (tags->flags[2] == '-' && tags->flags[0] == '0')
		exit (0);
	if (tags->preci != 0 && tags->preci <= ft_strlen(str))
		str = ft_strncpy(str2, str, (size_t)tags->preci);
	count = ft_strlen(str);
	if (tags->flags[2] == '-')
		ft_putstr(str);
	if (tags->width != 0) 
	{
		while(count++ < tags->width)
			write(1, &tags->flags[0], 1);
		if(tags->flags[2] != '-')
	    	ft_putstr(str);

	}
	else if(tags->flags[2] != '-')
		ft_putstr(str);
}