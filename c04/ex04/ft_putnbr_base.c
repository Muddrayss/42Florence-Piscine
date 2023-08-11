/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:51:48 by egualand          #+#    #+#             */
/*   Updated: 2023/08/01 14:19:30 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (-1);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		while (base[j] != '\0')
		{
			if (base[i] == base[j++])
				return (-1);
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	char	arr[100];
	long	num;
	int		base_len;

	i = 0;
	num = (long)nbr;
	base_len = validate_base(base);
	if (num == 0)
		ft_putchar(base[0]);
	if (base_len <= 0)
		return ;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	while (num > 0)
	{
		arr[i++] = base[num % base_len];
		num /= base_len;
	}
	while (--i >= 0)
		ft_putchar(arr[i]);
}

/*int main(void)
{
	ft_putnbr(42);
}*/
