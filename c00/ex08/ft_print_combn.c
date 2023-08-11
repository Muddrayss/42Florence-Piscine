/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:33:01 by egualand          #+#    #+#             */
/*   Updated: 2023/07/25 18:42:41 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int n, char *buf, int buf_idx, int last_num)
{
	int	i;

	i = last_num + 1;
	if (n == 0)
	{
		write(1, buf, buf_idx);
		write(1, ", ", 2);
		return ;
	}
	while (i <= 10 - n)
	{
		buf[buf_idx] = '0' + i;
		print_comb(n - 1, buf, buf_idx + 1, i);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];
	int		i;

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i <= 10 - n)
	{
		buf[0] = '0' + i;
		print_comb(n - 1, buf, 1, i);
		i++;
	}
	buf[0] = '0' + 10 - n;
	write(1, buf, n);
}

/*int main(void)
{
	ft_print_combn(2);
}*/
