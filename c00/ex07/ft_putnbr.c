/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:07:23 by egualand          #+#    #+#             */
/*   Updated: 2023/07/27 11:06:49 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_l(int n, int molt)
{
	if (n / 10 == 0)
		return (molt);
	return (get_l(n / 10, molt * 10));
}

void	ft_putnbr(int nb)
{
	char	c;
	int		len;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	len = get_l(nb, 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (len > 0)
	{
		c = (nb / len) % 10 + '0';
		write(1, &c, 1);
		len /= 10;
	}
}

/*int main(void)
{
	ft_putnbr(0);
	ft_putnbr(-0);
}*/
