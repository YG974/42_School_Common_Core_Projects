/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:52:48 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/20 15:58:14 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int nb_power;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb_power = nb * ft_recursive_power(nb, power - 1);
	return (nb_power);
}
