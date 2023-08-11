/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid_cols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:14:52 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:42:49 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define N 4

int	check_col_view(int **m, int p, int i, int max)
{
	int	v_u;
	int	v_d;

	v_u = 0;
	while (++i <= N)
	{
		if (m[i][p] > max)
		{
			max = m[i][p];
			v_u++;
		}
	}
	v_d = 0;
	max = -1;
	while (--i >= 1)
	{
		if (m[i][p] > max)
		{
			max = m[i][p];
			v_d++;
		}
	}
	if ((v_u == m[0][p] || m[0][p] == 0) && (v_d == m[5][p] || m[5][p] == 0))
		return (1);
	return (0);
}

int	check_duplicates_col(int **arr, int col)
{
	int	i;
	int	j;

	i = 1;
	while (i < N)
	{
		j = i + 1;
		while (j <= N)
		{
			if (arr[i][col] == arr[j][col])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_columns(int **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i <= N)
	{
		if (!check_duplicates_col(arr, i))
			return (0);
		j = 1;
		if (!check_col_view(arr, i, 0, -1))
			return (0);
		i++;
	}
	return (1);
}
