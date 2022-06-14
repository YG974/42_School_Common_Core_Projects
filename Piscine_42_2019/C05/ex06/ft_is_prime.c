/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:54:01 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/21 00:27:09 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sqrt;

	if (nb < 1)
		return (0);
	sqrt = (nb + 1) / 2;
	while (sqrt > (sqrt + nb / sqrt) / 2)
		sqrt = (sqrt + nb / sqrt) / 2;
	return (sqrt);
}

int	ft_is_prime(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}
