/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:34:12 by egualand          #+#    #+#             */
/*   Updated: 2023/08/10 10:34:17 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "ft_convert_base2.c"

int	ft_atoi_base(char *str, char *base);
int	valid_b(char *base);

/*char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (i < nb && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_convert(int num, char *base_to, char *result)
{
	int	base_l;

	base_l = ft_strlen(base_to);
	if (num < 0)
	{
		ft_strcat(result, "-");
		num = -num;
	}
	if (num > base_l - 1)
	{
		ft_convert(num / base_l, base_to, result);
		ft_convert(num % base_l, base_to, result);
	}
	else
		ft_strncat(result, &base_to[num], 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		bt_l;
	int		i;
	char	*result;

	if (valid_b(base_from) == 0 || valid_b(base_to) == 0)
		return (NULL);
	i = 0;
	bt_l = ft_strlen(base_to);
	num = ft_atoi_base(nbr, base_from);
	result = (char *)malloc(sizeof(char) * 100);
	while (i < 100)
	{
		result[i] = '\0';
		i++;
	}
	if (result == NULL)
		return (NULL);
	ft_convert(num, base_to, result);
	return (result);
}

/*int main()
{
	char nbr[] = "--\t\n\r\v1234idjjbsj";
	char base1[] = "0123456789";
	char base2[] = "0123456";
	char result[100];

	ft_strcpy(result, ft_convert_base(nbr, base1, base2));

	printf("%s\n", result);
}*/
