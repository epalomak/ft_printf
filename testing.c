/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:42:36 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/09 13:54:49 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		add(int args, ...)
{
	va_list ap;
	int i;
	int sum;
	
	va_start(ap, args);
	i = 0;
	sum = 0;
	while(i < args)
	{
		sum += va_arg(ap, int);
		i++;
	}	
	va_end(ap);
	return (sum);
}

int		main(void)
{
	printf("%d\n", add(6, 2,2,6,8,1,1));
	return (0);
}
	
