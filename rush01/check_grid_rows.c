/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid_rows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:12:48 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:39:46 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define N 4

int	check_row_view(int *mat, int i, int max)
{
	int	view_r;
	int	view_l;

	view_r = 0;
	while (++i <= N)
	{
		if (mat[i] > max)
		{
			max = mat[i];
			view_r++;
		}
	}
	view_l = 0;
	max = -1;
	while (--i >= 1)
	{
		if (mat[i] > max)
		{
			max = mat[i];
			view_l++;
		}
	}
	if ((view_r == mat[0] || mat[0] == 0) && (view_l == mat[5] || mat[5] == 0))
		return (1);
	return (0);
}

int	check_duplicates_row(int *arr)
{
	int	i;
	int	j;

	i = 1;
	while (i < N)
	{
		j = i + 1;
		while (j <= N)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rows(int **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i <= N)
	{
		if (!check_duplicates_row(&arr[i][0]))
			return (0);
		j = 1;
		if (!check_row_view(&arr[i][0], 0, -1))
			return (0);
		i++;
	}
	return (1);
}
