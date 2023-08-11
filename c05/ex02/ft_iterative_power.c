/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:41:09 by egualand          #+#    #+#             */
/*   Updated: 2023/07/31 14:35:37 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	sum;

	i = 0;
	sum = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i++ < power)
		sum *= nb;
	return (sum);
}

/*int main(void)
{
	printf("%i\n", ft_iterative_power(2, 3));
}*/
