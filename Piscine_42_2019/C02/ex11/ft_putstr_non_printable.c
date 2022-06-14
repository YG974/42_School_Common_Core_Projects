/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:27:27 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/17 22:34:06 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str_is_printable(unsigned char *str)
{
	if (str[0] >= 32 && str[0] <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*hexa_tab;
	unsigned char	uc;

	i = 0;
	hexa_tab = "0123456789abcdef";
	while (str[i] != '\0')
	{
		uc = (unsigned char)str[i];
		if (ft_str_is_printable(&uc) == 0)
		{
			ft_putchar(92);
			ft_putchar(hexa_tab[uc / 16]);
			ft_putchar(hexa_tab[uc % 16]);
		}
		else
			ft_putchar(uc);
		i++;
	}
}
