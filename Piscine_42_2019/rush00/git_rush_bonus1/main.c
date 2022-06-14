/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:58:13 by fel-hams          #+#    #+#             */
/*   Updated: 2019/06/09 16:30:00 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);

int		main(void)
{
	int x;
	int y;

	x = 55554;
	y = 445687;
	if ((x < 1) || (y < 1))
	{
		write(1, &"please enter a srictly positive value for x and y", 49);
	}
	else
	{
		rush(x, y);
		return (0);
	}
}
