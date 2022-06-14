/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:56:48 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/09 14:34:40 by fel-hams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	put_line_a(int x)
{
	int i;

	i = x;
	ft_putchar('/');
	i--;
	while (i > 1)
	{
		ft_putchar('*');
		i--;
	}
	if (i == 1)
	{
		ft_putchar(92);
		ft_putchar('\n');
		i--;
	}
	else
	{
		ft_putchar('\n');
	}
}

void	put_line_b(int x)
{
	int i;

	i = x;
	ft_putchar('*');
	i--;
	while (i > 1)
	{
		ft_putchar(' ');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('*');
		ft_putchar('\n');
		i--;
	}
	else
	{
		ft_putchar('\n');
	}
}

void	put_line_c(int x)
{
	int i;

	i = x;
	ft_putchar(92);
	i--;
	while (i > 1)
	{
		ft_putchar('*');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('/');
		ft_putchar('\n');
		i--;
	}
	else
	{
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int i;

	i = y;
	while (i > 0)
	{
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
}
