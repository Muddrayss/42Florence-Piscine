/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:12:14 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 15:33:54 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_fill_tab(int **arr, int max_value, char *params)
{
	int		i;

	i = 0;
	while (++i <= max_value)
		arr[0][i] = params[i - 1] - '0';
	i = 0;
	while (++i <= max_value)
		arr[max_value + 1][i] = params[i + 3] - '0';
	i = 0;
	while (++i <= max_value)
		arr[i][0] = params[i + 7] - '0';
	i = 1;
	while (i <= max_value)
	{
		arr[i][max_value + 1] = params[i + 11] - '0';
		i++;
	}
}

int	**ft_create_tab(int max_value, char *params)
{
	int		i;
	int		j;
	int		**arr;

	arr = (int **)malloc(sizeof(int *) * max_value + 2);
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < max_value + 2)
	{
		arr[i] = (int *)malloc(sizeof(int) * max_value + 2);
		if (arr[i] == NULL)
			return (0);
		i++;
	}
	i = -1;
	while (++i < max_value + 2)
	{
		j = -1;
		while (++j < max_value + 2)
			arr[i][j] = 0;
	}
	ft_fill_tab(arr, max_value, params);
	return (arr);
}
