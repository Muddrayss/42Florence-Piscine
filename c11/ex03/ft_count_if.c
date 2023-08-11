/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:15:08 by egualand          #+#    #+#             */
/*   Updated: 2023/08/10 17:09:38 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;
	int	return_value;

	i = 0;
	count = 0;
	while (i < length)
	{
		return_value = f(tab[i]);
		if (return_value != 0)
			count += return_value;
		i++;
	}
	return (count);
}
