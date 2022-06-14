/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:16:22 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/18 14:18:38 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int src_len;
	unsigned int total_size;

	dest_len = ft_strlen(dest);
	total_size = ft_strlen(src);
	src_len = 0;
	if (size <= dest_len)
		total_size = total_size + size;
	else
		total_size = total_size + dest_len;
	while (src[src_len] != '\0' && dest_len + 1 < size)
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	dest[dest_len] = '\0';
	return (total_size);
}
