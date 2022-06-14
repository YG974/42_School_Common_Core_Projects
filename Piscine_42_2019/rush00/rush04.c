/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:55:59 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/08 17:46:34 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	put_line_a(int x)
{
	int i;

	i = x;
	ft_put_char('A');
	i--;
	while (i > 1)
	{
		ft_put_char('B');
		i--;
	}
	if (i == 1)
	{
		ft_put_char('C');
		ft_put_char('\n');
		i--;
	}
}

void	put_line_b(int x)
{
	int i;

	i = x;
	ft_put_char('B');
	i--;
	while (i > 1)
	{
		ft_put_char(' ');
		i--;
	}
	if (i == 1)
	{
		ft_put_char('B');
		ft_put_char('\n');
		i--;
	}
}

void	put_line_c(int x)
{
	int i;

	i = x;
	ft_put_char('C');
	i--;
	while (i > 1)
	{
		ft_put_char('B');
		i--;
	}
	if (i == 1)
	{
		ft_put_char('A');
		ft_put_char('\n');
		i--;
	}
}

void	rush(int x, int y)
{
	int i;

	i = y;
	while (i > 0)
		if (i == y)
		{
			put_line_a(x);
			i--;
		}
		else if (i > 1)
		{
			put_line_b(x);
			i--;
		}
		else
		{
			put_line_c(x);
			i--;
		}
}

int		main(void)
{
	int x;
	int y;

	x = 8;
	y = 6;
	if ((x || y) < 1)
	{
		write(1, &"please enter a srictly positive value for x and y", 49);
	}
	else
	{
		rush(x, y);
		return (0);
	}
}
