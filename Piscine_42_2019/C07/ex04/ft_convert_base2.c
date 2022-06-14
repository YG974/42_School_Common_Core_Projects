/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:50:04 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/24 14:23:25 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_index(char c, char *base);

int		ft_tnrvfrr(char *str, char *base)
{
	int i;

	i = 0;
	while ((base_index(str[i], base) < 0) &&
			str[i] != '+' && str[i] != '-')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
				str[i] != '\r' && str[i] != '\f' && str[i] != '\v')
			return (-1);
		i++;
	}
	return (i);
}
