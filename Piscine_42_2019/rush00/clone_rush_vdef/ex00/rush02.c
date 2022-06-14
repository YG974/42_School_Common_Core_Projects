/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:55:19 by fel-hams          #+#    #+#             */
/*   Updated: 2019/06/09 21:39:09 by fel-hams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	put_line_a(int x)
{
	int i;

	i = x;
	ft_putchar('A');
	i--;
	while (i > 1)
	{
		ft_putchar('B');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('A');
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
	ft_putchar('B');
	i--;
	while (i > 1)
	{
		ft_putchar(' ');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('B');
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
	ft_putchar('C');
	i--;
	while (i > 1)
	{
		ft_putchar('B');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('C');
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
	while (i > 0 && x > 0)
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
