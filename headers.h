/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:17:51 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/21 15:21:54 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct		s_flags
{
	int			hash;
	int			zero;
	int			minus;
	int 		plus;
	int 		fwidth;
	int			prec;
	int			slenght:
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			capl;
	char		specif;

	struct s_flags *next;
}					t_flags;

int			ft_printf(const char * restrict formt, ...);

#endif
