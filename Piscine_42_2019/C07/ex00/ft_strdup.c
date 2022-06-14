/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:03:00 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/24 22:16:48 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		str_size(char *src)
{
	int i;

	i = 0;
	while (src[i++])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char*)malloc(sizeof(*src) * str_size(src));
	if (dest == NULL)
		return (dest);
	dest = ft_strcpy(dest, src);
	return (dest);
}
