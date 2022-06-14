/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:55:59 by ygeslin           #+#    #+#             */
/*   Updated: 2019/06/08 14:35:35 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
		write(1, &c, 1);
}

void	rush(int x, int y)
{
	int i;

	i = x;
	ft_put_char('A');
	i--;
	while(i > 1)
	{
		ft_put_char('B');
		i--;
	}
		if(i == 1)
		{
			ft_put_char('C');
			ft_put_char('\n');
            i = x;
			ft_put_char('B');
			i--;
		}
				while(i > 1)	
				{
					ft_put_char(" ");		
				}
                    if(i == 1)
                    {
						ft_put_char("B");
						ft_put_char('\n');
                        ft_put_char("B");
                        i =
				
				i--;
			while(y > 1)
		{
			write(1, &" ", 1);
			i--;
				if(i == 1)
					write(1, &"B", 1);	
					write(1, &"\n", 1);
					i--;
				
		}	
}		


int		main()
{
		int x;
		int y;

		x = 6;
		y = 5;
	
		rush(x, y);
		return(0);
}
