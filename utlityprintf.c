/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlityprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:41 by aalhamel          #+#    #+#             */
/*   Updated: 2022/02/07 16:50:45 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int fd, t_list *alist)
{
	write(fd, &c, 1);
	alist -> ret += 1;
	alist -> i += 1;
}

void	ft_putchar_fd(char c, int fd, t_list *alist)
{
	write(fd, &c, 1);
	alist -> ret += 1;
}

int	num_size(int n, int base_len, t_list *alist)
{
	alist->i = 1;
	while (n >= base_len)
	{
		n /= base_len;
		alist -> i++;
	}
	return (alist -> i);
}

char	*ft_strchr(const char *s, int c, t_list *alist)
{
	char	j;

	j = (char) c;
	alist -> i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (s[alist -> i])
	{
		if (s[alist->i] == j)
			return ((char *)s + alist -> i);
		alist->i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
