/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:49:02 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/24 21:46:45 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcat(char *dest, char *src, int pos_next_str)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[pos_next_str + i] = src[i];
		i++;
	}
	return (pos_next_str + i);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len_sum;
	int		pos_next_str;
	char	*tab;

	i = -1;
	len_sum = 0;
	pos_next_str = 0;
	if (!size)
		return (tab = malloc(0));
	while (++i < size)
		len_sum = len_sum + ft_strlen(strs[i]);
	len_sum = len_sum + ft_strlen(sep) * (size - 1);
	if (!(tab = malloc((sizeof(*strs)) * len_sum + 1)))
		return (tab = NULL);
	i = -1;
	while (++i < size)
	{
		pos_next_str = ft_strcat(tab, strs[i], pos_next_str);
		if (i != size - 1)
			pos_next_str = ft_strcat(tab, sep, pos_next_str);
	}
	tab[pos_next_str] = '\0';
	return (tab);
}
