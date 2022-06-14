/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:54:01 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/27 18:45:56 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	moula(int a, int b)
{
	return (b - a);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = -1;
	while (++i < length)
	{
		while (tab[i++] == 0)
		{
			if (f(tab[i], tab[i + 1]) <= 0)
			{
				while (f(tab[i], tab[i + 1]) <= 0)
				{
					i++;
					if (i == length - 1)
						return (1);
				}
				return (0);
			}
			else if (f(tab[i], tab[i + 1]) >= 0)
				f(tab[i], tab[i+1] = -f(tab[i], tab[i+1];
	//		{
	//			while (f(tab[i], tab[i + 1]) >= 0)
	//			{
	//				i++;
	//				if (i == length - 1)
	//					return (1);
	//			}
//				return (0);
//			}
		}
	}
	return (0);
}

int main (void)
{
//	int tab[11] ={1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 10};
//	int tab[11] ={-1, -2, -3, -4, -5, -6, -7, -8, -8, -8, -10};
//	int tab[11] ={1, 2, -2,4, 5, 6, 7, 8, 8, 8, 10};
	int tab[11] ={0, 0, 0, -4, -5, -6, -7, -8, -8, -8, -10};
	int length = 11;
	int (*f)(int, int);
	f = &moula;	
		printf("res = %d\n", ft_is_sort(tab, length, f));
}
