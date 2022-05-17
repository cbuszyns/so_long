/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_pt2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:24:05 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/02/16 12:32:21 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digit(uintptr_t nb, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_digit(-nb, base);
	}
	if (nb >= 16)
	{
		ft_digit(nb / 16, base);
		ft_putchar(base[nb % 16]);
	}
	else if (nb >= 0)
		ft_putchar(base[nb % 16]);
}

unsigned int	ft_puthex(uintptr_t num, char lett)
{
	int		count;
	char	*base;

	count = ft_len(num);
	if (lett == 'p')
	{
		write (1, "0x", 2);
		count += 2;
		base = "0123456789abcdef";
		ft_digit(num, base);
	}
	else if (lett == 'x')
	{
		base = "0123456789abcdef";
		ft_digit(num, base);
	}
	else
	{
		base = "0123456789ABCDEF";
		ft_digit(num, base);
	}
	return (count);
}

int	ft_putperc(void)
{
	return (write(1, "%", 1));
}
