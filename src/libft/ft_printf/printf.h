/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:55:09 by dpenney           #+#    #+#             */
/*   Updated: 2020/01/24 17:25:59 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../includes/libft.h"
# include <stdarg.h>

enum				e_length
{
	none,
	hh,
	h,
	l,
	ll,
	L
};

/*
**	Structure that stores our internal representation of "user request"
*/

typedef struct		s_spec
{
	int				flag_zero;
	int				flag_hash;
	int				flag_plus;
	int				flag_dash;
	int				flag_space;

	int				width;
	int				precision;
	enum e_length	length;

	char			conv;
	int				stupid_c0_special_case;
}					t_spec;

/*
**	Generalized conversion function
**	Generalized argument extractor function
**  And all of its specifiers
*/

typedef struct		s_conv_f
{
	char			*specifiers;
	char			*(*to_str)(void *arg, t_spec spec);
	void			*(*arg_extract)(t_spec spec, va_list *vl);
	int				cleanup_needed;
}					t_conv_f;

/*
**	Integer convertors
*/

char				*itoa_b10u(long long n);
char				*itoa_b10(long long n);
char				*itoa_b2(long long n);

char				*itoa_b8(long long n);
char				*itoa_bxx(long long n);
char				*itoa_bx(long long n);

/*
**	Integer convertors wrappers
*/

char				*w_itoa_b10u(void *n, t_spec spec);
char				*w_itoa_b10(void *n, t_spec spec);
char				*w_itoa_b2(void *n, t_spec spec);
char				*w_itoa_b8(void *n, t_spec spec);
char				*w_itoa_xx(void *n, t_spec spec);
char				*w_itoa_x(void *n, t_spec spec);

/*
**	Non-integer convertors
*/

char				*ctoa(char c);
char				*stoa(char *s);
char				*ptoa(void *p);
char				*percent_to_a();

/*
**	Non-integer convertors wrappers
*/

char				*w_ftoa(void *x, t_spec spec);
char				*w_ctoa(void *x, t_spec spec);
char				*w_stoa(void *x, t_spec spec);
char				*w_ptoa(void *x, t_spec spec);
char				*w_percent(void *x, t_spec spec);

/*
**	Argument extractors
*/

void				*int_extractor(t_spec spec, va_list *vl);
void				*float_extractor(t_spec spec, va_list *vl);
void				*char_extractor(t_spec spec, va_list *vl);
void				*str_extractor(t_spec spec, va_list *vl);
void				*dummy_extractor(t_spec spec, va_list *vl);

t_conv_f			*find_action(t_spec spec);

int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);

#endif
