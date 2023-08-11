/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:37:08 by egualand          #+#    #+#             */
/*   Updated: 2023/07/25 12:21:15 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		i++;
	}
	return (str);
}

/*int main(void)
{
	char src[] = "My amazing string";

	ft_strupcase(src);
	for (int i = 0; i < strlen(src); i++)
	{
		printf("%c", src[i]);
	}
}*/
