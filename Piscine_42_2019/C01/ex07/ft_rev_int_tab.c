/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:50:36 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/10 19:16:23 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_rev_int_tab(int *tab, int size)
{
	int i;
	int buffer;

	i = 0;
	while (i < size)
	{
		buffer = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = buffer;
		size--;
		i++;
	}
}
