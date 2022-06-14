/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:58:16 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/22 23:47:01 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int j;

	j = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if ((tab = (int*)malloc(sizeof(int) * (max - min))))
	{
		while (max > min)
		{
			tab[j] = min;
			j++;
			min++;
		}
		*range = tab;
		return (j);
	}
	return (-1);
}
