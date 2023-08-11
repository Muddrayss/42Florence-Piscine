/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:24:02 by egualand          #+#    #+#             */
/*   Updated: 2023/07/26 12:22:49 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_array(char *nums)
{
	nums[0] = '0';
	nums[1] = '1';
	nums[2] = '2';
	nums[3] = ',';
	nums[4] = ' ';
}

void	ft_print_comb(void)
{
	char	n[5];

	initialize_array(n);
	while (n[0] <= '7')
	{
		while (n[1] <= '8')
		{
			while (n[2] <= '9')
			{
				if (n[0] == '7' && n[1] == '8' && n[2] == '9')
					write(1, n, 3);
				else
					write(1, n, 5);
				n[2]++;
			}
			n[2] = ++n[1] + 1;
		}
		n[1] = ++n[0] + 1;
		n[2] = n[1] + 1;
	}
}

/*int main(void)
{
	ft_print_comb();
}*/
