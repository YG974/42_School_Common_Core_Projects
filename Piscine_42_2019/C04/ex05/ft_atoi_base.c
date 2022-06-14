/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:05:42 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/23 17:38:04 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_tnrvfrr(char *str, char *base)
{
	int i;

	i = 0;
	while ((base_index(str[i], base) < 0) &&
			str[i] != '+' && str[i] != '-')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
				str[i] != '\r' && str[i] != '\f' && str[i] != '\v')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_strlen_strstr(char *str)
{
	int pos;
	int pos_find;

	pos = 0;
	if (str[pos] == '\0')
		return (0);
	while (str[pos] != '\0')
	{
		if (str[pos] == '-' || str[pos] == '+' || str[pos] == ' ')
			return (0);
		pos_find = pos + 1;
		while (str[pos_find] != '\0')
		{
			if (str[pos] == str[pos_find])
				return (0);
			pos_find++;
		}
		pos++;
	}
	if (pos < 2)
		return (0);
	return (pos);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	len_base;
	int				pos_nb;
	int				sign;
	int				messie;

	len_base = ft_strlen_strstr(base);
	if (len_base < 2)
		return (0);
	pos_nb = ft_tnrvfrr(str, base);
	messie = 0;
	sign = 1;
	if (pos_nb == -1)
		return (0);
	while (str[pos_nb] == '+' || str[pos_nb] == '-')
	{
		if (str[pos_nb] == '-')
			sign = -sign;
		pos_nb++;
	}
	while (base_index(str[pos_nb], base) >= 0)
	{
		messie = (messie * len_base) + base_index(str[pos_nb], base);
		pos_nb++;
	}
	return (messie * sign);
}
