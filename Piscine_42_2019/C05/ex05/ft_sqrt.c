/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:53:33 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/20 18:22:04 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sqrt;

	if (nb < 1)
		return (0);
	sqrt = (nb + 1) / 2;
	while (sqrt > (sqrt + (nb / sqrt)) / 2)
		sqrt = (sqrt + nb / sqrt) / 2;
	if (sqrt * sqrt == nb)
		return (sqrt);
	else
		return (0);
}
