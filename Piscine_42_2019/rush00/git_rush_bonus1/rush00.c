/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:49:03 by fel-hams          #+#    #+#             */
/*   Updated: 2019/06/09 13:53:23 by fel-hams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	put_line_a(int x)
{
	int i;

	i = x;
	ft_putchar('o');
	i--;
	while (i > 1)
	{
		ft_putchar('-');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('o');
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
	ft_putchar('|');
	i--;
	while (i > 1)
	{
		ft_putchar(' ');
		i--;
	}
	if (i == 1)
	{
		ft_putchar('|');
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
			put_line_a(x);
			i--;
		}
	}
}
