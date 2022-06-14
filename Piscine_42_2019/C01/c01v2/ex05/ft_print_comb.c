/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:49:11 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/09 18:23:32 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_block(char a, char b, char c)
{
	ft_print_char(a);
	ft_print_char(b);
	ft_print_char(c);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_print_block(a, b, c);
				if (a == '7')
					break ;
				else
					write(1, &", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
