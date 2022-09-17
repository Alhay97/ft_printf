/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlityprintf2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:46 by aalhamel          #+#    #+#             */
/*   Updated: 2022/02/07 17:03:54 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_helper(char *base, t_list *alist, long n)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < base_len)
	{
		write(1, &base[n], 1);
		alist -> ret ++;
	}
}

int	ft_putnbr_base(long long nbr, char *base, t_list *alist)
{
	long	n;
	int		base_len;

	n = 0;
	alist->negat = 0;
	if (n < 0)
		alist->negat = 1;
	n = nbr;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
		alist -> ret ++;
	}
	ft_putnbr_base_helper(base, alist, n);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base, alist);
		write (1, &base[n % base_len], 1);
		alist -> ret++;
	}
	return (num_size(n, base_len, alist) + alist->negat);
}

int	ft_print_mem(unsigned long long nbr, char *base, t_list *alist)
{
	unsigned long long	n;

	n = nbr;
	alist -> i = 0;
	if (nbr == 0)
	{
		write (1, "0", 1);
		alist -> ret ++;
		return (1);
	}
	if (n < 16)
	{
		alist -> i++;
		write (1, &base[n], 1);
		alist -> ret ++;
	}
	if (n >= 16)
	{
		alist -> i += ft_putnbr_base(n / 16, base, alist);
		write (1, &base[n % 16], 1);
		alist -> ret ++;
	}
	return (num_size(nbr, 16, alist));
}

void	ft_putstr(char *s, t_list *alist)
{
	int	j;

	if (s == NULL)
	{
		write (1, "(null)", 6);
		alist->ret += 6;
		alist->i++;
	}
	else
	{
		j = ft_strlen(s);
		write (1, s, j);
		alist->ret += j;
		alist->i++;
	}
}

int	nbrlen(unsigned int num, t_list *alist)
{
	alist->i = 0;
	while (num > 0)
	{
		num /= 10;
		alist -> i++;
	}
	return (alist -> i);
}
