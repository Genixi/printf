/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:58 by equiana           #+#    #+#             */
/*   Updated: 2019/11/26 17:22:18 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTF_H
#define FT_PRINTF_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

typedef struct		s_param
{
 	char			flag;
	char			flag_2;
    char			flag_3;
	int				width;
    int				precision;
    char			mod;
	char			mod_2;
	char        	type;
	int				head;
	int				null;
	int				hash;
	int				plus;
	int				space;
}					t_param;

typedef struct		s_nbr
{
	int				size;
	long			decimal;
	unsigned long	n;

}					t_nbr;

int					ft_printf(const char *restrict format, ...);
int					ft_prm_parse(char *s, t_param *p);
int					get_num_len(long int n);
void				ft_display(va_list ap, t_param *prm);
void				ft_prm_init(t_param *p);
void				ft_putnbr_i(int n, t_param *prm);
void				ft_putnbr_u(unsigned int n, t_param *prm);
void				ft_putnbr_l(long l);
void				ft_putnbr_f(double n, t_param *prm);
void				ft_putnbr_li(long int n, t_param *prm);
void				ft_putnbr_lo(unsigned long int n, t_param *prm);
void				ft_putnbr_lx(unsigned long ont, t_param *prm, int cap);
void				ft_putnbr_hi(short int n, t_param *prm);
void				ft_putnbr_ho(unsigned short int n, t_param *prm);	//short_oct.c
void				ft_putnbr_lu(unsigned long int n, t_param *prm);
void				ft_putnbr_lf(long double n, t_param *prm);
void				ft_putnbr_hu(unsigned short int n, t_param *prm);
void				ft_putnbr_hx(unsigned short int m, t_param *prm, int cap);
void				ft_putnbr_hhi(signed char n, t_param *prm);
void				ft_putnbr_hho(unsigned char o, t_param *prm);
void				ft_putnbr_hhu(unsigned char n, t_param *prm);
void				ft_putnbr_hhx(unsigned char n, t_param *prm, int cap);
void				ft_putnbr_hex(unsigned int value, t_param *prm, int cap);
void				ft_putnbr_oct(unsigned int value, t_param *prm);
void				ft_putnbr_ptr(unsigned long long int value, t_param *prm, int cap);
void				ft_put_char(char c, t_param *prm);
void				ft_put_str(char *s, t_param *prm);
void				ft_put_str_e(char *s, t_param *prm);
void				char_fill(char *str, int start, int end, char c, int eof); 
void				ft_error(int n);
void				display_str(t_param *p);
char				*ft_itoa_base_li(long int value, int base, int cap);
char				*ft_itoa_base_ul(unsigned long long int n, int base, int cap);
char				*ft_itoa_base_u(unsigned int n, int base, int cap);
char				*ft_itoa_base_hi(short int nbr, int base, int cap);            //short_int.c
char				*ft_itoa_base_hu(unsigned short int value, int base, int cap);
char                *ft_itoa_base_hhi(signed char nbr, int base, int cap);
char				*ft_itoa_base_hhu(unsigned char value, int base, int cap);

#endif //FT_PRINTF_PRINTF_H
