/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:29:52 by egualand          #+#    #+#             */
/*   Updated: 2023/07/23 16:49:42 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	p1;
	int	p2;
	int	tmp;

	p1 = 0;
	p2 = size - 1;
	while (p1 < p2)
	{
		tmp = tab[p1];
		tab[p1++] = tab[p2];
		tab[p2--] = tmp;
	}
}
