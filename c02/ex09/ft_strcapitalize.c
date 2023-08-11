/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:37:08 by egualand          #+#    #+#             */
/*   Updated: 2023/07/25 12:23:01 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		should_capitalize;
	char	c;

	i = 0;
	should_capitalize = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 'a' && c <= 'z' && should_capitalize == 1)
		{
			str[i] += 'A' - 'a';
			should_capitalize = 0;
		}
		else if (c >= '0' && c <= '9')
			should_capitalize = 0;
		else if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
			should_capitalize = 1;
		i++;
	}
	return (str);
}

/*int main(void)
{
	char src[] = "my amazing string";

	ft_strcapitalize(src);
	for (int i = 0; i < strlen(src); i++)
	{
		printf("%c", src[i]);
	}
}*/
