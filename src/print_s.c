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
	char	*dst;
	int		i;

	i = 0;
	dst = ft_memalloc(1);
	str = va_arg(tags->arg, char*);
//	printf("3.\n");
	if (tags->preci != 0 && tags->preci <= ft_strlen(str))
		str = strncpy(dst, str, (size_t)tags->preci);
	count = ft_strlen(str);
//	printf("4.\n");
	if (tags->flags[2] == '-')
		ft_putstr(str);
	if (tags->width != 0) 
	{
		while (count++ < tags->width)
			write(1, &tags->flags[0], 1);
		if (tags->flags[2] != '-')
	    	ft_putstr(str);

	}
	else if(tags->flags[2] != '-')
		ft_putstr(str);
}