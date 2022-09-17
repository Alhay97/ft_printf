/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:37 by aalhamel          #+#    #+#             */
/*   Updated: 2022/02/07 17:29:27 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include  <stdarg.h>
#include  <unistd.h>
#include  <limits.h>
#include  <stdio.h>
#include  <stdlib.h>

typedef struct t_list
{
  size_t  i;
  va_list arg;
  int negat;
  int len;
  int leng;
  int tmp;
  size_t  ret;
} t_list;

void  ft_putchar(char c, int fd, t_list *alist);
int num_size(int n, int base_len, t_list *alist);
char  *ft_strchr(const char *s, int c, t_list *alist);
void  ft_putchar_fd(char c, int fd, t_list *alist);
int nbrlen(unsigned int num, t_list *alist);
size_t  ft_strlen(const char *str);
int ft_putnbr_base(long long nbr, char * base, t_list *alist);
int ft_print_mem(unsigned long long nbr, char *base, t_list *alist);
void  ft_putstr(char *s, t_list *alist);
int ft_printf(const char *alhai, ...);
void  ft_speci(const char input, t_list *alist);
char  ft_getspecifier(const char *input, t_list *alist);

#endif
