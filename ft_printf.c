/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:35:29 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/08 16:01:04 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>			//REMOVE THIS at somepoint :)

int			ft_printf(const char * restrict formt, ...)
{
	int			i;	
	char		*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(formt))))
		return (0);
	i = 0;
	while(formt[i] != '\0')
	{
		tmp[i] = formt[i];
		if (tmp[i] != '%')
			ft_putchar(tmp[i]);
	//	else if (tmp[i] == '%' && formt[i + 1] != '%')
	//		ft_check(*formt[i]);
		i++;
	}
	return(0);
}

int		main(void)
{
	ft_printf("HELLO");
	printf("\nHELLO");
}
