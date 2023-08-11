/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:35:21 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:44:07 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*check_space(char *mat)
{
	int		i;
	int		j;
	char	*par;

	par = (char *)malloc(sizeof(char) * 17);
	i = 0;
	j = 0;
	while (mat[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (mat[i] == ' ')
				par[j] = '0';
			else if (mat[i] >= '0' && mat[i] <= '4')
				par[j] = mat[i];
			else
				return (NULL);
			j++;
		}
		i++;
	}
	par[j] = '\0';
	return (par);
}

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
