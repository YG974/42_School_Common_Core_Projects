/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:52:00 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/20 15:03:26 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int factoriel;

	factoriel = 1;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb == 0)
		return (1);
	else
		factoriel = nb * ft_recursive_factorial(nb - 1);
	return (factoriel);
}
