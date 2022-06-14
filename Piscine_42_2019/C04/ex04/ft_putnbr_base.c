/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:35:28 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/23 13:08:26 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen_strstr(char *str)
{
	int pos;
	int pos_find;

	pos = 0;
	if (str[pos] == '\0')
		return (0);
	while (str[pos] != '\0')
	{
		if (str[pos] == '-' || str[pos] == '+' || str[pos] == ' ')
			return (0);
		pos_find = pos + 1;
		while (str[pos_find] != '\0')
		{
			if (str[pos] == str[pos_find])
				return (0);
			pos_find++;
		}
		pos++;
	}
	if (pos < 2)
		return (0);
	return (pos);
}

void	print_nbr_base(int nbr, char *base, unsigned int len_base)
{
	unsigned int u_nbr;
	unsigned int rest;

	if (nbr < 0)
	{
		write(1, "-", 1);
		u_nbr = -nbr;
	}
	else
		u_nbr = nbr;
	rest = base[u_nbr % len_base];
	if (u_nbr >= len_base)
		print_nbr_base(u_nbr / len_base, base, len_base);
	write(1, &rest, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int len_base;

	len_base = ft_strlen_strstr(base);
	if (len_base < 2)
		return ;
	print_nbr_base(nbr, base, len_base);
}
