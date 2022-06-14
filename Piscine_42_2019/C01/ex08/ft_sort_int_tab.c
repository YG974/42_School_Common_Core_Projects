/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:17:23 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/11 13:29:45 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int min;
	int pos_buffer_min;
	int buffer_size;

	i = 0;
	while (i < size)
	{
		min = tab[i];
		pos_buffer_min = i;
		buffer_size = size - 1;
		while (buffer_size > i)
		{
			if (min > tab[buffer_size])
			{
				min = tab[buffer_size];
				pos_buffer_min = buffer_size;
			}
			buffer_size--;
		}
		tab[pos_buffer_min] = tab[i];
		tab[i] = min;
		i++;
	}
}
