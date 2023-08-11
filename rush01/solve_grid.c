/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:19:39 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:19:45 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define N 4

int	is_valid(int **arr);

int	solve(int pos, int **arr)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	j = 0;
	y = (pos / N) + 1;
	x = (pos % N) + 1;
	if (pos == 16 && is_valid(arr))
		return (1);
	while (++i <= N && j == 0 && pos < 16)
	{
		arr[x][y] = i;
		j = solve(pos + 1, arr);
	}
	if (j != 0)
		return (1);
	if (pos < 16)
		arr[x][y] = 0;
	return (0);
}
