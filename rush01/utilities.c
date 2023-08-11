/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:25:16 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:34:16 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_mat(int **arr, int dim)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= dim)
	{
		j = 0;
		while (++j <= dim)
		{
			ft_putchar(arr[i][j] + '0');
			if (j != dim)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
