/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgennai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:26:26 by rgennai           #+#    #+#             */
/*   Updated: 2023/07/23 17:54:57 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	write_row(int x, char first_char, char middle_chars, char last_char)
{
	ft_putchar(first_char);
	x--;
	while (x > 1)
	{
		ft_putchar(middle_chars);
		x--;
	}
	if (x != 0)
	{
		ft_putchar(last_char);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "Warning: Contact the Dev team to ", 33);
		write(1, "implement negative or NULL numbers feature!\n", 48);
		return ;
	}
	write_row(x, 'A', 'B', 'A');
	y--;
	while (y >= 2)
	{
		write_row(x, 'B', ' ', 'B');
		y--;
	}
	if (y == 1)
	{
		write_row(x, 'C', 'B', 'C');
	}
}
