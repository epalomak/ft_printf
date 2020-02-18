/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:17:51 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/29 13:35:36 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>					//  !!!! Remove this before submission !!!!
#include <string.h>
#include "./libft/libft.h"

typedef struct		s_tags
{
	char			flags[5];
	int				preci;
	size_t			i;
	int				negative;
	int				width;
	char			*length;
	va_list			arg;
	char			*pchar;
	char			filler;

	struct s_tags *next;
}					t_tags;

int			ft_printf(const char *formt, ...);
t_tags		*check_tags(char *str, t_tags *tags);
void		print_c(t_tags *tags);
void		print_s(t_tags *tags);
void		print_p(t_tags *tags);
void		print_d(t_tags *tags);
t_tags 		*tap_flags(char *str, t_tags *tags);
char    	*ft_itoa_base(int src, int base);

#endif
