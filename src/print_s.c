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

char	*null_str(char *str)
{
	str = "(null)";
	return (str);
}

void	print_s(t_tags *tags)
{
	int		count;
	char	*str;
	char	*dst;
	int		i;

	i = 0;
	if ((str = va_arg(tags->arg, char*)) == NULL)
		str = null_str(str);
	dst = ft_memalloc(ft_strlen(str));
	if (tags->dot == '.' && tags->preci < (int)ft_strlen(str))
	{
		str = ft_strncpy(dst, (char*)str, (size_t)tags->preci);
	}
	count = ft_strlen(str);
	if (tags->flags[2] == '-')
		ft_putstr(str);
	if (tags->width != 0)
	{
		while (count++ < tags->width)
			write(1, &tags->flags[0], 1);
		if (tags->flags[2] != '-')
			ft_putstr(str);
		count--;
	}
	else if (tags->flags[2] != '-' && str[0] != '\0')
		ft_putstr(str);
	tags->count += count;
	free(dst);
}
