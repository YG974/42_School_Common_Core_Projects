/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:20:44 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/27 15:17:23 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *tab2;
	int i;

	i = 0;
	if (!(tab2 = malloc(sizeof(int) * (length))))
		return (NULL);
	while (i < length)
	{
		tab2[i] = f(tab[i]);
		i++;
	}
	return (tab2);
}
