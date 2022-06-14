/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:37:16 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/17 12:51:37 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha_numeric(char *str)
{
	if ((str[0] >= '0' && str[0] <= '9') ||
			(str[0] >= 'a' && str[0] <= 'z') ||
			(str[0] >= 'A' && str[0] <= 'Z'))
		return (1);
	else
		return (0);
}

int		ft_str_is_uppercase(char *str)
{
	if (str[0] < 'A' || str[0] > 'Z')
		return (0);
	return (1);
}

char	*ft_strupcase(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	return (&str[0]);
}

char	*ft_strlowcase(char *str)
{
	if (str[0] >= 'A' && str[0] <= 'Z')
		str[0] = str[0] + 32;
	return (&str[0]);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strupcase(&str[0]);
	while (str[i] != '\0')
	{
		if (ft_str_is_alpha_numeric(&str[i]) == 1)
		{
			if (ft_str_is_alpha_numeric(&str[i - 1]) == 1)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] = str[i] + 32;
			}
			else
				ft_strupcase(&str[i]);
		}
		i++;
	}
	return (str);
}
