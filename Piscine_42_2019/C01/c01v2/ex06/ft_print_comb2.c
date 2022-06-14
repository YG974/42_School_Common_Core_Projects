/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:48:09 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/09 00:15:07 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int t;

	t = n % 10;
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(t + '0');
}

void	put_nb_a(int n)
{
	if (n < 10)
	{
		ft_putchar('0');
		ft_putnbr(n);
		ft_putchar(' ');
	}
	else
	{
		ft_putnbr(n);
		ft_putchar(' ');
	}
}

void	put_nb_b(int n)
{
	if (n < 10)
	{
		ft_putchar('0');
		ft_putnbr(n);
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_putnbr(n);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int na;
	int nb;

	na = 0;
	while (na < 99)
	{
		nb = na + 1;
		while (nb <= 99)
		{
			put_nb_a(na);
			if (na == 98 && nb == 99)
			{
				write(1, &"99", 2);
			}
			else
			{
				put_nb_b(nb);
			}
			nb++;
		}
		na++;
	}
}
