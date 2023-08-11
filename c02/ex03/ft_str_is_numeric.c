/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:33:41 by egualand          #+#    #+#             */
/*   Updated: 2023/07/25 12:13:19 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i++];
		if (c >= '0' && c <= '9')
			continue ;
		else
			return (0);
	}
	return (1);
}

/*int main(void)
{
	char src[] = "54673456";

	printf("%i", ft_str_is_numeric(src);
}*/
