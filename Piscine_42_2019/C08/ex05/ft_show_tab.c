/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:47:03 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/25 23:44:54 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	int rest;
	int quotient;

	if (nb == -2147483648)
		write(1, &"-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		rest = nb % 10;
		quotient = nb;
		quotient = quotient / 10;
		if (quotient != 0)
		{
			ft_putnbr(quotient);
		}
		ft_putchar(rest + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	if (!par)
		return ;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
