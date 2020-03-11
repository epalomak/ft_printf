/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:40:04 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/30 15:40:07 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	print_p(t_tags *tags)
{
	uintmax_t	add;
	char		*str;
	char		*front;
	char		*src;
	int			count;

	add = va_arg(tags->arg, unsigned int);
	if (add <= 0)
		front = "0x";
	else
		front = "0x10";
	src = ft_uintmax_itoa_base(add, 16, 0);
	str = ft_join_free(front, src);
	if (tags->dot == '.' && tags->preci == 0 && str[0] == '0')
		ft_strclr(str);
	count = ft_strlen(str);
	if (tags->flags[2] == '-')
		ft_display(tags, str);
	if (tags->width != 0)
	{
		while (count++ < tags->width)
			write(1, &tags->flags[0], 1);
		if (tags->flags[2] != '-')
			ft_display(tags, str);
		count--;
	}
	else if (tags->flags[2] != '-')
		ft_display(tags, str);
	tags->count += count;
}
