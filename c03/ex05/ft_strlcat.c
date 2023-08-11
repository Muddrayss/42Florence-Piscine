/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:03:53 by egualand          #+#    #+#             */
/*   Updated: 2023/08/02 08:51:37 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res_d;
	unsigned int	res_s;

	i = ft_strlen(dest);
	res_d = ft_strlen(dest);
	res_s = ft_strlen(src);
	j = 0;
	if (size <= 0)
		return (res_s + size);
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < res_d)
		return (res_s + size);
	else
		return (res_d + res_s);
}

/*int main(void)
{
	char dest[] = "Hello!!";
	char src[] = "World!";

	printf("dest: %s\n", dest);
	printf("src: %s\n", src);
	printf("sizeof(dest): %lu\n", sizeof(dest));
	printf("sizeof(src): %lu\n", sizeof(src));
	printf("len: %i\n", ft_strlcat(dest, src, sizeof(dest)));
	printf("dest: %s\n", dest);
	printf("src: %s\n", src);
}*/
