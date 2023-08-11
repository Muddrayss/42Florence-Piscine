/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:03:14 by egualand          #+#    #+#             */
/*   Updated: 2023/08/02 15:17:44 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define N 10

void	print_queens(int mat[N][N])
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			if (mat[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
				break ;
			}
		}
	}
	write(1, "\n", 1);
}

int	check_diagonals(int mat[N][N], int r, int c)
{
	int	i;
	int	j;

	i = r;
	j = 0;
	while (--i >= 0)
	{
		if (c + (++j) < N && mat[i][c + j] == 1)
			return (0);
		if (c - j >= 0 && mat[i][c - j] == 1)
			return (0);
	}
	i = r;
	j = 0;
	while (++i < N)
	{
		if (c + (++j) < N && mat[i][c + j] == 1)
			return (0);
		if (c - j >= 0 && mat[i][c - j] == 1)
			return (0);
	}
	return (1);
}

int	is_safe(int mat[N][N], int r, int c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i < N)
	{
		if (++i != c && ++j != r)
		{
			if (mat[r][i] == 1 || mat[j][c] == 1)
				return (0);
		}
	}
	return (check_diagonals(mat, r, c));
}

int	find_combs(int mat[N][N], int queen, int c)
{
	int	i;

	i = 0;
	if (queen == N)
	{
		print_queens(mat);
		return (1);
	}
	while (c < N)
	{
		if (is_safe(mat, queen, c))
		{
			mat[queen][c] = 1;
			i += find_combs(mat, queen + 1, 0);
			mat[queen][c] = 0;
		}
		c++;
	}
	return (i);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	int	mat[N][N];

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			mat[i][j] = 0;
	}
	return (find_combs(mat, 0, 0));
}

/*int main(void)
{
	ft_ten_queens_puzzle();
}*/
