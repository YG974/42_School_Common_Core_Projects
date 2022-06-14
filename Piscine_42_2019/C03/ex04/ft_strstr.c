/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:57:29 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/18 17:10:33 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int pos;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		pos = 0;
		if (str[i] == to_find[pos])
			while (str[i + pos] == to_find[pos])
			{
				if (to_find[pos + 1] == '\0')
					return (&str[i]);
				pos++;
			}
		i++;
	}
	return (0);
}
