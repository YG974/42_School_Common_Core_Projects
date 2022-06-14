/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:34:41 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/20 12:52:57 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tnrvfrr(char *str)
{
	int i;

	i = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
				str[i] != '\r' && str[i] != '\f' && str[i] != '\v')
			return (-1);
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int pos_nb;
	int sign;
	int messie;

	pos_nb = ft_tnrvfrr(str);
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
	while (str[pos_nb] >= '0' && str[pos_nb] <= '9')
	{
		messie = (messie * 10) + (str[pos_nb] - '0');
		pos_nb++;
	}
	return (messie * sign);
}
