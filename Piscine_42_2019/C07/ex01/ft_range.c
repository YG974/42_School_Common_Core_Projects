/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:23:10 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/22 19:54:43 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int j;

	j = 0;
	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if ((tab = (int*)malloc(sizeof(int) * (max - min))))
	{
		while (max > min)
		{
			tab[j] = min;
			j++;
			min++;
		}
		return (tab);
	}
	return (NULL);
}
