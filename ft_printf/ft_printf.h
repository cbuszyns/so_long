/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:55:53 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/02/16 12:22:05 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_format(va_list args, const char format);
int				ft_putstr(char *str);
int				ft_put_unsigned(unsigned int n);
int				ft_putnbr(int n);
int				ft_len(uintptr_t n);
int				ft_putperc(void);
int				ft_putchar(int c);
unsigned int	ft_puthex(uintptr_t num, char lett);

#endif
