/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:17:34 by egualand          #+#    #+#             */
/*   Updated: 2023/07/23 15:58:29 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_couples(int a, int b)
{
	char	first;
	char	second;
	char	third;
	char	fourth;

	first = a / 10 + '0';
	second = a % 10 + '0';
	third = b / 10 + '0';
	fourth = b % 10 + '0';
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, " ", 1);
	write(1, &third, 1);
	write(1, &fourth, 1);
	if (!(a == 98 && b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	b = a + 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			write_couples(a, b++);
		}
		b = ++a + 1;
	}
}

/*int main(void)
{
	ft_print_comb2();
}*/
