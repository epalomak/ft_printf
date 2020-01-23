/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:17:51 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/23 14:21:40 by epalomak         ###   ########.fr       */
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
	char			flags[4];
	int				preci;
	size_t			i;
	char			specif;
	int				negative;

	struct s_tags *next;
}					t_tags;

int			ft_printf(const char *formt, ...);

#endif
