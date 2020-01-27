/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:17:51 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/27 16:15:49 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
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

	struct s_tags *next;
}					t_tags;

int			ft_printf(const char *formt, ...);
int			check_tags(const char *str, int i, t_tags *tags);

#endif
