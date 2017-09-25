/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:36:10 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:36:12 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>
# define ABS(v) ((v) < 0 ? -(v) : (v))

typedef struct	s_fl
{
	va_list		arg;
	int			i;
	int			ret;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			grid;
	int			width;
	int			accur;
	int			t;
	char		type;
	char		len;
	int			s_len;
}				t_fl;

int				ft_putwch(wchar_t value);
int				ft_wchlen(wchar_t value);
void			ft_decimal(t_fl *fl);
void			ft_ch_flag(t_fl *fl, intmax_t *num);
void			ft_pr_dp(size_t *len, t_fl *fl, intmax_t num);
void			ft_pr_dm(size_t *len, t_fl *fl, intmax_t num);
void			ft_checkd(t_fl *fl, intmax_t num, size_t *len);
void			ft_dp1(t_fl *fl, intmax_t num);
void			ft_dp2(size_t *len, t_fl *fl, intmax_t num);
void			ft_dp3(size_t *len, t_fl *fl, intmax_t num);
void			ft_dp4(intmax_t num);
int				ft_pr_argz(size_t len, intmax_t num, t_fl *fl);
void			ft_pr_symb(intmax_t num, t_fl *fl);
void			ft_hexad(t_fl *fl);
void			ft_ch_flagx(t_fl *fl, intmax_t *num);
void			ft_pr_hexp(size_t *len, t_fl *fl, intmax_t num, char *str);
void			ft_pr_hexm(size_t *len, t_fl *fl, char *str);
void			ft_checkx(t_fl *fl, intmax_t num);
void			ft_hexp1(t_fl *fl, intmax_t num);
void			ft_hexp2(size_t *len, t_fl *fl);
void			ft_hexp3(size_t *len, t_fl *fl);
int				ft_pr_argx(intmax_t num, t_fl *fl);
void			ft_hexadx(t_fl *fl);
void			ft_ch_flagxx(t_fl *fl, intmax_t *num);
void			ft_pr_hexxp(size_t *len, t_fl *fl, intmax_t num, char *str);
void			ft_pr_hexxm(size_t *len, t_fl *fl, char *str);
void			ft_checkxx(t_fl *fl, intmax_t num);
void			ft_hexxp1(t_fl *fl, intmax_t num);
void			ft_hexxp2(size_t *len, t_fl *fl);
void			ft_hexxp3(size_t *len, t_fl *fl);
int				ft_pr_argxx(intmax_t num, t_fl *fl);
void			ft_octal(t_fl *fl);
void			ft_ch_flago(t_fl *fl, intmax_t *num);
void			ft_pr_octp(size_t *len, t_fl *fl, intmax_t num, char *str);
void			ft_pr_octm(size_t *len, t_fl *fl, char *str);
void			ft_checko(t_fl *fl, intmax_t num);
void			ft_octp1(t_fl *fl, intmax_t num);
void			ft_octp2(size_t *len, t_fl *fl);
void			ft_octp3(size_t *len, t_fl *fl);
int				ft_pr_argo(t_fl *fl, intmax_t num);
void			ft_udecimal(t_fl *fl);
void			ft_for_udp(t_fl *fl, size_t num, size_t len);
void			ft_for_udm(t_fl *fl, size_t num, size_t len);
size_t			ft_unumlen(size_t n);
int				ft_pr_argu(size_t num, t_fl *fl);
void			ft_percent(t_fl *fl);
void			ft_for_per(int i);
void			ft_point(t_fl *fl);
int				ft_pr_argpp(int num, t_fl *fl);
void			ft_poip1(t_fl *fl, int num);
void			ft_poip2(size_t *len, t_fl *fl);
void			ft_poip3(size_t *len, t_fl *fl);
void			ft_char(t_fl *fl);
void			ft_for_ch(t_fl *fl);
void			ft_str_s(t_fl *fl);
char			*width_trim_p(t_fl *fl, char *str, char ch);
char			*width_trim_m(t_fl *fl, char *str, char ch);
char			*acur_trim(t_fl *fl, char *str);
int				ft_pr_args(t_fl *fl);
void			ft_str_ss(t_fl *fl);
int				ft_wstrlen(wchar_t *value);
int				ft_putwstr(wchar_t *value);
int				ft_flag(char *str, t_fl *fl);
int				ft_width(char *str, t_fl *fl);
int				ft_accuracy(char *str, t_fl *fl);
int				ft_len(char *str, t_fl *fl);
void			ft_len1(char *str, t_fl *fl, char ch);
int				ft_type(char *str, t_fl *fl);
int				ft_printf(const char *format, ...);
void			ft_basic_fl(t_fl *fl);
void			ft_solve(char *str, t_fl *fl);
void			ft_initialization(t_fl *fl);
size_t			ft_numlend(intmax_t n);
void			ft_puthex(char *str);
char			*ft_itoa_base(size_t value, size_t base);
void			aux(size_t n, size_t b, char *ans, int *p);
char			*ft_itoa_basem(intmax_t value, int base);
void			chose(intmax_t n, int b, char *ans, int *p);
int				ft_intlen(int n);
void			ft_wr_wrong(t_fl *fl, char *str);

#endif
