/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:15:10 by egualand          #+#    #+#             */
/*   Updated: 2023/07/30 17:20:18 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define N 4

int	check_rows(int **arr);
int	check_columns(int **arr);

int	is_valid(int **arr)
{
	if (check_rows(arr) && check_columns(arr))
		return (1);
	else
		return (0);
}
