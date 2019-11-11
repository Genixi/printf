/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:58 by equiana           #+#    #+#             */
/*   Updated: 2019/11/11 16:56:15 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTF_H
#define FT_PRINTF_PRINTF_H

#include <stdarg.h>
#include "libft.h"

# define BUFF_SIZE	1024

typedef struct		s_param
{
    char			flag;
    int				width;
    int				precision;
    char			mod;
	char        	type;
}					t_param;

int					ft_printf(const char *restrict format, ...);
int					ft_prm_parse(char *s, t_param *p);
int					get_num_len(long int n);
void				ft_display(va_list ap, t_param *prm);
void				ft_prm_init(t_param *p);
void				ft_putnbr_i(int n, t_param *prm);
void				ft_putnbr_u(unsigned int n, t_param *prm);
void				ft_putnbr_l(long l);
void				ft_putnbr_hex(int value);
void				ft_putnbr_oct(int value);
void				ft_put_char(char c, t_param *prm);
void				ft_put_str(char *s, t_param *prm);
void				char_fill(char *str, int len, char c); 
void				ft_display_float(va_list ap, t_param *p);
void				ft_error(int n);
void				display_str(t_param *p);
char				*ft_itoa_base_u(unsigned int n, int base);

#endif //FT_PRINTF_PRINTF_H
