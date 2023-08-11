/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:51:48 by egualand          #+#    #+#             */
/*   Updated: 2023/08/10 17:32:21 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	arr[100];
	long	num;

	i = 0;
	num = (long)nb;
	if (num == 0)
		ft_putchar('0');
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	while (num > 0)
	{
		arr[i++] = num % 10 + '0';
		num /= 10;
	}
	while (--i >= 0)
	{
		ft_putchar(arr[i]);
	}
}

/*int main(void)
{
	ft_putnbr(01234567);
}*/
