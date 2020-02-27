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

static int	ft_unb_count(uintmax_t nb)
{
	long	c;

	c = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

static int	ft_nb_count(intmax_t nb)
{
	long	c;

	c = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

char		*ft_uintmax_itoa(uintmax_t n)
{
	uintmax_t	i;
	char		*dst;

	i = ft_unb_count(n);
	if (n < 0)
	{
		if (!(dst = ft_strnew(i + 1)))
			return (NULL);
		dst[0] = '-';
		n = -n;
	}
	else if (!(dst = ft_strnew(i--)))
		return (NULL);
	if (n == 0)
		dst[0] = '0';
	while (n > 0)
	{
		dst[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}

char		*ft_intmax_itoa(intmax_t n)
{
	intmax_t	i;
	char		*dst;

	i = ft_nb_count(n);
	if (n < 0)
	{
		if (!(dst = ft_strnew(i + 1)))
			return (NULL);
		dst[0] = '-';
		n = -n;
	}
	else if (!(dst = ft_strnew(i--)))
		return (NULL);
	if (n == 0)
		dst[0] = '0';
	while (n > 0)
	{
		dst[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}