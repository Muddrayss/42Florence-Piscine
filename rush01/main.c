/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:34:01 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:33:43 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define N 4

char	*check_space(char *mat);
int		ft_strlen(char *str);
int		**ft_create_tab(int max_value, char *params);
int		solve(int pos, int **arr);
void	print_mat(int **arr, int dim);

int	main(int argc, char **argv)
{
	int		**matrix;
	char	*param;

	param = check_space(argv[1]);
	if (ft_strlen(param) != 16 || param == NULL || argc != 2)
	{
		write(1, "Error!", 6);
		return (0);
	}
	matrix = ft_create_tab(N, param);
	if (!solve(0, matrix))
	{
		write(1, "No solutions!", 13);
		return (0);
	}
	print_mat(matrix, N);
	free(matrix);
}
