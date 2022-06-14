/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:34:10 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/18 19:57:34 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

int		ft_positive_integer(int nb)
{
	if (nb >= 0)
		return (nb);
	else
	{
		ft_put_char('-');
		return (-nb);
	}
}

void	ft_putnbr(int nb)
{
	int r;
	int t;

	if (nb == -2147483648)
		write(1, &"-2147483648", 11);
	else
	{
		t = ft_positive_integer(nb);
		r = t % 10;
		t = t / 10;
		if (t != 0)
		{
			ft_putnbr(t);
		}
		ft_put_char(r + '0');
	}
}
