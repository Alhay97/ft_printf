/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:29 by aalhamel          #+#    #+#             */
/*   Updated: 2022/02/07 17:23:03 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	ft_getspecifier(const char *input, t_list *alist)
{
	if (input[alist -> i] == '%')
		alist -> i++;
	if (ft_strchr("cspdiuxX%", input[alist->i], alist) != 0)
		return (input[alist->i]);
	return (0);
}

void	ft_speci(const char input, t_list *alist)
{
	if (input == 'c')
		ft_putchar(va_arg(alist->arg, int), 1, alist);
	else if (input == 'd' || input == 'i')
		ft_putnbr_base(va_arg(alist->arg, int), "0123456789", alist);
	else if (input == 's')
		ft_putstr(va_arg(alist->arg, char *), alist);
	else if (input == 'u')
		ft_putnbr_base(va_arg(alist->arg, unsigned int), "0123456789", alist);
	else if (input == 'x')
		ft_putnbr_base(va_arg(alist->arg, unsigned int),
			"0123456789abcdef", alist);
	else if (input == 'X')
		ft_putnbr_base(va_arg(alist->arg, unsigned int),
			"0123456789ABCDEF", alist);
	else if (input == 'p')
	{
		write(1, "0x", 2);
		alist->ret += 2;
		ft_print_mem(va_arg(alist->arg, unsigned long long),
			"0123456789abcdef", alist);
	}
}

int	ft_printf(const char *ip, ...)
{
	t_list	st;
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	st.ret = 0;
	va_start(st.arg, ip);
	while (ip[i])
	{
		if (ip[i] == '%')
		{
			i++;
			if (ip[i] == '%')
				ft_putchar(ip[i], 1, &st);
			else
				ft_speci(ip[i], &st);
			i++;
		}
		else
			ft_putchar_fd(ip[i++], 1, &st);
	}
	va_end(st.arg);
	return (st.ret);
}
