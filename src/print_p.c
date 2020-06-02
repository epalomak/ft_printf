/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:40:04 by epalomak          #+#    #+#             */
/*   Updated: 2020/06/01 21:19:36 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static int	if_width(t_tags *tags, char *str, int count)
{
	while (count++ < tags->width)
		write(1, &tags->flags[0], 1);
	if (tags->flags[2] != '-')
		ft_display(tags, str);
	count--;
	return (count);
}

void		print_p(t_tags *tags)
{
	uintmax_t	nbr;
	char		*str;
	char		*front;
	char		*src;
	int			count;

	nbr = va_arg(tags->arg, unsigned long);
	if (nbr < 0)
		nbr *= -1;
	front = "0x";
	src = ft_uintmax_itoa_base(nbr, 16, 0);
	str = ft_join_free(front, src);
	if (tags->dot == '.' && tags->preci == 0 && str[0] == '0')
		ft_strclr(str);
	count = ft_strlen(str);
	if (tags->flags[2] == '-')
		ft_display(tags, str);
	if (tags->width != 0)
		count = if_width(tags, str, count);
	else if (tags->flags[2] != '-')
		ft_display(tags, str);
	tags->count += count;
}
